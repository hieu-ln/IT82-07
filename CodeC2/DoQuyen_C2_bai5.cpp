#include<iostream>
#include<stdio.h>
using namespace std;

#define MAX 100
int a[MAX];
int sp;
//5.2
void init(int a[], int &sp)
{
	sp = -1;
}
 //5.3
int isEmpty(int a[], int sp)
{
	if(sp == -1)
		return -1;
	return 0;
}

//5.4
int isFull(int a[], int sp)
{
	if(sp == MAX -1)
		return 1;
	return 0;
}
//5.5
int Push(int a[], int &sp, int x)
{
	if(sp < MAX -1)
	{
		a[++sp] = x;
		return 1;
	}
	return 0;
}
//5.6
int Pop(int a[], int &sp, int &x)
{
	if(sp != -1)
	{
		x  = a[sp--];
		return 1;
	}
	return 0;
}
//xuat Stack
void Process_stack(int a[], int sp)
{
	for(int i=0; i < sp+1; i++)
	{
		cout << a[i] << "\t";
	}
	cout << endl;
}

int main ()
{
	int a[MAX];
	int choice, sp, x, i;
	system("cls");
	cout << "------- BAI TAP 5 , CHUONG 2 , STACK -------"<< endl;
	cout << "1. Khoi tao stack rong"<<endl;
	cout << "2. Kiem tra stack rong"<<endl;
	cout << "3. Kiem tra stack day"<<endl;
	cout << "4. Them phan tu vao stack"<<endl;
	cout << "5. Lay phan tu ra khoi stack"<<endl;
	cout << "6. Xuat stack"<<endl;
	cout << "7. Thoat"<<endl;

	do{
		cout << "Vui long chon so de thuc hien: ";
		cin >> choice;
		switch(choice)
		{
			case 1:
				init(a, sp);
				cout << "Ban vua khoi tao stack rong";
				break;
			case 2:
				i = isEmpty(a, sp);
				if(i == 0)
					cout << "Stack khong rong!" <<x<<endl;
				else
					cout << "Stack rong!"<<endl;
				break;
			case 3:
				i = isFull(a, sp);
				if(i == 0)
					cout << "Stack chua day!!"<<x<<endl;
				else
					cout << "Stack day!!"<<endl;
				break;
			case 4:
				cout << "Vui long nhap gia tri x=";
				cin >> x;
				i = Push(a, sp);
				cout << "Stack sau khi them la: ";
				Process_stack(a, sp);
				break;
			case 5:
				i = Pop(a, sp, x);
				cout << "Phan tu lay ra tu stack la x=";
				cout << "Stack sau khi lay ra la:";
				Process_stack(a, sp);
				break;
			case 6:
				cout << "Stack hien tai la:";
				Process_stack(a, sp);
				break;
			case 7:
				cout << "Goodbye------!"<< endl;
				break;
			default:
				break;
		}
	}while(choice != 7);
	system("pause");
	return 0;
}