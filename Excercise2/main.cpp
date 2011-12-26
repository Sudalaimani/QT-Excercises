#include <QtCore/QCoreApplication>
#include <sender.h>
#include <receiver.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    cSender s;
    cReceiver r;

//    qDebug("Main thread id: %u", (uint) QThread::currentThreadId());

    QObject::connect(&s,SIGNAL(sigSender(uint)),&r,SLOT(sltReceiver(uint)),Qt::QueuedConnection);

    
    return a.exec();
}
