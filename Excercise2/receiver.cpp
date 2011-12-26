#include "receiver.h"
#include <QDebug>

cReceiver::cReceiver(QObject *parent) :
    QObject(parent)
{
}

void cReceiver::sltReceiver(uint iCounter)
{
    qDebug() << "Counter:" << iCounter/3 <<endl;
}
