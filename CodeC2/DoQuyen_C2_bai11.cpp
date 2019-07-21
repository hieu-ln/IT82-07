#include <iostream>
#include<stdio.h>
using namespace std;

//cau 11.1
struct Node
{
	int info;
	Node *link;
};
Node *front, *rear;
// cau 11.2
void init()
{
	front = NULL;
	rear = NULL;
}
int isEmpty()
{
	if (front == NULL)
		return 1;
	return 0;
}
// cau 11.4: them phan tu vao queue
void Push(int x)
{
	Node *p = new Node;
	p->info = x;
	p->link = NULL;
	if (rear == NULL)
		front = p;
	else
		rear->link = p;
	rear = p;
}
// cau 11.5 : lay phan tu khoi queue
int Pop(int &x)
{
	if (front != NULL)
	{
		Node *p = front;
		front = p->link;
		x = p->info;
		if (front == NULL)
		{
			rear = NULL;
		}
		delete p;
		return 1;
	}
	return 0;
}
// xuat queue
void Process_queue()
{
	if (front != NULL)
	{
		Node *p = front;
		cout << "<--  ";
		do {
			cout << p->info<<" ";
			p = p->link;
		} while (p != NULL);
		cout << "---  " << endl;

	}
}
int main()
{
	int choice, x, i;
	system(" cls");
	cout << " --------BAI TAP 7 , CHUONG 2,QUEUE ( HANG DOI _ DSLK)------" << endl;
	cout << " 1. khoi tao queue rong " << endl;
	cout << " 2. them phan tu vao queue" << endl;
	cout << " 3. lay phan tu ra khoi queue" << endl;
	cout << " 4. kiem tra queue co rong hay khong " << endl;
	cout << " 5. xuat queue" << endl;
	cout << " 6. thoat!!!" << endl;
	do {
		cout << " \nVui long chon so de thuc hien :";
		cin >> choice;
		switch (choice)
		{
		case 1:
			init();
			cout << " ban vua khoi tao queue rong thanh cong !\n";
			break;
		case 2:
			cout << "Vui long nhap gia tri x = " << endl;
			cin >> x;
			Push(x);
			cout << " queue sau khi them ra la :";
			Process_queue();
			break;
		case 3:
			Pop(x);
			cout << " phan tu lay ra tu queue la x =" << x << endl;
			cout << " queue sau khi lay ra la :";
			Process_queue();
			break;
		case 4:
			i = isEmpty();
			if (i == 0)
				cout << " queue khong rong !!" << x << endl;
			else
				cout << " queue rong !" << endl;
			break;
		case 5:
			cout << " queue hien tai la :";
			Process_queue();
			break;
		case 6:
			cout << " Goodbye -------" << endl;
			break;
		default:
			break;
		}
	} while (choice != 6);
	system("pause");
	return 0;
}