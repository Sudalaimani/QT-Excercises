#include <QtGui/QApplication>
#include <bridge.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    cBridge w;
    QString strFilePath = QString("file://")+ QCoreApplication::applicationDirPath() + QString("/myPage.html");

    w.load(QUrl(strFilePath));

    w.show();
    
    return a.exec();
}
