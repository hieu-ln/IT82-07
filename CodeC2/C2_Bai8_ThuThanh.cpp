//Chuong 2, Bai 8 : SU DUNG STACK DA XAY DUNG, DOI CO SO TU HE THAP PHAN SANG HE BAT KI
#include <stdio.h>
#include <iostream>
using namespace std;

//Khai bao cau truc STACK
struct Node
{
	int info;
	Node *link;
};
Node *sp;

//Khoi tao danh sach rong
void Init()
{
	sp = NULL;
}


//Kiem tra STACK rong
int isEmpty()
{
	if (sp==NULL)
		return 1;
	return 0;
}

//Them phan tu vao STACK
void Push(int x)
{
	Node *p = new Node;
	p->info = x;
	p->link = sp;
	sp = p;
}

//Lay phan tu ra khoi STACK
int Pop(int &x)
{
	if (sp != NULL)
	{
		Node *p = sp;
		x = p->info;
		sp = p->link;
		delete p;
		return 1;
	}
	return 0;
}

//Ham doi co so tu he thap phan sang he 2, 8, 16
void DoiCoSo (int cosocandoi, int hethapphan)
{

	while (hethapphan != 0)
	{
		int x = hethapphan % cosocandoi;
		Push(x); 
		hethapphan /= cosocandoi;
	}

}

//Xuat STACK
void Process_stack()
{
	Node *p;
	p = sp;
	do
	{
		if (p -> info < 10)
			cout << p -> info;
		else
		{
			if (p -> info == 10)
			{
				cout << "A";
			}
			else if (p -> info == 11)
			{
				cout << "B";
			}
			else if (p -> info == 12)
			{
				cout << "C";
			}
			else if (p -> info == 13)
			{
				cout << "D";
			}
			else if (p -> info == 14)
			{
				cout << "E";
			}
			else if (p -> info == 15)
			{
				cout << "F";
			}
		}
		p = p -> link;
	}while (p!= NULL);
	cout << endl;
}

int main()
{
	int choice, x, i;
	system("cls");
	cout << " -------- BAI TAP 10, CHUONG 2, STACK (Ngan xep - DSLK) --------" << endl;
	cout << "1. Khoi tao STACK rong" << endl;
	cout << "2. Chuyen doi co so" << endl;
	cout << "3. Xuat STACK" << endl;
	cout << "4. Thoat" << endl;

	do
	{
		cout << "\nVui long chon so de thuc hien: ";
		cin >> choice;
		switch(choice)
		{
			case 1:
				Init();
				cout << "Ban vua khoi tao Stack rong thanh cong \n";
				break;

			case 2:
				int hethapphan;
				cout << "\nNhap gia tri he Thap phan can chuyen: ";
				cin >> hethapphan;
				int cosocandoi;
				do {
				cout << "\nNhap co so can chuyen(2, 8, 16):  ";
				cin >> cosocandoi;
				} while ( cosocandoi != 2 && cosocandoi != 8 && cosocandoi != 16);

				DoiCoSo(cosocandoi, hethapphan);
				
				cout << "He Thap phan = "<< hethapphan << " -> He " << cosocandoi << " = ";

				Process_stack();
				break;

			case 3:
				cout << "STACK hien tai la: "<< endl;
				Pop(x);
				break;

			case 4:
				cout << "GOODBYE ......!"<< endl;
				break;

			default:
				break;
		}
	}while (choice != 4);
	system ("pause");
	return 0;
}
