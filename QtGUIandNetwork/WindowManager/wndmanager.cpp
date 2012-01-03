#include "graphicsbased.h"
#include "widgetbases.h"
#include "wndmanager.h"
#include "cbasewnd.h"

cWndManager::cWndManager(QObject* pParent)
{
    m_bWidget = false;
    m_pParent = pParent;
    m_rgWnd[false] = (CBaseWnd*) new cGraphicsBased;
    m_rgWnd[false]->setParent(m_pParent);
}

cWndManager::~cWndManager()
{
    if(m_rgWnd[false])
        delete m_rgWnd[false];
    if(m_rgWnd[true])
        delete m_rgWnd[true];
}

void cWndManager::UpdateWnd()
{
}

CBaseWnd *cWndManager::GetWnd()
{
    CBaseWnd* pWnd =  (CBaseWnd*)m_rgWnd[m_bWidget];
    return pWnd;
}


void cWndManager::Toggle()
{
    if(m_rgWnd.contains(m_bWidget))
    {
        if(m_rgWnd[false])
        {
            delete m_rgWnd[false];
            m_rgWnd[false] = 0;
        }
        if(m_rgWnd[true])
        {
            delete m_rgWnd[true];
            m_rgWnd[true] = 0;
        }
    }
    m_bWidget = (m_bWidget)?false:true;

    CBaseWnd* pWnd = (m_bWidget)? (CBaseWnd*) new cWidgetBases: (CBaseWnd*) new cGraphicsBased;
    pWnd->setParent(m_pParent);
    m_rgWnd[m_bWidget] = pWnd;

}

bool cWndManager::Launch(QString strUrl)
{
    return GetWnd()->Launch(strUrl);
}

void cWndManager::Close()
{
    GetWnd()->Close();
}

void cWndManager::Apply(QString strUrl, int iOption)
{
    GetWnd()->Apply(strUrl,iOption);
}

