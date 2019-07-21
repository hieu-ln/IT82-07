#include<iostream>
#include<stdio.h>
using namespace std;

struct Node
{
	int info;
	Node *link;
};
Node *first;
//cau4.2 Khoi tao danh sach rong
void init()
{
	first=NULL;
}
//cau4.3 them vao dau danh sach
void insert_first(int x)
{
	Node *p;
	p=new Node;
	p->info=x;
	p->link=first;
	first=p;
}
//cau4.4: xuat cac phan tu trong danh sach
void process_list()
{
	Node *p;
	p=first;
	while(p!=NULL)
	{
		cout<<p->info<<"\t";
		p=p->link;
	}
	cout<<endl;
}
//cau4.5: tim mot phan tu trong danh sach
Node* search(int x)
{
	Node *p=first;
	while(p!=NULL&&p->info!=x)
	{
		p=p->link;
	}
	return p;
}

//cau4.6 tim phan tu va xoa
int searchAnddelete(int x)
{
	if(first!=NULL)
	{
		Node *p,*q;
		p=first;
		q=first;
		while(p->info!=x)
		{
			q=p;
			p=p->link;
		}
		if(p!=first&&p!=NULL)
		{
			if(p->link!=NULL)
				q->link=p->link;
			else
				q->link=NULL;
			delete p;
			return 1;
		}
		else
			if(p==first)
			{
				first=p->link;
				delete p;
				return 1;
			}
			else
				return 0;
	}
	return 0;
}
int main()
{
	int choice=0;
	int x,i;
	Node*p;
	system("cls");
	cout<<"--------------BAI TAP 3,CHUONG1------------"<<endl;
	cout<<"1.Khoi Tao Danh Sach"<<endl;
	cout<<"2.Them Phan Tu Vao Dau Danh Sach"<<endl;
	cout<<"3.Xuat danh sach"<<endl;
	cout<<"4.tim phan tu co gia tri x trong danh sach:"<<endl;
	cout<<"5.tim va xoa phan tu co gia tri x"<<endl;
	cout<<"6.thoat"<<endl;
	do{
		cout<<"\Vui long chon so:";
		cin>>choice;
		switch(choice)
		{
		case 1:
			init();
			cout<<"\n Ban vua khoi tao danh sach thanh cong"<<endl;
			break;
		case 2:
			cout<<"Vui long nhap gia tri x=";
			cin>>x;
			insert_first(x);
			cout<<"Danh sach sau khi them la";
			process_list();
			break;
		case 3:
			cout<<"Danh sach hien tai la: ";
			process_list();
		case 4:
			cout<<"Nhap gia tri can tim x=";
			cin>>x;
			p=search(x);
			if(p!=NULL)
			{
				cout<<"Tim thay phan tu co gia tri x";
			}
			else
				cout<<"Khong tim thay";
			break;
		case 5:
			cout<<"Nhap gia tri can tim x=";
			cin>>x;
			i=searchAnddelete(x);
			if(i==1)
			{
				cout<<"tim thay x va da xoa tha cong"<<endl;
				cout<<"Danh sach sau khi xoa la: ";
				process_list();
			}
			else
				cout<<"Khong tim thay x"<<endl;
			break;
		case 6:
			cout<<"Good bye\n";
			break;
		}
	}while(choice!=6);
		system("pause");
		return 0;
}