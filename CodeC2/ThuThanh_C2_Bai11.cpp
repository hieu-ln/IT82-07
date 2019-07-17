//CHUONG 2 - BAI 11: DANH SACH HAN CHE, HANG DOI, QUEUE
//QUEUE su dung DANH SACH LIEN KET
#include <stdio.h>
#include <iostream>
using namespace std;

//Cau 11.1: Khai bao cau truc QUEUE
struct Node 
{
	int info;
	Node *link;
};
Node *front, *rear;

//Cau 11.2: Khoi tao QUEUE rong
void init()
{
	front = NULL;
	rear = NULL;
}

//Kiem tra QUEUE rong
int isEmpty()
{
	if (front == NULL)
		return 1;
	return 0;
}

//Cau 11.4:Them phan tu vao QUEUE
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

//Cau 11.5: Lay phan tu ra khoi QUEUE
int Pop(int &x)
{
	if (front != NULL){
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

//Xuat QUEUE
void Process_queue()
{
	if(front != NULL)
	{
		Node *p = front;
		cout<<"<--   ";
		do
		{
			cout<<p->info<<"  ";
			p = p->link;
		}while (p != NULL);
		cout<<"<--"<<endl;
	}
}

int main()
{
	int choice, x, i;
	system("cls");
	cout<<"------- BAI TAP 11, CHUONG 2, QUEUE (HANG DOI - DANH SACH LIEN KET) -------"<<endl;
	cout<<"1. Khoi tao QUEUE rong"<<endl;
	cout<<"2. Them phan tu vao QUEUE"<<endl;
	cout<<"3. Lay phan tu ra khoi QUEUE"<<endl;
	cout<<"4. Kiem tra QUEUE co rong hay khong!"<<endl;
	cout<<"5. Xuat QUEUE"<<endl;
	cout<<"6. Thoat"<<endl;
	do
	{
		cout<<"\nVui long chon so de thuc hien: ";
		cin >> choice;
		switch (choice)
		{
			case 1:
				init();
				cout<<"Ban vua khoi tao QUEUE rong thanh cong!\n";
				break;
			case 2:
				cout<<"Vui long nhap gia tri x = ";
				cin >> x;
				Push(x);
				cout<<"QUEUE sau khi them la: ";
				Process_queue();
				break;
			case 3:
				Pop(x);
				cout<<"Phan tu lay ra tu QUEUE la x = "<< x <<endl;
				cout<<"QUEUE sau khi lay "<<x<<" ra la: ";
				Process_queue();
				break;
			case 4:
				i = isEmpty();
				if(i == 0)
					cout<<"QUEUE khong rong!"<<endl;
				else
					cout<<"QUEUE rong !"<<endl;
				break;
			case 5:
				cout<<"QUEUE ien tai la: ";
				Process_queue();
				break;
			case 6:
				cout <<"GOODBYE!!!"<<endl;
				break;
			default:
				break;
		}
	}while(choice != 6);
	system("pause");
	return 0;
}