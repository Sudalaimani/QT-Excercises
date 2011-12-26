#ifndef RECEIVER_H
#define RECEIVER_H

#include <QObject>

class cReceiver : public QObject
{
    Q_OBJECT
public:
    explicit cReceiver(QObject *parent = 0);

public slots:
    void sltReceiver(uint);
    void sltQReceiver(uint);
    
signals:
    
public slots:
    
};

#endif // RECEIVER_H
