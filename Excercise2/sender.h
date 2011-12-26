#ifndef SENDER_H
#define SENDER_H

#include <QThread>

class cSender : public QThread
{
    Q_OBJECT
public:
    explicit cSender(QObject *parent = 0);

    void run();

protected:
    void timerEvent(QTimerEvent *event);

private:
    uint m_iCount;
    
signals:
    void sigSender(uint);
    
public slots:
    
};

#endif // SENDER_H
