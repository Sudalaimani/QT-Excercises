#include "sender.h"
#include <QtDebug>

cSender::cSender(QObject *parent) :
    QThread(parent)
{
    m_iCount = 0;
    moveToThread(this);
    this->start();
}

void cSender::run()
{
    startTimer(200);     // 200-millisecond timer
    this->exec();
}

void cSender::timerEvent(QTimerEvent *event)
 {
    m_iCount++;

    if((m_iCount % 3) == 0)
    {
        qDebug() << "Time stamp: " << m_iCount*200;
        emit sigSender(m_iCount);
//        qDebug("Thread id: %u", (uint) QThread::currentThreadId());
    }
 }
