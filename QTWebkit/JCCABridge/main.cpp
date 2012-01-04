#include <QtGui//QApplication>
#include <mywebpage.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    cMyWebpage myPage;
    QString strFilePath = QString("file://")+ QCoreApplication::applicationDirPath() + QString("/myJCCAPage.html");

    myPage.load(QUrl(strFilePath));

    myPage.show();
    
    return a.exec();
}
