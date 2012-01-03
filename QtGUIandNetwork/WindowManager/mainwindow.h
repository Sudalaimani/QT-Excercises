#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class cWndManager;

namespace Ui {
class MainWindow;
}



class MainWindow : public QMainWindow
{
    Q_OBJECT
    cWndManager* m_pManager;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void SetDefaultValues();

private slots:
    void on_LaunchButton_clicked();

    void on_ApplyButton_clicked();

    void on_pushButton_clicked();

    void on_checkBox_toggled(bool checked);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
