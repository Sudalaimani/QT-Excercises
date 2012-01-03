#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "download.h"

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QWebView>
#include <QFileInfo>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    SetDefaultValues();
}

MainWindow::~MainWindow()
{
    cDownload *pDownload = 0;
    QNetworkAccessManager *pNAM  = 0;

    delete ui;

    foreach(pDownload,m_rgDownload)
        delete pDownload;

    foreach(pNAM,m_rgNAM)
        delete pNAM;
}

void MainWindow::SetDefaultValues()
{
    QProgressBar *pProgressbar = 0;


    m_rgButtonCancel.push_back(ui->pushButton_2);
    m_rgButtonCancel.push_back(ui->pushButton_4);
    m_rgButtonCancel.push_back(ui->pushButton_6);
    m_rgButtonCancel.push_back(ui->pushButton_8);
    m_rgButtonCancel.push_back(ui->pushButton_10);
    m_rgButtonCancel.push_back(ui->pushButton_12);
    m_rgButtonCancel.push_back(ui->pushButton_14);

    m_rgButtonPause.push_back(ui->pushButton_3);
    m_rgButtonPause.push_back(ui->pushButton_5);
    m_rgButtonPause.push_back(ui->pushButton_7);
    m_rgButtonPause.push_back(ui->pushButton_9);
    m_rgButtonPause.push_back(ui->pushButton_11);
    m_rgButtonPause.push_back(ui->pushButton_13);
    m_rgButtonPause.push_back(ui->pushButton_15);

    m_rgProgressbar.push_back(ui->progressBar);
    m_rgProgressbar.push_back(ui->progressBar_2);
    m_rgProgressbar.push_back(ui->progressBar_3);
    m_rgProgressbar.push_back(ui->progressBar_4);
    m_rgProgressbar.push_back(ui->progressBar_5);
    m_rgProgressbar.push_back(ui->progressBar_6);
    m_rgProgressbar.push_back(ui->progressBar_7);

    m_rgLabel.push_back(ui->label);
    m_rgLabel.push_back(ui->label_2);
    m_rgLabel.push_back(ui->label_3);
    m_rgLabel.push_back(ui->label_4);
    m_rgLabel.push_back(ui->label_5);
    m_rgLabel.push_back(ui->label_6);
    m_rgLabel.push_back(ui->label_7);


    foreach(pProgressbar,m_rgProgressbar)
    {
        pProgressbar->setValue(0);
        pProgressbar->parentWidget()->setVisible(false);
    }
}

void MainWindow::on_pushButton_clicked()
{
    int iCount = m_rgDownload.count();

    QNetworkRequest request(QUrl(ui->lineEdit->text()));
    QNetworkAccessManager *pNAM = new QNetworkAccessManager;
    QNetworkReply *pReply = pNAM->get(request);
    cDownload *pDownload = new cDownload(pReply,iCount);
    QString strFileName = QFileInfo(request.url().path()).fileName();

    m_rgNAM.push_back(pNAM);
    m_rgDownload.push_back(pDownload);

    if(strFileName.isEmpty())
        strFileName = request.url().toString();
    m_rgLabel[iCount]->setText(strFileName);
    m_rgButtonCancel[iCount]->parentWidget()->setVisible(true);

    QObject::connect(m_rgButtonCancel[iCount],SIGNAL(clicked()),pDownload,SLOT(Cancel()));
    QObject::connect(m_rgButtonPause[iCount],SIGNAL(clicked()),pDownload,SLOT(Pause()));

    QObject::connect(pDownload,SIGNAL(Dlupdate(qint64,qint64,int)),this,SLOT(UpdateProgress(qint64,qint64,int)));
    QObject::connect(pDownload,SIGNAL(DlCancel(int)),this,SLOT(Cancel(int)));
    QObject::connect(pDownload,SIGNAL(DlPause(int)),this,SLOT(Pause(int)));
    QObject::connect(pDownload,SIGNAL(DlResume(int)),this,SLOT(Resume(int)));
    QObject::connect(pDownload,SIGNAL(DlCompleted(int)),this,SLOT(Completed(int)));

    if(iCount > 5)
    {
        ui->pushButton->setEnabled(false);
    }
}

void MainWindow::UpdateProgress(qint64 lReceived,qint64 lTotal,int iIndex)
{
    if(lTotal != -1)
        m_rgProgressbar[iIndex]->setMaximum(lTotal);
    m_rgProgressbar[iIndex]->setValue(lReceived);
}

void MainWindow::Cancel(int iIndex)
{
    m_rgButtonCancel[iIndex]->setText("Cancelled");
    m_rgButtonCancel[iIndex]->setDisabled(true);
    m_rgButtonPause[iIndex]->setDisabled(true);
}

void MainWindow::Completed(int iIndex)
{
    m_rgButtonCancel[iIndex]->setText("Completed");
    m_rgButtonCancel[iIndex]->setDisabled(true);
    m_rgButtonPause[iIndex]->setDisabled(true);
}

void MainWindow::Pause(int iIndex)
{
    m_rgButtonPause[iIndex]->setText("Resume");
}

void MainWindow::Resume(int iIndex)
{
    m_rgButtonPause[iIndex]->setText("Pause");
}
