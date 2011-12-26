#ifndef RECEIVER_H
#define RECEIVER_H

#include <QObject>

class cReceiver : public QObject
{
    Q_OBJECT
public:
    explicit cReceiver(QObject *parent = 0);
    
signals:
    
public slots:
    void sltReceiver(uint);
    
};

#endif // RECEIVER_H
