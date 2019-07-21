#include<iostream>
#include<stdio.h>
using namespace std;
//cau 3.1
struct Node
{
	int info;
	Node *link;
};
//cau 3.2
Node *first;
void init ()
{
	first = NULL;
}
//cau 3.3
void Process_list()
{
	Node *p;
	p = first;
	while(p != NULL)
	{
		cout << p ->info << endl;
		p = p ->link ;
	}
}
//cau 3.4
Node *search(int x)
{
	Node *p = first;
	while((p != NULL) && (p ->info = x))
		p = p ->link ;
	return p;
}
//cau 3.5
void insert_first(int x)
{
	Node *p;
	p = new Node;
	p ->info = x;
	p ->link = first; 
	first = p;
}
//cau 3.6
int Delete_first()
{
	if(first != NULL)
	{
		Node *p = first;
		first = first -> link;
		delete p;
		return 1;
	}
	return 0;
}
//cau 3.7
void insert_last(int x)
{
	Node *p;
	p = new Node;
	p ->info = x;
	p ->link = NULL;
	if(first == NULL)
	{
		first = p;
	}
	else
	{
		Node *q = first ;
		while(q ->link != NULL)
		{
			q = q ->link ;
		}
		q ->link = p;
	}
}
//cau 3.8
int Delete_last()
{
	if(first == NULL)
	{
		Node *q, *p;
		p = first;
		q = first;
		while(p ->link != NULL)
		{
			p = q;
			p = p ->link ;
		}
		if(p != first)
		{
			q ->link = NULL;
		}
		else
			first = NULL;
		delete p;
		return 1;
	}
	return 0;
}
//cau 3.9
int search_delete(int x)
{
	if(first == NULL)
	{
		Node *q, *p;
		p = first;
		q = first;
		while(p ->info != x)
		{
			p = q;
			p = p ->link ;
		}
		if(p != first && p!= NULL)
		{
			if(p ->link != NULL)
				q ->link = p ->link;
			else
				q ->link = NULL;
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
	cout << "-------- BAI TAP 3 , CHUONG 2 , DANH SACH LIEN KET DON --------" << endl;
	cout << "1. Khoi tao DSLKD rong "<< endl;
	cout << "2. Them phan tu vao dau DSLKD"<< endl;
	cout << "3. Them phan tu vao cuoi DSLKD"<< endl;
	cout << "4. Xoa phan tu vao dau DSLKD"<< endl;
	cout << "5. Xoa phan tu vao cuoi DSLKD"<< endl;
	cout << "6. Xuat DSLKD"<< endl;
	cout << "7. Tim mot phan tu gia tri x trong DSLKD"<< endl;
	cout << "8. Tim phan tu voi gia tri x va xoa no neu co" << endl;
	cout << "9. Thoat"<< endl;
	do{
		cout << "\nVUi long chon so de thuc hien:";
		cin >> choice;
		switch(choice)
		{
			case 1:
				init();
				cout << "Ban vua khoi tao DSLKD thanh cong!\n";
				break;
			case 2:
				cout << "Vui long hap gia tri x=";
				cin >> x;
				insert_first (x);
				cout << "Danh sach sau khi them la:";
				Process_list();
				break;
			case 3:
				cout << "Vui long nhap gia tri x=";
				cin >> x;
				insert_last (x);
				cout << "Danh sach sau khi them la:";
				Process_list();
				break;
			case 4:
				i = Delete_first();
				if(i == 0)
					cout << "Danh sach rong, khong the xoa!" << x <<  endl;
				else
				{
					cout << "Da xoa thanh cong phan tu dau cua DSLKD!"<< endl;
					cout << "Danh sach sau khi xoa la: ";
					Process_list();
				}
				break;
			case 5:
				i = Delete_last();
				if(i == 0)
					cout << "Danh sach rong, khong the xoa!" << x <<  endl;
				else
				{
					cout << "Da xoa thanh cong phan tu cuoi cua DSLKD!"<< endl;
					cout << "Danh sach sau khi xoa la: ";
					Process_list();
				}
				break;
			case 6:
				cout << "Danh sach hien tai la:";
				Process_list();
				break;
			case 7:
				cout << "Vui long nhap gia tri can tim x=";
				cin >> x;
				p = search(x);
				if(p !=NULL)
				{
					cout << "Tim thay phan tu co gia tri x="<<x<< endl;
				}
				else
					cout << "Khong thay phan tu co gia tri x="<<x<< "!!" <<endl;
				break;
			case 8:
				cout << "Vui long nhap gia tri can tim x=";
				cin >> x;
				i = search_delete(x);
				if(i == 1)
				{
					cout << "Tim thay x=" << x << "va xoa thanh cong" << endl;
					cout << "Danh sach sau khi xoa la: ";
					Process_list();
				}
				else
					cout << "Khong thay phan tu co gia tri x="<<x<< "!!" <<endl;
				break;
			case 9:
				cout << "goodbye......!"<< endl;
				break;
			default:
				break;
		}
	}while(choice != 9);
	system("pause");
	return 0;

}