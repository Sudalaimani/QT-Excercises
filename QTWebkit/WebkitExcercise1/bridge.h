#ifndef BRIDGE_H
#define BRIDGE_H

#include <QWebView>

class cBridge : public QWebView
{
    Q_OBJECT
public:
    explicit cBridge(QWidget *parent = 0);
    
signals:
    
public slots:
    QString SayHello();
    
};

#endif // BRIDGE_H
