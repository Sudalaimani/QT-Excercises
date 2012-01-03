#ifndef CBASEWND_H
#define CBASEWND_H

#include <QString>
class QObject;

class CBaseWnd
{
public:
    CBaseWnd();
    virtual ~CBaseWnd();
    virtual bool Launch(QString) = 0;
    virtual void Apply(QString,int) = 0;
    virtual void Close() = 0;
    virtual void setParent(QObject*) = 0;
};

#endif // CBASEWND_H
