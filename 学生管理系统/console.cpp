#include"head.h"
void setco(unsigned short forecolor = 7, unsigned short backgroundcolor = 0)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, forecolor + backgroundcolor * 0x10);
}
void notice()
{
	setco(0, 6);
		cout << "[ϵͳ��Ϣ]";
	setco(0, 15);
}
void success()
{
	setco(0,10);
	cout << "[�����ɹ�]";
	setco(0, 15);
}
void error()
{
	setco(15, 4);
	cout << "[����]";
	setco(0, 15);
}