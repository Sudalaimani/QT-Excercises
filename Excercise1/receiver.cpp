#include "receiver.h"
#include <QtDebug>

cReceiver::cReceiver(QObject *parent) :
    QObject(parent)
{
}

void cReceiver::sltReceiver(uint iCounter)
{
    qDebug() << "Direct Connection Counter:" << iCounter/3;
}

void cReceiver::sltQReceiver(uint iCounter)
{
    qDebug() << "Queued Connection Counter:" << iCounter/3<<"\n";
}
