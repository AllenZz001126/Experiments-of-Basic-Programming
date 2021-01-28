#define _CRT_SECURE_NO_WARNINGS
#include "admin.h"
string splitline(82, '=');
string starline(100, '*');
int adminfunc()
{
	char i[31] = { '\0' };
	while (1)
	{
		cout <<endl<< "�������ѡ����ѡ�����Ĳ���:\n" << "\033[34m"<<splitline<<endl;
		cout << "1.ע����¼\t2.¼��γ���Ϣ\t3.�鿴ȫ���γ���Ϣ\t4.���ӿγ�\n5.ɾ���γ�\t6.�޸Ŀγ�\t7.�鿴����γ�  \t8.�鿴�γ����̶�Ӧѧ������";
		cout<< endl << splitline <<"\033[30m"<< endl;
		cout << endl<<"���������Ĳ�����";
		cin >> i;
		cout << endl;
		if (!strcmp(i, "1"))
			signout();
		else if (!strcmp(i, "2"))
			get_lesson_info();
		else if (!strcmp(i, "3"))
			view_alllesson_info();
		else if (!strcmp(i, "4"))
			add_lesson();
		else if (!strcmp(i, "5"))
			delete_lesson();
		else if (!strcmp(i, "6"))
			change_lesson();
		else if (!strcmp(i, "7"))
			view_specific_info();
		else if (!strcmp(i, "8"))
			view_ta_stu();
		else 
		{ 
			error();
			cout << "ָ����Ч��" << endl; 
		}
		notice();
		cout << "�ַ����ϼ�ҳ�棡" << endl;
	}
	return 0;
}
void signout()
{
	success();
	cout<<star<< "�ɹ��˳���¼���ַ��ص�¼���棡"<<star<<endl<<endl;
	Sleep(2000);
	login();
}
bool get_lesson_info()
{
	FILE *fm = fopen("current_course.txt", "r");
	if(fm!=0)
	{ 
		fclose(fm);
		error();
		cout << "�γ̴�ǰ��¼�룬�޷��ظ�¼�룡"<<endl;
		return false;
	}
start: cout<<"��������Ҫ������ļ����ƣ�";
	char name[50] = { '\0' };
	cin >> name;
	FILE *fk = fopen(name, "r");
	if (fk == 0)
	{
		error();
		cout << "�ļ���ʧ�ܣ������������ļ����ƣ�" << endl;
		goto start;
	}
	else
	{
		bullet = 1;
		fclose(fk);
		ifstream fp(name, ios::in);
		fstream fpp("current_course.txt", ios::out);
		if (fpp.fail())
		{
			cout << "�ļ�¼��ʧ�ܣ�"<<endl;
			return false;
		}
		success();
		cout <<star<< "�γ̵���ɹ���"<<star<<endl<<"����γ���Ϣ���£�" << endl;
		cout << starline<<endl<<setw(10) << std::left << "�γ̱��" << setw(30) << std::left << "�γ�����" << setw(20) << std::left
			<< "�ڿν�ʦ" << setw(10) << std::left << "��������" << setw(10) << std::left << "Ŀǰ��ѡ" << setw(10) << std::left << "�γ�����" << endl;
		char id[4] = { '\0' };
		fp >> id;
		while (!fp.eof())
		{
			lesson p;
			strcpy(p.id, id);
			fp >> p.name;
			fp >> p.tutor;
			fp >> p.max;
			fp >> p.current;
			fp >> p.type;
			info.push_back(p);
			cout << setw(10) << std::left << p.id << setw(30) << std::left << p.name
				<< setw(20) << std::left << p.tutor << setw(10) << std::left << p.max << setw(10) << std::left << p.current << setw(10) << std::left << p.type << endl;
			fpp << p.id << " " << p.name << " " << p.tutor << " " << p.max << " " << p.current << " " << p.type << endl;
			fp >> id;
		}
		cout << starline << endl;
		fpp.close();
		fp.close();
		initial_ta_info();
	}
	return true;
}
bool view_alllesson_info()
{
	FILE *fk = fopen("current_course.txt", "r");
	if (fk == 0)
	{
		error();
		cout << "�޷��鿴�γ���Ϣ���뵼��γ̺��ٽ��в�����" << endl;
		return false;
	}
	fclose(fk);
	vector<lesson>::iterator loc = info.begin(), last = info.end();
	if (loc == last)
	{
		notice();
		cout << "Ŀǰ��û�пγ̣�" << endl;
		return true;
	}
	cout << "ȫ���γ���Ϣ���£�" << endl<<starline<<endl;
	cout<< setw(10) << std::left<<  "�γ̱��" << setw(30) << std::left << "�γ�����" << setw(20) << std::left
		<< "�ڿν�ʦ" << setw(10) << std::left << "��������" << setw(10) << std::left << "Ŀǰ��ѡ" << setw(10) << std::left << "�γ�����" << endl;
	while (loc != last)
	{
		cout <<setw(10) <<std::left << loc->id<<setw(30)<<std::left<< loc->name
			 << setw(20) << std::left << loc->tutor << setw(10) << std::left << loc->max << setw(10) << std::left<< loc->current << setw(10) << std::left << loc->type << endl;
		loc++;
	}
	cout << starline << endl;
	return true;
}
bool add_lesson()
{
	FILE *fk = fopen("current_course.txt", "r");
	if (fk==0)
	{
		error();
		cout << "�޷���ӿγ̣��뵼��γ̺��ٽ��в�����" << endl;
		return false;
	}
	fclose(fk);
	
	cout << "����������γ���Ϣ�����ơ���ʦ���������������ͣ��ÿո�ָ����س���������";
	lesson p;
	cin >> p.name>> p.tutor >> p.max >> p.type;
		p.current = 0;
		if (check_duplicate2(p.name, p.tutor))
		{
			error();
			cout << "����Ŀγ��Ѵ��ڣ����ʧ�ܣ�" << endl;
			return false;
		}
		else if (fabs(strcmp(p.type, "רҵ��")) && fabs(strcmp(p.type, "��רҵ��")))
		{
			error();
			cout <<"����Ŀγ����Ͳ����Ϲ涨�����ʧ�ܣ�" << endl;
			return false;
		}
		else if (p.max <= 0)
		{
			error();
			cout << "������������������Ϲ涨�����ʧ�ܣ�" << endl;
			return false;
		}
		p.id[3] = '\0';
		if (info.size() == 0)
		{
			int maxs = p.max, currents = p.current;
			char ids[4] = { '\0' }, names[31] = { '\0' }, tutors[31] = { '\0' }, types[31] = { '\0' };
			strcpy(names, p.name); strcpy(tutors, p.tutor); strcpy(types, p.type);
			strcpy(p.id, "001");
			strcpy(ids, p.id);
			info.push_back(p);
			FILE *fpk = fopen("current_course.txt", "w+");
			fprintf(fpk, "%s\t%s\t%s\t%d\t%d\t%s\n", ids, names, tutors, maxs, currents, types);
			fclose(fpk);
		}
		else
		{
			vector<lesson>::iterator loc = info.begin(), last = info.end();
			while (loc != last - 1)
				loc++;
			int i = (loc->id[0] - '0') * 100 + (loc->id[1] - '0') * 10 + (loc->id[2] - '0') + 1;
			if (i <= 9)
			{
				p.id[0] = '0';
				p.id[1] = '0';
				p.id[2] = '0' + i;
			}
			else if (i <= 99)
			{
				p.id[0] = '0';
				p.id[1] = '0' + i / 10;
				p.id[2] = '0' + i % 10;
			}
			else if (i <= 999)
			{
				p.id[0] = '0' + i / 100;
				p.id[1] = '0' + (i % 100) / 10;
				p.id[2] = '0' + i % 10;
			}
			info.push_back(p);
		ofstream fp("current_course.txt", ios::app);
		fp << p.id << "\t" << p.name << "\t" << p.tutor << "\t" << p.max << "\t" << p.current << "\t" << p.type << endl;
		fp.close();
		}
		FILE *fpp = fopen("assistant.txt", "a+");
		if (fpp == 0)
		{
			cout << "�γ���ӳɹ�����������ӿγ��޷����������б�" << endl;
			return false;
		}
		fprintf(fpp, "%s", p.id);
		fprintf(fpp, "%s\n", " Null");
		fclose(fpp);
		success();
		cout << star <<"�γ���ӳɹ���" << star << endl;
	return true;
}
bool check_duplicate2(char name[], char tutor[])
{
	vector<lesson>::iterator first = info.begin(), last = info.end();
	while (first != last)
	{
		if ((!strcmp(name, first->name))&&(!strcmp(tutor,first->tutor)))
			return true;
		else first++;
	}
	return false;
}
bool delete_lesson()
{
	FILE *fk = fopen("current_course.txt", "r");
	if (fk==0)
	{
		error();
		cout << "�޷�ɾ���γ̣��뵼��γ̺��ٽ��в�����" << endl;
		return false;
	}
	fclose(fk);
	vector<lesson>::iterator first1 = info.begin(), last1 = info.end();
	if (first1 == last1)
	{
		error();
		cout << "Ŀǰ��û�пγ̣��޷�ɾ����" << endl;
		return true;
	}
	view_alllesson_info();
	char num[4] = { '\0' };
	cout << "�������ɾ���Ŀγ̱�ţ�";
	while (1)
	{
		vector<lesson>::iterator first = info.begin(), last = info.end();
		cin >> num;
		int flag1 = 1, flag2 = 0;
		while (first != last)
		{
			if (!strcmp(num, first->id))
				flag1 = 0;
			if (flag1 == 0 && first->current == 0)
			{
				info.erase(first);
				break;
			}
			else if (flag1 == 0 && first->current != 0)
			{
				flag2 = 1;
				break;
			}
			first++;
		}
		if (flag1)
		{
			error();
			cout << "IDΪ"<<num<<"�Ŀγ̲����ڣ�ɾ��ʧ�ܣ�" << endl;
			if (getchar() == '\n')
				break;
			else continue;
		}
		else if (flag2)
		{
			error();
			cout << "������ѡ��IDΪ"<<num<<"�Ŀγ̣�ɾ��ʧ�ܣ�" << endl;
			if (getchar() == '\n')
				break;
			else continue;
		}
		else
		{
			ofstream fp("current_course.txt", ios::out);
			vector<lesson>::iterator loc = info.begin(), end = info.end();
			while (loc != end)
			{
				fp << loc->id << "\t" << loc->name << "\t" << loc->tutor << "\t" << loc->max << "\t" << loc->current << "\t" << loc->type << endl;
				loc++;
			}
			fp.close();
			FILE *fpp = fopen("assistant.txt", "r");
			if (fpp == 0)
			{
				cout << "�޷��޸ĸÿγ�������Ϣ��" << endl;
				return false;
			}
			char already[4] = { '\0' }, temp[5000] = { '\0' }, tmp[5000] = { '\0' }, key[5000] = { '\0' };
			fscanf(fpp, "%s", already);
			while (!feof(fpp))
			{
				fscanf(fpp, "%s", temp);
				if (fabs(strcmp(already, num)))
				{
					strcat(tmp, already);
					strcat(tmp, " ");
					strcat(tmp, temp);
					strcat(tmp, "\n");
				}
				else if (!strcmp(already, num))
				{
					fseek(fpp, 2, SEEK_CUR);
					fscanf(fpp, "%[^;]", key);
					fclose(fpp);
					FILE *fk = fopen("assistant.txt", "w+");
					if (fk == 0)
					{
						cout << "�޷��޸Ŀγ�������Ϣ��";
						return false;
					}
					fprintf(fk, tmp);
					fprintf(fk, key);
					fclose(fk);
					break;
				}
				fscanf(fpp, "%s", already);
			}
		}
		success();
		cout << star <<"IDΪ"<<num<< "�Ŀγ�ɾ���ɹ���" << star << endl;
		if (getchar() == '\n')
				break;
	}
	cout << "ɾ����";
	view_alllesson_info();
	return true;
}
bool change_lesson()
{
	FILE *fk = fopen("current_course.txt", "r");
	if (fk==0)
	{
		error();
		cout << "�޷��޸ģ��뵼��γ̺��ٽ��в�����"<<endl;
		return false;
	}
	fclose(fk);
	char num[4] = { '\0' };
	cout << "��������Ҫ�޸ĵĿγ̺ţ�";
	cin >> num;
	vector<lesson>::iterator first = info.begin(), last = info.end();
	int flag=1;
	while (first != last)
	{
		if (!strcmp(num, first->id))
		{
			flag = 0;
			break;
		}
		first++;
	}
	if (flag)
	{ 
		error();
		cout << "��ѡ��Ŀγ̲����ڣ�"<<endl;
	}
	else
	{
		int choice;
	cout << "��ѡ����Ҫ�޸ĵ����� ��1.��ʦ	2.������������";
	cin >> choice;
	cout << "�����޸�Ϊ��";
	if (choice == 1)
	{
		char tutor[31] = { '\0' };
		cin >> tutor;
		strcpy(first->tutor, tutor);
		success();
		cout << star<<"�޸Ŀγ̽�ʦ�ɹ���"<<star<<endl;
	}
	else if (choice == 2)
	{
		int temp;
		cin >> temp;
		if (temp < first->max)
		{
			error();
			cout << "�޸ĺ���������С�ڵ�ǰ�����������޸�ʧ�ܣ�" << endl;
			return false;
		}
		else
		{
			first->max = temp;
			success();
			cout <<star<< "�޸Ŀγ����������ɹ���"<<star<<endl;
		}
	}
	else
	{
		error();
		cout << "������Ч��";
		return false;
	}
		ofstream fp("current_course.txt", ios::out);
		vector<lesson>::iterator loc = info.begin(), end = info.end();
		while (loc != end)
		{
			fp << loc->id << "\t" << loc->name << "\t" << loc->tutor << "\t" << loc->max << "\t" << loc->current << "\t" << loc->type << endl;
			loc++;
		}
		fp.close();
	}
	return true;
	}
