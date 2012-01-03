#ifndef WNDMANAGER_H
#define WNDMANAGER_H

#include <QMap>

class CBaseWnd;
class QObject;

class cWndManager
{
    bool m_bWidget;
    QObject *m_pParent;
    QMap<bool,CBaseWnd*> m_rgWnd;
public:
    cWndManager(QObject *pParen = 0);
    virtual ~cWndManager();

    bool Launch(QString);
    void Apply(QString, int);
    void Close();
    void UpdateWnd();
    void Toggle();
    CBaseWnd *GetWnd();
};

#endif // WNDMANAGER_H
