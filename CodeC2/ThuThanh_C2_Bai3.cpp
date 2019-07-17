//BAI 3 - CHUONG 2: DANH SACH LIEN KET DON
#include <stdio.h>
#include <iostream>
using namespace std;

//Cau 3.1
struct Node
{
	int info;
	Node *link;
};
Node *first;

//Cau 3.2
void Init()
{
	first = NULL;
}

//Cau 3.3
void Process_list()
{
	Node *p;
	p = first;
	while (p != NULL)
	{
		cout<<p->info<<"\t";
		p = p->link;
	}
	cout<<endl;
}

//Cau 3.4
Node *search(int x)
{
	Node *p = first;
	while (p != NULL && p->info != x)
	{
		p = p->link;
	}
	return p;
}

//Cau 3.5
void insert_first(int x)
{
	Node *p;
	p = new Node;
	p->info = x;
	p->link = first;
	first = p;
}

//Cau 3.6
int Delete_first()
{
	if (first != NULL)
	{
		Node *p = first;
		first = first->link;
		delete p;
		return 1;
	}
	return 0;
}

//Cau 3.7
void insert_last(int x)
{
	Node *p;
	p = new Node;
	p->info = x;
	p->link = NULL;
	if(first == NULL)
	{
		first = p;
	}
	else
	{
		Node *q = first;
		while (q->link != NULL)
		{
			q = q->link;
		}
		q->link = p;
	}
}

//Cau 3.8
int Delete_last()
{
	if (first != NULL)
	{
		Node *p, *q;
		p = first;
		q = first;
		while (p->link != NULL)
		{
			q = p;
			p = p->link;
		}
		if (p != first)
		{
			q->link = NULL;
		}
		else first = NULL;
		delete p;
		return 1;
	}
	return 0;
}


//Cau 3.9
int search_delete(int x)
{
	if (first != NULL)
	{
		Node *p, *q;
		p = first;
		q = first;
		while (p->info != x && p->link != NULL)
		{
			q = p;
			p = p->link;
		}
		if (p!= first && p != NULL)
		{
			if(p->link != NULL)
				q->link = p->link;
			else
				q->link = NULL;
			delete p;
			return 1;
		}
		else if(p == first)
		{
			first = p->link;
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
	int choice = 0;
	int x, i;
	Node *p;
	system("cls");
	cout<<"-----------CHUONG 2, BAI TAP 3, DANH SACH LIEN KET----------"<<endl;
	cout<<"1. Khoi tao Danh sach lien ket don rong"<<endl;
	cout<<"2. Them phan tu vao dau danh sach don"<<endl;
	cout<<"3. Them phan tu vao cuoi danh sach don"<<endl;
	cout<<"4. Xoa phan tu vao dau danh sach don"<<endl;
	cout<<"5. Xoa phan tu vao cuoi danh sach don"<<endl;
	cout<<"6. Xuat Danh sach lien ket don"<<endl;
	cout<<"7. Tim phan tu co gia tri x trong danh sach lien ket don"<<endl;
	cout<<"8. Tim phan tu voi gia tri x và xoa no neu tim thay"<<endl;
	cout<<"9. Thoat"<<endl;

	do
	{
		cout<<"Vui long chon so theo menu de thuc hien: ";
		cin >> choice;
		switch(choice)
		{
		case 1:
			Init ();
			cout<<"Ban vua khoi tao danh sach lien ket don thanh cong!\n";
			break;
		case 2:
			cout<<"Vui long nhap gia tri x = ";
			cin >> x;
			insert_first(x);
			cout<<"Danh sach sau khi them la: ";
			Process_list();
			break;
		case 3:
			cout<<"Vui long nhap x can them vao cuoi danh sach: ";
			cin >> x;
			insert_last(x);
			cout<<"Danh sach sau khi them la: ";
			Process_list();
			break;
		case 4:
			i = Delete_first();
			if(i = 0)
			{
				cout<<"Danh sach rong, khong the xoa!"<< x << endl;
			}
			else
			{
				cout<<"Xoa thanh cong!"<< endl;
				cout<<"Danh sach sau khi xoa phan tu dau la:\n";
				Process_list();
			}
			break;
		case 5:
			i = Delete_last();
			if(i = 0)
			{
				cout<<"Danh sach rong, khong the xoa!"<< x << endl;
			}
			else
			{
				cout<<"Xoa thanh cong!"<< endl;
				cout<<"Danh sach sau khi xoa phan tu cuoi la:\n";
				Process_list();
			}
			break;
		case 6:
			cout<<"Danh sach hien tai la: \n";
			Process_list();
			break;
		case 7: 
			cout<<"Vui long nhap vi tri can tim x = ";
			cin >> x;
			p = search(x);
			if(p != NULL)
			{
				cout<<"Tim thay phan tu co gia tri x = "<< x <<endl;
			}
			else
				cout<<"Khong tim thay phan tu co gia tri x = "<< x <<" !"<<endl;
			break;
		case 8: 
			cout<<"Vui long nhap gia tri can tim x = ";
			cin >> x;
			i = search_delete(x);
			if(i == 1)
			{
				cout<<"Xoa thanh cong phan tu co gia tri x = "<< x <<"!"<<endl;
				cout<<"Danh sach sau khi xoa la:\n";
				Process_list();
			}
			else
				cout<<"Khong tim thay phan tu x = "<< x <<" de xoa!"<<endl;
			break;
		case 9:
			cout<<"\nGOODBYE!!!"<<endl;
			break;
		default:
			break;
		}
	}while(choice != 9);
	system("pause");
	return 0;
}