bool view_specific_info()
{
	FILE *fk = fopen("current_course.txt", "r");
	if (fk==0)
	{
		error();
		cout << "�޷��鿴�γ���Ϣ���뵼��γ̺��ٽ��в�����" << endl;
		return false;
	}
	fclose(fk);
	char temp[31] = { '\0' };
	cout << "��������Ҫ�鿴�Ŀγ̺Ż�γ����ƣ�";
	cin >> temp;
	vector<lesson>::iterator first = info.begin(), last = info.end();
	int flag = 1;
	while (first != last)
	{
		if (!(strcmp(temp, first->id)&&strcmp(temp,first->name)))
		{
			flag = 0;
			break;
		}
		first++;
	}
	if (flag)
	{
		error();
		cout << "��ѡ��Ŀγ̲����ڣ�" << endl;
	}
	else
	{
		cout << "�γ���Ϣ���£�"<<endl<<starline<<endl;
		cout << first->id << "\t" << first->name << "\t" << first->tutor << "\t" << first->max << "\t" << first->current << "\t" << first->type << endl<<starline<<endl;
		cout << "��ѡ����鿴�����ݣ�1.ѡ��ѧ������	2.����������������";
		int choice;
		cin >> choice;
		if (choice == 1)
		{
			if (first->chosen_by.size() == 0)
				cout << "�ÿγ�Ŀǰû��ѧ��ѡ��";
			else
			{
				cout << "Ŀǰѡ��ÿγ̵�ѧ���У�";
				for (auto beg = first->chosen_by.begin(); beg < first->chosen_by.end(); beg++)
					cout << *beg << " ";
			}
				cout << endl;
		}
		else if (choice == 2)
		{
			FILE *fp = fopen("assistant.txt", "r");
			if (fp == 0)
			{
				cout << "�޷��鿴�γ�������Ϣ��" << endl;
				return false;
			}
			char id[31] = { '\0' };
			
			fscanf(fp, "%s", id);
			while (!feof(fp))
			{
				char ta[5000] = { '\0' };
				if (!strcmp(id, first->id))
				{
					fscanf(fp, "%s", ta);
					if (!strcmp(ta, "Null"))
						cout << "�ÿγ�Ŀǰû�����̣�" << endl;
					else cout << "Ŀǰ�ÿγ̵������У�" << ta << endl;;
					break;
				}
				fscanf(fp, "%s", ta);
				fscanf(fp, "%s", id);
			}
			fclose(fp);
			return true;
		}
		else
		{ 
			error();
			cout << "������Ч�������ϼ����棡";
		}
	}
	return false;
	}
