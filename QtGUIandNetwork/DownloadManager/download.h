#ifndef NETREPLY_H
#define NETREPLY_H
#include <QObject>
#include <QFile>

#include <QNetworkReply>

class cDownload:public QObject
{
    Q_OBJECT
    QNetworkReply* m_pNetReply;
    int m_iIndex;
    bool m_bPause;
    QFile m_OutputFile;
public:
    cDownload(QNetworkReply*, int);
    ~cDownload();

signals:
    void Dlupdate(qint64,qint64,int);
    void DlCancel(int);
    void DlCompleted(int);
    void DlPause(int);
    void DlResume(int);

public slots:
    void Dlprogress(qint64,qint64);
    void Finished();
    void Cancel();
    void Pause();
};

#endif // NETREPLY_H
