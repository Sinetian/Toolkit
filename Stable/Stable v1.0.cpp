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
	cout << "版本：STABLE v1.0 构建时间：2022-11-28" << endl;
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
	cout << "欢迎使用由Sinetian开发的Sinetian's Toolkit！" << endl;
	while(1)
	{
		cout << "现在有以下功能可用：" << endl;
		cout << "1.计算器 2.排序器 3.系统信息 4.退出" << endl;
		cout << "请输入序号：";
		cin >> ope;
		if(ope == 1)
		{
			cout << endl << "计算器使用注意事项：" << endl << "1.在做除法、减法时，请保证第一个数大于后面的。" << endl << "2.除法的结果保留三位小数。" << endl;
			double x , y; char op;
			cout << "请输入两个数：";
			cin >> x >> y;
			cout << "请输入一下操作之一：+加、-减、*乘、/除：";
			cin >> op;
			printf("%.3llf" , cal(x , y , op));
		}
		if(ope == 2)
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
		}
		if(ope == 3)
		{
			sysinfo();
		}
		if(ope == 4)
		{
			int end;
			cout << "您确定要退出？是则输入1，否则输入0：";
			cin >> end;
			if(end == 1) return 0;
			else continue; 
		}
	}
	return 0;
}
