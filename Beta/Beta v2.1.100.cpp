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
	cout << "版本：Beta v2.1.100 构建时间：2022-12-20" << endl;
}
double cal(double x , double y , char op)
{
	
	if(y == 0 && op == '/')
	{
		cout << "不可以除以0！" << endl;
		return 0;
	}
	if(op != '+' && op != '-' && op != '*' && op != '/')
	{
		cout << "操作未知。" << endl;
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
	cout << "欢迎使用由Sinetian开发的Sinetian's Toolkit！" << endl;
	while(1)
	{
		cout << "警告：现在为止，没有任何功能支持处理字符串。因随意输入造成的BUG将不予处理！" << endl;
		cout << "现在有以下功能可用：" << endl;
		cout << "1.计算器 2.排序器 3.时间显示 4.质数判断 5.系统信息 6.更新日志 7.退出" << endl;
		cout << "请输入序号：";
		cin >> ope;
		switch(ope)
		{
			case 1:
			{
				cout << endl << "计算器使用注意事项：" << endl << "1.在做除法、减法时，请保证第一个数大于后面的。" << endl << "2.除法的结果保留三位小数。" << endl;
				double x , y; char op;
				cout << "请输入两个数：";
				cin >> x >> y;
				cout << "请输入一下操作之一：+（加）、-（减）、*（乘）、/（除）：";
				cin >> op;
				printf("%.3lf" , cal(x , y , op));
				break;
			}
			case 2:
			{
				int num;
				cout << "请输入排序数据个数（至多100个）：";
				cin >> num;
				cout << "请依次输入排序数据：";
				for(int i = 1; i <= num; i++)
				{
					cin >> sor[i];
				}
				cout << "请选择排序方式：1.快速排序 2.选择排序：";
				int ss; cin >> ss;
				if(ss == 1) qsort(num);
				if(ss == 2) ssort(num);
				cout << "结果从大至小依次为：";
				for(int i = 1; i <= num; i++) cout << sor[i] << " ";
				cout << endl;
				break;
			}
			case 3:
			{
			   time_t now = time(0);
			   char* dt = ctime(&now);
			   cout << "本地（计算机）日期和时间：" << dt << endl;
			   tm *gmtm = gmtime(&now);
			   dt = asctime(gmtm);
			   cout << "UTC（国际协调时） 日期和时间："<< dt << endl;
			   break;
			}
			case 4:
			{
				int n;
				cout << "请输入一个数：";
				cin >> n;
				if(isPrime(n))
				{
					cout << "这是个质数！" << endl;
				}
				else
				{
					cout << "这不是质数！" << endl;
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
				cout << "更新日志：" << endl;
				cout << "1.更新了判断逻辑，使用了switch...case...而不是if...else..." << endl;
				cout << "2.更新了对话框" << endl;
				break;
			}
			case 7:
			{
				if(MessageBox(NULL , "你确定要离开？" , "退出" , MB_OKCANCEL+32) == 1) return 0;
				else break;
			}
		}
	}
}
