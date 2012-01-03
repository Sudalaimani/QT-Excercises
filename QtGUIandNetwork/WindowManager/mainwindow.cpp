#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "wndmanager.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_pManager = new cWndManager(this);
    SetDefaultValues();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SetDefaultValues()
{
    QStringList rgstrlstUrl;
    QStringList rgstrlstWndState;

    rgstrlstUrl.push_back("http://www.google.co.in/");
    rgstrlstUrl.push_back("http://www.cnet.com/");
    rgstrlstUrl.push_back("http://www.wikipedia.org/");
    rgstrlstUrl.push_back("http://www.amazon.com/");
    rgstrlstUrl.push_back("http://www.msn.com/");
    rgstrlstUrl.push_back("http://www.ford.com/");


    rgstrlstWndState.push_back("Foreground");
    rgstrlstWndState.push_back("Foreground Disable");
    rgstrlstWndState.push_back("Background");
    rgstrlstWndState.push_back("Background Disable");

    ui->comboBox->addItems(rgstrlstUrl);
    ui->comboBox_3->addItems(rgstrlstWndState);
}

void MainWindow::on_LaunchButton_clicked()
{
    QString strUrl = ui->comboBox->currentText();
    if(!m_pManager->Launch(strUrl))
    {
        ui->comboBox_2->addItem(strUrl);
    }
}

void MainWindow::on_ApplyButton_clicked()
{
    m_pManager->Apply(ui->comboBox_2->currentText(),ui->comboBox_3->currentIndex() );
}

void MainWindow::on_pushButton_clicked()
{
    m_pManager->Close();
}

void MainWindow::on_checkBox_toggled(bool checked)
{
    ui->comboBox_2->clear();
    m_pManager->Toggle();
}
