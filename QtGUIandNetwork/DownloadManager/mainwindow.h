#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>

class QNetworkAccessManager;
class cDownload;
class QPushButton;
class QProgressBar;
class QLabel;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QVector<QNetworkAccessManager*> m_rgNAM;
    QVector<cDownload*> m_rgDownload;

    QVector<QPushButton*> m_rgButtonCancel;
    QVector<QPushButton*> m_rgButtonPause;
    QVector<QProgressBar*> m_rgProgressbar;
    QVector<QLabel*> m_rgLabel;

public:
    explicit MainWindow(QWidget *parent = 0);
    void SetDefaultValues();
    ~MainWindow();
    
private slots:
    void on_pushButton_clicked();
    void UpdateProgress(qint64,qint64,int);
    void Cancel(int);
    void Completed(int);
    void Pause(int);
    void Resume(int);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
