#include "download.h"
#include <QDebug>
#include <QFileInfo>

cDownload::cDownload(QNetworkReply* pnetReply, int iCount)
{
    QString strFileName = QFileInfo(pnetReply->url().path()).fileName();

    m_iIndex = iCount;
    m_pNetReply = pnetReply;
    m_bPause = true;

    QObject::connect(m_pNetReply,SIGNAL(finished()),this,SLOT(Finished()));
    QObject::connect(m_pNetReply,SIGNAL(downloadProgress(qint64,qint64)),this,SLOT(Dlprogress(qint64 ,qint64 )));

    if(strFileName.isEmpty())
        strFileName = m_pNetReply->url().toString();

    if (QFile::exists(strFileName))
    {
        int iIndex = 0;
        strFileName += '.';
        while (QFile::exists(strFileName + QString::number(iIndex)))
            iIndex++;

        strFileName += QString::number(iIndex);
    }
    m_OutputFile.setFileName(strFileName);

    if (!m_OutputFile.open(QIODevice::WriteOnly))
    {
         qDebug("Problem opening save file '%s' for download '%s': %s\n",
                 qPrintable(strFileName), pnetReply->url().toEncoded().constData(),
                 qPrintable(m_OutputFile.errorString()));
     }
}

cDownload::~cDownload()
{
}

void cDownload::Dlprogress(qint64 lReceived,qint64 lTotal)
{
    m_OutputFile.write(m_pNetReply->readAll());
    qDebug()<< "Size: "<< m_OutputFile.size()<< "lReceived: "<< lReceived << "Total:" << lTotal << "Download id:"<<m_iIndex;
    emit Dlupdate(m_OutputFile.size()+lReceived,m_OutputFile.size()+lTotal,m_iIndex);
}

void cDownload::Finished()
{
    m_OutputFile.close();
    emit DlCompleted(m_iIndex);
}

void cDownload::Cancel()
{
    QObject::disconnect(m_pNetReply,SIGNAL(finished()),this,SLOT(Finished()));
    QObject::disconnect(m_pNetReply,SIGNAL(downloadProgress(qint64,qint64)),this,SLOT(Dlprogress(qint64 ,qint64 )));
    m_pNetReply->abort();
    emit DlCancel(m_iIndex);
}

void cDownload::Pause()
{
    if(m_bPause)
    {
        m_OutputFile.write(m_pNetReply->readAll());
        qDebug()<< "Paused: size"<< m_OutputFile.size() <<"Download id:"<<m_iIndex;
        QObject::disconnect(m_pNetReply,SIGNAL(finished()),this,SLOT(Finished()));
        QObject::disconnect(m_pNetReply,SIGNAL(downloadProgress(qint64,qint64)),this,SLOT(Dlprogress(qint64 ,qint64 )));
        m_pNetReply->abort();
        emit DlPause(m_iIndex);
        m_bPause = false;
    }
    else
    {
        qDebug()<< "Resumed: size"<< m_OutputFile.size() <<"Download id:"<<m_iIndex;
        QByteArray rangeHeaderValue = "bytes=" + QString::number(m_OutputFile.size()).toAscii() + "-";
        qDebug()<<rangeHeaderValue;
        m_pNetReply->request().setRawHeader("Range",rangeHeaderValue);
        m_pNetReply = m_pNetReply->manager()->get(m_pNetReply->request());
        QObject::connect(m_pNetReply,SIGNAL(finished()),this,SLOT(Finished()));
        QObject::connect(m_pNetReply,SIGNAL(downloadProgress(qint64,qint64)),this,SLOT(Dlprogress(qint64 ,qint64 )));
        emit DlResume(m_iIndex);
        m_bPause = true;
    }
}
