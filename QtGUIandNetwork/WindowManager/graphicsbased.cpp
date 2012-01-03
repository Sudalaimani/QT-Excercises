#include "graphicsbased.h"

#include <QGraphicsView>
#include <QGraphicsWebView>
#include <QList>

cGraphicsBased::cGraphicsBased()
{
    m_iWndOrder = 0;
    m_pGraphicsView = new QGraphicsView;
    m_pGraphicsView->setGeometry(QRect(0,100,1240,820));
    m_pGraphicsView->setScene(new QGraphicsScene);
}

cGraphicsBased::~cGraphicsBased()
{
    if(m_pGraphicsView)
        delete m_pGraphicsView;
}

void cGraphicsBased::setParent(QObject* pParent)
{
    m_pGraphicsView->setParent((QWidget*)pParent);
}

bool cGraphicsBased::isLaunched(QString strCurrent)
{
    bool bReturn = false;

    if(m_rgMapWebPage.contains(strCurrent))
    {
        bReturn = true;
        QGraphicsWebView *pCurPage = m_rgWndOrder[m_iWndOrder-1];
        QGraphicsWebView *pPage = m_rgMapWebPage[strCurrent];
        SwapZValue(pPage,pCurPage);
    }
    return bReturn;
}

void cGraphicsBased::SwapZValue(QGraphicsWebView* pFirst, QGraphicsWebView* pSecond)
{
    if(pFirst && pSecond && pFirst != pSecond)
    {
        int iZorder = pFirst->zValue();
        pFirst->setZValue(pSecond->zValue());
        pSecond->setZValue(iZorder);

        m_rgWndOrder[pFirst->zValue()] = pFirst;
        m_rgWndOrder[pSecond->zValue()] = pSecond;
    }
}

bool cGraphicsBased::Launch(QString strUrl)
{
    bool bReturn = true;
    if(!isLaunched(strUrl))
    {
        QGraphicsWebView *pNewPage = new QGraphicsWebView();

        bReturn = false;
        pNewPage->setUrl(QUrl(strUrl));
        pNewPage->resize(QSize(m_pGraphicsView->width(),m_pGraphicsView->height()));

        m_rgMapWebPage[strUrl] = pNewPage;
        m_pGraphicsView->scene()->addItem(pNewPage);
        m_rgWndOrder.push_back(pNewPage);

        pNewPage->setZValue(m_iWndOrder++);
    }
    m_pGraphicsView->show();
    return bReturn;
}

void cGraphicsBased::Close()
{
    QGraphicsWebView *pCurPage = m_rgWndOrder[m_iWndOrder-1];

    if(pCurPage)
    {
        QList<QGraphicsItem*> rgList = m_pGraphicsView->scene()->items();

        m_rgMapWebPage.remove(m_rgMapWebPage.key(pCurPage));
        rgList.removeOne(pCurPage);
        m_rgWndOrder.removeOne(pCurPage);

        m_iWndOrder--;
        delete pCurPage;
    }
}

void cGraphicsBased::Apply(QString strUrl, int iOption)
{
    QGraphicsWebView *pPage = m_rgMapWebPage[strUrl];

    switch(iOption)
    {
    case 0://Foreground
        {
            pPage->setEnabled(true);
            SwapZValue(pPage,m_rgWndOrder[m_iWndOrder-1]);
        }
        break;
    case 1://Foreground Disable
        {
            pPage->setEnabled(false);
            SwapZValue(pPage,m_rgWndOrder[m_iWndOrder-1]);
        }
        break;
    case 2://Background
        {
            pPage->setEnabled(true);
            SwapZValue(pPage,m_rgWndOrder[(m_iWndOrder > 1)?m_iWndOrder-2:0]);
        }
        break;
    case 3://Background Disable
        {
            pPage->setEnabled(false);
            SwapZValue(pPage,m_rgWndOrder[(m_iWndOrder > 1)?m_iWndOrder-1:0]);
        }
        break;
    }
}
