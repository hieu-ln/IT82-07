//BAI 7 , CHUONG 2: DANH SACH HAN CHE, HANG DOI, QUEUE
//QUEUE su dung danh sach dac
#include <stdio.h>
#include <iostream>
using namespace std;

#define MAX 100

//Cau 7.2: Khoi tao QUEUE rong
void init(int a[], int &front, int &rear)
{
	front = -1;
	rear = -1;
}

//Cau 7.3: Kiem tra QUEUE rong
int isEmpty(int a[], int &front, int &rear)
{
	if(front == rear)
		return 1;
	return 0;
}

//Cau 7.3: Kiem tra QUEUE day
int isFull(int a[], int &front, int &rear)
{
	if((front == 0 && rear == MAX - 1) || (front - rear == 1))
		return 1;
	return 0;
}

//Cau 7.5: Them phan tu vao QUEUE
int Push(int a[], int &front, int &rear, int x)
{
	if (rear - front == MAX - 1)
		return 0;
	else{
		if (front == -1)
			front = 0;
		if (rear == MAX -1)
		{
			for (int i = front; i <= rear; i++)
			{
				a[i - front] = a[i];
			}
			rear = MAX - 1 - front;
			front = 0;
		}
	a[++rear] = x;
	return 1;
	}
	return 0;
}

//Cau 7.6: Xoa mot phan tu ra khoi QUEUE
int Pop(int a[], int &front, int &rear, int &x)
{
	if (front == -1)
		return 0;
	else
	{
		x = a[front++];
		if (front > rear)
		{
			front = -1;
			rear = -1;
		}
		return 1;
	}
	return 0;
}

//Xuat QUEUE
void Process_queue(int a[], int f, int r)
{
	cout<<"f = "<<f<<"\t r = "<<r<<endl;
	if(f <= r && f != -1)
	{
		cout <<"<--    ";
		for (int i = f; i < r + 1; i++){
			cout <<a[i] <<"   ";
		}
		cout <<"<--"<<endl;
	}
}

int main()
{
	int a[MAX];
	int choice, f, r, x, i;
	system("cls");
	cout <<" ---------- BAI TAP 7 , CHUONG 2 , QUEUE (HANG DOI - DANH SACH DAC) ----------"<<endl;
	cout <<"1. Khoi tao QUEUE rong"<<endl;
	cout <<"2. Them phan tu vao QUEUE"<<endl;
	cout <<"3. Lay phan tu ra khoi QUEUE"<<endl;
	cout <<"4. Kiem tra QUEUE co rong hay khong?"<<endl;
	cout <<"5. Kiem ra QUEUE co day hay khong?"<<endl;
	cout <<"6. Xuat QUEUE"<<endl;
	cout <<"7. Thoat"<<endl;

	do
	{
		cout << "\nVui long chon so de thuc hien: ";
		cin >> choice;
		switch(choice)
		{
		case 1:
			init(a, f, r);
			cout << "Ban vua khoi tao QUEUE rong thanh cong!\n";
			break;
		case 2:
			cout << "Vui long nhap gia tri x = ";
			cin >> x;
			i = Push(a, f, r, x);
			cout << "QUEUE sau khi them la: ";
			Process_queue(a, f, r);
			break;
		case 3:
			i = Pop(a, f, r, x);
			cout <<"Phan tu lay ra tu QUEUE la x = "<< x <<endl;
			cout <<"QUEUE sau khi lay ra la: ";
			Process_queue(a, f, r);
			break;
		case 4:
			i = isEmpty(a, f, r);
			if(i == 0)
				cout<< "QUEUE khong rong!" << endl;
			else
				cout << "QUEUE rong!"<<endl;
			break;
		case 5:
			i = isFull(a, f, r);
			if(i == 0)
				cout<< "QUEUE chua day!" << endl;
			else
				cout << "QUEUE da day!"<<endl;
			break;
		case 6:
			cout <<"QUEUE hien tai la: ";
			Process_queue(a, f, r);
			break;
		case 7:
			cout <<"GOODBYE.....!" <<endl;
			break;
		default:
			break;
		}
	}while(choice != 7);
	system("pause");
	return 0;
}
