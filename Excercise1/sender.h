#ifndef SENDER_H
#define SENDER_H

#include <QObject>

class cSender : public QObject
{
    Q_OBJECT
public:
    explicit cSender(QObject *parent = 0);
protected:
    void timerEvent(QTimerEvent *event);

private:
    uint m_iCount;
    
public:
signals:
    void sigSender(uint);
public slots:
    
};

#endif // SENDER_H
