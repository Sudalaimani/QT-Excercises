#ifndef MYWEBPAGE_H
#define MYWEBPAGE_H

#include <QWebView>

class cMyWebpage : public QWebView
{
    Q_OBJECT
public:
    explicit cMyWebpage(QWidget *parent = 0);
    
signals:
    
public slots:
    QString getNameObject();
    
};

#endif // MYWEBPAGE_H
