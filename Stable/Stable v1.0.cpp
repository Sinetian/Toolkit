#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
int sor[105];
void sysinfo()
{
	cout << "**************************" << endl;
	cout << "**                      **" << endl;
	cout << "**   ********           **" << endl;
	cout << "**      **              **" << endl;
	cout << "**      **              **" << endl;
	cout << "**      **              **" << endl;
	cout << "**      **    ***       **" << endl;
	cout << "**      **    ***       **" << endl;
	cout << "**                      **" << endl;
	cout << "**************************" << endl;
	cout << "**  Sinetian's Toolkit  **" << endl;
	cout << "**************************" << endl;
	cout << "�汾��STABLE v1.0 ����ʱ�䣺2022-11-28" << endl;
}
double cal(double x , double y , char op)
{
	
	if(y == 0 && op == '/')
	{
		cout << "�����Գ���0��" << endl;
		return 0;
	}
	if(op != '+' && op != '-' && op != '*' && op != '/')
	{
		cout << "����δ֪��" << endl;
		return 0;
	}
	if(op == '+')
	{
		return x + y;
	}
	if(op == '-')
	{
		return x - y;
	}
	if(op == '*')
	{
		return x * y;
	}
	if(op == '/')
	{
		return x / y;
	}
	return 0;
}
bool cmp(int x , int y)
{
	return x > y; 
}
void qsort(int num)
{
	sort(sor + 1 , sor + num + 1 , cmp);
}
void ssort(int num)
{
	for(int i = 1; i <= num; i++)
	{
		for(int j = 1; j <= i; j++)
		{
			if(sor[j] > sor[i])
			{
				swap(sor[j] , sor[i]);
			}
		}
	}
}
int main()
{
	sysinfo();
	int ope;
	cout << "��ӭʹ����Sinetian������Sinetian's Toolkit��" << endl;
	while(1)
	{
		cout << "���������¹��ܿ��ã�" << endl;
		cout << "1.������ 2.������ 3.ϵͳ��Ϣ 4.�˳�" << endl;
		cout << "��������ţ�";
		cin >> ope;
		if(ope == 1)
		{
			cout << endl << "������ʹ��ע�����" << endl << "1.��������������ʱ���뱣֤��һ�������ں���ġ�" << endl << "2.�����Ľ��������λС����" << endl;
			double x , y; char op;
			cout << "��������������";
			cin >> x >> y;
			cout << "������һ�²���֮һ��+�ӡ�-����*�ˡ�/����";
			cin >> op;
			printf("%.3llf" , cal(x , y , op));
		}
		if(ope == 2)
		{
			int num;
			cout << "�������������ݸ���������100������";
			cin >> num;
			cout << "�����������������ݣ�";
			for(int i = 1; i <= num; i++)
			{
				cin >> sor[i];
			}
			cout << "��ѡ������ʽ��1.�������� 2.ѡ������";
			int ss; cin >> ss;
			if(ss == 1) qsort(num);
			if(ss == 2) ssort(num);
			cout << "����Ӵ���С����Ϊ��";
			for(int i = 1; i <= num; i++) cout << sor[i] << " ";
			cout << endl;
		}
		if(ope == 3)
		{
			sysinfo();
		}
		if(ope == 4)
		{
			int end;
			cout << "��ȷ��Ҫ�˳�����������1����������0��";
			cin >> end;
			if(end == 1) return 0;
			else continue; 
		}
	}
	return 0;
}
