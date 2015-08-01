#include <Windows.h>
#include "../DuiLib/StdAfx.h" 
using namespace DuiLib;
class CMyWnd : public CWindowWnd,public INotifyUI
{
public:
	CMyWnd(){}
	LPCTSTR GetWindowClassName() const
	{
		return L"MyWnd";
	}
	UINT GetClassStyle() const{
		return UI_CLASSSTYLE_FRAME|CS_DBLCLKS;
	}
	void Notify(TNotifyUI& msg)
	{
		if(msg.sType == L"click")
		{
			if(msg.pSender->GetName() == L"CloseBtn")
			{
				if(IDOK == ::MessageBox(NULL,L"�˳�����",L"��ʾ��Ϣ",MB_OKCANCEL))
				{
					::PostQuitMessage(0);
				}
			}
		}
	}
	LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		switch(uMsg)
		{
		case WM_CREATE:
			{
				m_PaintMgr.Init(m_hWnd); 
				//������ť
				m_pCloseBtn = new CButtonUI();
				m_pCloseBtn->SetName(L"CloseBtn");
				m_pCloseBtn->SetBkColor(0xFFFF0000);
				m_pCloseBtn->SetText(L"�رհ�ť");
				m_pCloseBtn->SetVisible(true);
				m_PaintMgr.AttachDialog(m_pCloseBtn); 
				m_PaintMgr.AddNotifier(this);
			}
			break;
		case WM_PAINT:
			{
				RECT rect = {100,100,200,150};
				m_pCloseBtn->SetPos(rect);
			}
			break;
		case WM_DESTROY:
			::PostQuitMessage(0);
			break;
		} 
		LRESULT lRes=0;
		if(m_PaintMgr.MessageHandler(uMsg,wParam,lParam,lRes)) return lRes;
		return CWindowWnd::HandleMessage(uMsg,wParam,lParam);
	}

	~CMyWnd(){}
private:
	CPaintManagerUI m_PaintMgr; 
	CControlUI* m_pCloseBtn;
};
INT WinMain(HINSTANCE hInst,HINSTANCE hPreInst,LPSTR lpCmdLine,INT Show)
{
	CPaintManagerUI::SetInstance(hInst);
	//����������
	CMyWnd* pFrame = new CMyWnd();
	pFrame->Create(NULL,L"Hello World!",UI_WNDSTYLE_FRAME,WS_EX_WINDOWEDGE);
	pFrame->CenterWindow();
	//���ô��ڴ�С
	pFrame->ResizeClient(800,600);
	pFrame->ShowWindow(true);
	CPaintManagerUI::MessageLoop();
	 delete pFrame;
	return 0;
}