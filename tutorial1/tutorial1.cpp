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
	void Notify(TNotifyUI& msg)
	{
	}
};
INT WinMain(HINSTANCE hInst,HINSTANCE hPreInst,LPSTR lpCmdLine,INT Show)
{
	CMyWnd* pFrame = new CMyWnd();
	//����������
	pFrame->Create(NULL,L"Hello World!",UI_WNDSTYLE_FRAME,WS_EX_WINDOWEDGE);
	//��ʾ����
	pFrame->ShowWindow(true);
	//��Ϣѭ��
	CPaintManagerUI::MessageLoop();

	return 0;
}