bool initial_ta_info()
{
	FILE *fp = fopen("assistant.txt", "w+");
		if (fp == 0)
		{
			cout << "����������ʼ��ʧ�ܣ�";
			return false;
		}
	for (auto i = info.begin(); i < info.end(); i++)
		{
			fprintf(fp, "%s", i->id);
			fprintf(fp, "%s"," ");
			fprintf(fp, "%s\n", "Null");
		}
		fclose(fp);
		return true;
}
bool view_ta_stu()
{
	char lesson_id[4] = { '\0' };
	FILE *fp = fopen("student.txt", "r");
	FILE *fk = fopen("assistant.txt", "r");
	if (fp == 0 || fk == 0)
	{
		error();
		cout << "�鿴���̶�Ӧѧ������ʧ�ܣ����ȵ���γ���Ϣ��" << endl;
		return false;
	}
	else
	{
		cout<<"���������鿴�Ŀγ�ID��";
		cin >> lesson_id;
		char already[4] = { '\0' }, temp[5000] = { '\0' }; int flag1 = 1;
		fscanf(fk, "%s",already);
		while (!feof(fk))
		{
			fscanf(fk, "%s", temp);
			if (!strcmp(already, lesson_id))
			{
				flag1 = 0;
				break;
			}
			fscanf(fk, "%s", already);
		}
		if (flag1)
		{
			error();
			cout << "������Ŀγ̲����ڣ�" << endl;
			return false;
		}
		if (!strcmp(temp, "Null"))
		{
			cout << "�ÿγ�Ŀǰû�����̣�" << endl;
			return false;
		}
		cout << "�γ����̵�ѧ���������£�" << endl;
			int i = 0;
			for (int j = 0; temp[j]; j++)
				if (temp[j] == ',')
					i++;
			fseek(fk, -(int)strlen(temp), SEEK_CUR);
			for (int j = 0; j < i; j++)
			{
				int flag2 = 1;
				fscanf(fk, "%[^,]", temp);
				fseek(fk, 1, SEEK_CUR);
				cout << "����" << temp << "��ѧ���У�";
				fseek(fp, 0, SEEK_SET);
				char id[31] = { '\0' };
				fscanf(fp, "%[^,]", id);
				while (!feof(fp))
				{
					char ide[25] = { '\0' };
					strcpy(ide, id);
					strcat(ide, ".txt");
					FILE *fpp = fopen(ide, "r");
					if (fpp == 0)
					{
						cout << "�鿴������Ϣʧ�ܣ�";
						return false;
					}
					char tmp[4] = { '\0' };
					char ta[31] = { '\0' };
					fscanf(fpp, "%s", tmp);
					while (!feof(fpp))
					{
						fscanf(fpp, "%s", ta);
						if (!strcmp(tmp, lesson_id))
						{
							if (!strcmp(ta, temp))
							{
								flag2 = 0;
								cout << id << " ";
								break;
							}
							else break;
						}
						fscanf(fpp, "%s", tmp);
					}
					fclose(fpp);
					fseek(fp, 1, SEEK_CUR);
					fscanf(fp, "%s", id);
					fseek(fp, 2, SEEK_CUR);
					fscanf(fp, "%[^,]", id);
				}
				if (flag2)
					cout << "��"<< endl;
				else cout << endl;
			}
			fscanf(fk, "%s", temp);
			cout << "����" << temp << "��ѧ���У�";
		char id[31] = { '\0' };
		fseek(fp, 0, SEEK_SET);
		fscanf(fp, "%[^,]", id);
		int flag2 = 1;
		while (!feof(fp))
		{
			char ide[25] = { '\0' };
			strcpy(ide, id);
			strcat(ide, ".txt");
			FILE *fpp = fopen(ide, "r");
			if (fpp == 0)
			{
				cout << "�鿴������Ϣʧ�ܣ�";
				return false;
			}
			char tmp[4] = { '\0' };
			char ta[31] = { '\0' };
			fscanf(fpp, "%s", tmp);	
			while (!feof(fpp))
			{
				fscanf(fpp, "%s", ta);
				if (!strcmp(tmp, lesson_id))
				{
					if(!strcmp(ta,temp))
					{
						flag2 = 0;
						cout << id << " ";
						break;
					}
				}
			fscanf(fpp, "%s", tmp);
			}
			fclose(fpp);
			fseek(fp, 1, SEEK_CUR);
			fscanf(fp, "%s", id);
			fseek(fp, 2, SEEK_CUR);
			fscanf(fp, "%[^,]", id);
		}
		if (flag2)
			cout << "��" << endl;
		else cout << endl;
	}
	fclose(fp);
	return true;
}
