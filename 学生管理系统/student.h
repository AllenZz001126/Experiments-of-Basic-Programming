#ifndef student_h
#define student_h
#include "head.h"

bool choose_lesson();//ѡ��
bool view_schedule(int);//�鿴���˿α�
bool quit_lesson();//�˿�
bool sign_for_ta();//��������
bool choose_ta();//ѡ������
void clear_assistant(char []);//����������Ϣ
void update_cur_cour();//���¿γ��ļ�
bool change_pass();//�޸�����
extern void signout();//�ǳ�
extern bool view_alllesson_info();//�鿴ȫ���γ���Ϣ
extern string star;
extern string starline;
extern string splitline;
#endif /* student_h */
