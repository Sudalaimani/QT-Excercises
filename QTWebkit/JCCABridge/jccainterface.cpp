#include "jccainterface.h"
#include <QDebug>
#include <QTimerEvent>

cJccaInterface::cJccaInterface(QObject *parent) :
    QObject(parent)
{
    setObjectName("Jcca"+QString::number(rand()));
}

void cJccaInterface::getName(QVariantMap rgData)
{
    m_rgData = rgData;
    startTimer(1000);
}

void cJccaInterface::timerEvent(QTimerEvent *event)
{
    qDebug() << "Timer ID:" << event->timerId();

    emit Success(m_rgData["Name"]);

    killTimer(event->timerId());
}
