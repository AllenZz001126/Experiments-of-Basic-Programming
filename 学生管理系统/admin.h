#ifndef admin_h
#define admin_h
#include "head.h"
void signout();//�ǳ�
bool get_lesson_info();//����γ�
bool view_alllesson_info();//�鿴ȫ���γ���Ϣ
bool add_lesson();//��ӿγ�
bool delete_lesson();//ɾ���γ�
bool change_lesson();//�޸Ŀγ���Ϣ
bool view_specific_info();//�鿴�γ̾�����Ϣ
bool check_duplicate2(char [], char[]);//�鿴�Ƿ��ظ�
bool initial_ta_info();//��ʼ�������ļ�
bool view_ta_stu();//�鿴�γ����̶�Ӧ��ѧ��
extern string star;
extern int bullet;
#endif /* admin_h */

