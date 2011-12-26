#include <QtCore/QCoreApplication>
#include <sender.h>
#include <receiver.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    cSender s;
    cReceiver r;

    QObject::connect(&s,SIGNAL(sigSender(uint)),&r,SLOT(sltReceiver(uint)),Qt::DirectConnection);
    QObject::connect(&s,SIGNAL(sigSender(uint)),&r,SLOT(sltQReceiver(uint)),Qt::QueuedConnection);
    
    return a.exec();
}
