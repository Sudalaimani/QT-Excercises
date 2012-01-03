#ifndef GRAPHICSBASED_H
#define GRAPHICSBASED_H

#include <QMap>
#include "cbasewnd.h"

class QGraphicsView;
class QGraphicsWebView;

class cGraphicsBased:public CBaseWnd
{
    int m_iWndOrder;
    QGraphicsView* m_pGraphicsView;
    QList<QGraphicsWebView*> m_rgWndOrder;
    QMap<QString,QGraphicsWebView*> m_rgMapWebPage;
public:
    cGraphicsBased();
    virtual ~cGraphicsBased();

    bool Launch(QString);
    void Apply(QString, int);
    void Close();
    void SwapZValue(QGraphicsWebView*, QGraphicsWebView*);
    bool isLaunched(QString);
    void setParent(QObject*);
};

#endif // GRAPHICSBASED_H
