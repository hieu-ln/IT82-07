#include <iostream>
using namespace std;
struct Node
{
	int info;
	Node *next, *previous;
};
Node *first, *last;
void init()
{
	first = NULL;
	last = NULL;
}
int isEmpty()// ktra rong
{
	if (first == NULL)
		return 1;
	return 0;
}
void Process_list()// xuat danh sach
{
	Node *p;
	p = first;
	while (p != NULL)
	{
		cout << p->info << endl;
		p = p->next;
	}
}
void Insert_first(int x)// chen dau danh sach
{
	Node *p;
	p = new Node;
	p->info = x;
	p->next = first;
	p->previous = NULL;
	if (first != NULL)
		first->previous = p;
	else
		last = p;
	first = p;
}
void Insert_last(int x)// chen cuoi danh sach
{
	Node *p;
	p = new Node;
	p->info = x;
	p->next = NULL;
	p->previous = last;
	if (last != NULL)
		last->next = p;
	else
		first = p;
	last = p;
}
int Delete_first()//xoa dau danh sach
{
	if (first != NULL)
	{
		Node *p = first;
		first = first->next;
		delete p;
		if (first != NULL)
			first->previous = NULL;
		else
			last = NULL;
		return 1;
	}
	return 0;
}
int Delete_last()// xoa cuoi sanh sach
{
	if (first != NULL)
	{
		Node *p = last;
		last = last->previous;
		if (last != NULL)
			last->next = NULL;
		else
			first = NULL;
		delete p;
		return 1;
	}
	return 0;
}
// Tim X co trong danh sach khong??? Co thi chen Y sau X
Node *Search(int x)
{
	Node *p = first;
	while (p != NULL && p->info != x)
		p = p->next;
	return p;
}
int insert(int x, int y)
{
	Node *q = Search(x);
	if (q != NULL)
	{
		if (q == last)
			Insert_last(y);
		else
		{
			Node *p = new Node;
			p->info = y;
			p->next = q->next;
			(q->next)->previous = p;
			q->next = p;
			p->previous = q;
		}
		return 1;
	}
	return 0;
}
int DeleteX(int x)// tim x sau do xoa x
{
	Node *q = Search(x);
	if (q != NULL)
	{
		if (q == first)
		{
			if (Delete_first())
				return 1;
		}
		else
			if (q == last)
			{
				if (Delete_last())
					return 1;
			}
			else
			{
				(q->previous)->next = q->next;
				(q->next)->previous = q->previous;
				delete q;
			}
		return 1;
	}
	return 0;
}
int main()
{
	int chon;
	char tt;
	do
	{
		system("cls");
		cout << " -------- BAI TAP 12, CHUONG 2 -------- " << endl;
		cout << " 1. Khoi tao danh sach!" << endl;
		cout << " 2. Xuat danh sach!" << endl;
		cout << " 3. Kiem tra co rong hay khong!" << endl;
		cout << " 4. Them vao dau danh sach!" << endl;
		cout << " 5. Them vao cuoi danh sach!" << endl;
		cout << " 6. Xoa dau danh sach!" << endl;
		cout << " 7. Xoa cuoi danh sach!" << endl;
		cout << " 8. Tim X them Y sau X!" << endl;
		cout << " 9. Xoa VT!" << endl;
		cout << " 10. Chon: " << endl;
		cin >> chon;
		switch (chon)
		{
		case 1:
			init();
			cout << "Khoi tao thanh cong\n";
			break;
		case 2:
			cout << "Xuat danh sach:\n";
			Process_list();
			break;
		case 3:
			if (isEmpty())
				cout << "Danh sach rong\n";
			else
				cout << "Danh sach da co Node\n";
			break;
		case 4:
			int n;
			cout << "Gia tri can them vao dau: ";
			cin >> n;
			Insert_first(n);
			break;
		case 5:
			int a;
			cout << "Gia tri can them vao cuoi: ";
			cin >> a;
			Insert_last(a);
			break;
		case 6:
			cout << "Xoa gia tri dau\n " << Delete_first();
			break;
		case 7:
			cout << "Xoa gia tri cuoi\n " << Delete_last();
			break;
		case 8:
			int x, y;
			cout << "Gia tri can tim: ";
			cin >> x;

			if (Search(x) == NULL)
				cout << "Khong tim thay x\n";
			else
			{
				cout << "Gia tri them sau gia tri vua tim thay: ";
				cin >> y;
				cout << "Them gia tri " << y << " sau gia tri " << x << " thanh cong\n" << insert(x, y);
			}
			break;
		case 9:
			cout << "Nhap so can xoa:";
			cin >> x;
			if (DeleteX(x))
				cout << "\n Xoa thanh cong";
			else
				cout << "\n Xoa that bai";
			break;
		}
		cout << "Ban co muon tiep tuc (Y/N): ";
		cin >> tt;
	} while (tt == 'y' || tt == 'Y');
}