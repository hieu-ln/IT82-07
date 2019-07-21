#include <stdio.h>
#include <iostream>
using namespace std;

//cau 10.1 : Khai bao cau truc Stack
struct Node
{
	int info;
	Node *link;
};
Node *sp;

//cau 10.2: Khoi tao stack rong
void init()
{
	sp = NULL;
}

//cau 10.3: ktra stack rong
int isEmpty()
{
	if(sp == NULL)
		return 1;
	return 0;
}

//cau 10.4: them phan tu vao stack
void Push(int x)
{
	Node *p = new Node;
	p ->info = x;
	p ->link = sp;
	sp = p;
}

//cau 10.5: lay phan tu ra khoi stack
int Pop(int &x)
{
	if(sp != NULL)
	{
		Node *p = sp;
		x = p ->info;
		sp = p ->link;
		delete p;
		return 1;
	}
	return 0;
}

//xuat stack
void Process_stack()
{
	Node *p = sp;
	do{
		cout << p ->info << "  ";
		p = p ->link;
	}while(p != NULL);
	cout << endl;
}
 
int main()
{
	int choice,x,i;
	system("cls");
	cout << "-------- BAI TAP 10 , CHUONG 2 , STACK (NGAN XEP) --------"<<endl;
	cout << "1. Khoi tao stack rong!"<<endl;
	cout << "2. Them phan tu vao stack!"<<endl;
	cout << "3. Lay phan tu ra khoi stack!"<<endl;
	cout << "4. Xuat Stack"<<endl;
	cout << "5. Thoat"<<endl;

	do{
		cout << "\nVui long nhap so can thuc hien: ";
		cin >> choice;
		switch(choice)
		{
			case 1:
				init();
				cout << "Ban vua khoi tao stack thanh cong\n";
				break;
			case 2:
				cout << "Vui long nhap gia tri x=";
				cin >> x;
				Push(x);
				cout << "Stack sau khi them la: ";
				Process_stack();
				break;
			case 3:
				Pop(x);
				cout << "Phan tu lay ra tu stack la: ";
				Process_stack();
				break;
			case 4:
				cout << "Stack hien tai la: ";
				Process_stack();
				break;
			case 5:
				cout << "Goodbye.....!"<<endl;
				break;
			default:
				break;
		}
	}while(choice != 5);
	system("pause");
	return 0;
}