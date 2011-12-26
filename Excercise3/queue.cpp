#include "queue.h"

cQueue::cQueue()
{
}

void cListQueue::Add(DataType data)
{
    m_lstData.push_back(data);
}

void cListQueue::Remove()
{
    m_lstData.pop_front();
}

void cListQueue::Display()
{
    int uCount;

    cout<<"List Data:\n";

    for(uCount = 0;uCount<m_lstData.count();uCount++)
        cout<<m_lstData.at(uCount)<<endl;
}


void cVectQueue::Add(DataType data)
{
    m_VectData.push_back(data);
}

void cVectQueue::Remove()
{
    m_VectData.pop_front();
}

void cVectQueue::Display()
{
    int uCount;

    cout <<"Vector Data:\n";

    for(uCount = 0;uCount<m_VectData.count();uCount++)
        cout<<m_VectData.at(uCount)<<endl;
}
