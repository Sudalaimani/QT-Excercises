#include "sender.h"
#include <QtDebug>

cSender::cSender(QObject *parent) :
    QObject(parent)
{
    m_iCount = 0;
    startTimer(200);     // 200-millisecond timer
}

void cSender::timerEvent(QTimerEvent *event)
 {
    m_iCount++;
    qDebug() << "Time stamp: " << m_iCount*200;
    if((m_iCount % 3) == 0)
    {
        emit sigSender(m_iCount);
    }

 }
