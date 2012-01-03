#ifndef WIDGETBASES_H
#define WIDGETBASES_H

#include "cbasewnd.h"
#include <QMap>
class QWebView;

class cWidgetBases:public CBaseWnd
{
    QMap<QString,QWebView*> m_rgMapWebPage;
    QObject *m_pParent;
    QWebView* m_pForeGrnd;

public:
    cWidgetBases();
    virtual ~cWidgetBases();

    bool Launch(QString);
    void Apply(QString, int);
    void Close();
    bool isLaunched(QString);
    void setParent(QObject*);
};

#endif // WIDGETBASES_H
