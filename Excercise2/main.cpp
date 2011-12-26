#include <QtCore/QCoreApplication>
#include <sender.h>
#include <receiver.h>
#include <QThread>
#include <QMetaObject>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    cSender s;
    cReceiver r;
    QThread thread;

    s.moveToThread(&thread);

//    qDebug("Main thread id: %u", (uint) QThread::currentThreadId());

    QObject::connect(&s,SIGNAL(sigSender(uint)),&r,SLOT(sltReceiver(uint)),Qt::QueuedConnection);

    thread.start();
    QMetaObject::invokeMethod(&s, "run", Qt::QueuedConnection);


    return a.exec();
}
