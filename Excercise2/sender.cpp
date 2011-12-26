#include "sender.h"
#include <QtDebug>

cSender::cSender(QObject *parent) :
    QObject(parent)
{
    m_iCount = 0;
}

void cSender::run()
{
    startTimer(200);     // 200-millisecond timer
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
