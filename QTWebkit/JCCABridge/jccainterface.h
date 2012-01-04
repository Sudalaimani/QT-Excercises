#ifndef JCCAINTERFACE_H
#define JCCAINTERFACE_H

#include <QObject>
#include <QVariantMap>
#include <QVariant>

class cJccaInterface : public QObject
{
    Q_OBJECT

    QVariantMap m_rgData;

protected:
    void timerEvent(QTimerEvent *event);

public:
    explicit cJccaInterface(QObject *parent = 0);

    
signals:
    void Success(QVariant);
    void Failure();

public slots:
    void getName(QVariantMap rgData);
};

#endif // JCCAINTERFACE_H
