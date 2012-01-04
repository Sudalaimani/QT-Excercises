#include "mywebpage.h"
#include "jccainterface.h"
#include <QWebFrame>
#include <QDebug>

cMyWebpage::cMyWebpage(QWidget *parent) :
    QWebView(parent)
{
    QWebFrame *pframe = this->page()->mainFrame();
    pframe->addToJavaScriptWindowObject("GMInternal", this);
}

QString cMyWebpage::getNameObject()
{
    cJccaInterface *pObj = new  cJccaInterface(this);
    return pObj->objectName();
}
