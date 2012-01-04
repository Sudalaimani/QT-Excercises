#include "bridge.h"
#include <QtWebKit>

cBridge::cBridge(QWidget *parent) :
    QWebView(parent)
{
    QWebFrame *pframe = this->page()->mainFrame();
    pframe->addToJavaScriptWindowObject("GMInternal", this);
}

QString cBridge::SayHello()
{
    return QString("Hello");
}
