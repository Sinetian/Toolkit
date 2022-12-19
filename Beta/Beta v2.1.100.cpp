#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <ctime>
#include <windows.h> 
using namespace std;
double sor[105];
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
	cout << "�汾��Beta v2.1.100 ����ʱ�䣺2022-12-20" << endl;
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
bool cmp(double x , double y)
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
bool isPrime(int x)
{
	for(int i = 2; i * i <= x; i++)
	{
		if(x % i == 0) return false;
	}
	return true;
}
int main()
{
	sysinfo();
	int ope;
	cout << "��ӭʹ����Sinetian������Sinetian's Toolkit��" << endl;
	while(1)
	{
		cout << "���棺����Ϊֹ��û���κι���֧�ִ����ַ�����������������ɵ�BUG�����账��" << endl;
		cout << "���������¹��ܿ��ã�" << endl;
		cout << "1.������ 2.������ 3.ʱ����ʾ 4.�����ж� 5.ϵͳ��Ϣ 6.������־ 7.�˳�" << endl;
		cout << "��������ţ�";
		cin >> ope;
		switch(ope)
		{
			case 1:
			{
				cout << endl << "������ʹ��ע�����" << endl << "1.��������������ʱ���뱣֤��һ�������ں���ġ�" << endl << "2.�����Ľ��������λС����" << endl;
				double x , y; char op;
				cout << "��������������";
				cin >> x >> y;
				cout << "������һ�²���֮һ��+���ӣ���-��������*���ˣ���/��������";
				cin >> op;
				printf("%.3lf" , cal(x , y , op));
				break;
			}
			case 2:
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
				break;
			}
			case 3:
			{
			   time_t now = time(0);
			   char* dt = ctime(&now);
			   cout << "���أ�����������ں�ʱ�䣺" << dt << endl;
			   tm *gmtm = gmtime(&now);
			   dt = asctime(gmtm);
			   cout << "UTC������Э��ʱ�� ���ں�ʱ�䣺"<< dt << endl;
			   break;
			}
			case 4:
			{
				int n;
				cout << "������һ������";
				cin >> n;
				if(isPrime(n))
				{
					cout << "���Ǹ�������" << endl;
				}
				else
				{
					cout << "�ⲻ��������" << endl;
				}
				break;
			}
			case 5:
			{
				sysinfo();
				break;
			}
			case 6:
			{
				cout << "������־��" << endl;
				cout << "1.�������ж��߼���ʹ����switch...case...������if...else..." << endl;
				cout << "2.�����˶Ի���" << endl;
				break;
			}
			case 7:
			{
				if(MessageBox(NULL , "��ȷ��Ҫ�뿪��" , "�˳�" , MB_OKCANCEL+32) == 1) return 0;
				else break;
			}
		}
	}
}
