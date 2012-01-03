#include "widgetbases.h"
#include <QWebView>

cWidgetBases::cWidgetBases()
{

}

cWidgetBases::~cWidgetBases()
{
    if(!m_rgMapWebPage.isEmpty())
    {
        QWebView *pNewPage = 0;

        foreach(pNewPage, m_rgMapWebPage)
            delete pNewPage;
    }
}

bool cWidgetBases::isLaunched(QString strCurrent)
{
    bool bReturn = false;

    if(m_rgMapWebPage.contains(strCurrent))
    {
        bReturn = true;
        QWebView *pPage = m_rgMapWebPage[strCurrent];
        m_pForeGrnd = pPage;
        pPage->show();
    }
    return bReturn;
}


bool cWidgetBases::Launch(QString strUrl)
{
    bool bReturn = true;
    if(!isLaunched(strUrl))
    {
        QWebView *pNewPage = new QWebView();

        bReturn = false;
        pNewPage->setGeometry(0,100,1240,820);
        pNewPage->setParent((QWidget*)m_pParent);
        pNewPage->setUrl(QUrl(strUrl));
        m_rgMapWebPage[strUrl] = pNewPage;
        m_pForeGrnd = pNewPage;
        pNewPage->show();
    }
    return bReturn;
}


void cWidgetBases::Close()
{
    QWebView *pCurPage = m_pForeGrnd;

    if(pCurPage)
    {
        m_rgMapWebPage.remove(m_rgMapWebPage.key(pCurPage));
        m_pForeGrnd = 0;
        if(!m_rgMapWebPage.empty())
            m_pForeGrnd =  m_rgMapWebPage[m_rgMapWebPage.begin().key()];
        delete pCurPage;
    }
}

void cWidgetBases::Apply(QString strUrl, int iOption)
{
    QWebView *pPage = m_rgMapWebPage[strUrl];

    switch(iOption)
    {
    case 0://Foreground
        {
            pPage->setEnabled(true);
            m_pForeGrnd = pPage;
            pPage->raise();
        }
        break;
    case 1://Foreground Disable
        {
            pPage->setEnabled(false);
            m_pForeGrnd = pPage;
            pPage->raise();
        }
        break;
    case 2://Background
        {
            pPage->setEnabled(true);
            pPage->lower();
        }
        break;
    case 3://Background Disable
        {
            pPage->setEnabled(false);
            pPage->lower();
        }
        break;
    }
}

void cWidgetBases::setParent(QObject* pParent)
{
    m_pParent = pParent;
}
