#ifndef QUEUE_H
#define QUEUE_H
#include <QList>
#include <QVector>
#include <iostream>

using namespace std;

typedef int DataType;

class cQueue
{
public:
    cQueue();
    virtual void Add(DataType) = 0;
    virtual void Remove() = 0;
    virtual void Display() = 0;
};

class cListQueue: public cQueue
{
private:
    QList<DataType> m_lstData;
public:
    void Add(DataType);
    void Remove();
    void Display();
};

class cVectQueue: public cQueue
{
private:
    QVector<DataType> m_VectData;
public:
    void Add(DataType);
    void Remove();
    void Display();
};

#endif // QUEUE_H
