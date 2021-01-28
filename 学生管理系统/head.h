#ifndef head_h
#define head_h
#include<vector>
#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<conio.h>
#include<Windows.h>
using namespace std;
struct lesson
{
	char id[4];//�γ�id
	char name[31];//�γ���
	char tutor[31];//��ʦ��
	int max;//�������
	int current;//��������
	char type[31];//�γ�����
	vector<string> chosen_by;//ѡ��ѧ��
};
struct student
{
	char stu_id[31];//ѧ��id
	int signed_ta;//����������
	int major;//רҵ����Ŀ
	int minor;//��רҵ����Ŀ
};
extern std::vector <lesson> info;
extern std::vector <string> chosen_by;
extern student stu;
extern int login();
extern int adminfunc();
extern void stufunc();
extern void notice();
extern void error();
extern void success();
extern void setco(unsigned short forecolor , unsigned short backgroundcolor );
#endif /* head_h */

