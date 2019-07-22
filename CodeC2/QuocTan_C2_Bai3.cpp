#include <iostream>
#include <cstdlib>
using namespace std;
//3.1
 struct Node {
	int info;
	Node *link;
 };
 Node *first;
//3.2
void Init() {
	first = NULL;
}
//3.3
void processList() {
	Node *p;
	p = first;
	while(p != NULL) {
		cout << p->info << "\t";
		p = p->link;
	}
	cout << endl;
}
//3.4
Node *search(int x) {
	Node *p = first;
	while((p != NULL) && (p->info != x))
		p = p->link;
	return p;
}
//3.5
void insertFirst(int x) {
	Node *p;
	p = new Node;
	p->info = x;
	p->link = first;
	first = p;
}
//3.6
int deleteFirst() {
	if(first != NULL) {
		Node *p = first;
		first = first->link;
		delete p;
		return 1;
	}
	return 0;
}
//3.7
void insertLast(int x) {
	Node *p;
	p = new Node;
	p->info = x;
	p->link = NULL;
	if(first == NULL)
		first = p;
	else {
		Node *q = first;
		while(q->link != NULL)
			q = q->link;
		q->link = p;
	}
}
//3.8
int deleteLast() {
		if(first != NULL) {
		Node *p, *q;
		p = first;
		q = NULL;
		if(p != NULL)
			while(p->link != NULL) {
				q = p;
				p = p->link;
			}
			if(p != first)
				q->link = NULL;
			else
				first = NULL;
			delete p;
			return 1;
		} return 0;
}
//3.9
int searchAndDelete(int x) {
	if(first != NULL) {
		Node *p, *q;
		p = first;
		q = first;
		while(p->info != x) {
			q = p;
			p = p->link;
		}
		if(p != first && p != NULL) {
			if(p->link != NULL)
				q->link = p->link;
			else
				q->link = NULL;
			delete p;
			return 1;
		}
		else 
			if(p == first) {
			first = p->link;
			delete p;
			return 1;
		}
			else
				return 0;
	}
	return 0;
}
//3.10
void sort() {
	Node *p, *q, *min;
	p = first;
	while(p != NULL) {
		if(q->info < min->info)
			min = q;
		q = q->link;
	}
	swap(min, p);
	p = p->link;
}
int main() {
	int choice = 0;
	int x, i;
	Node *p;
	system("cls");
	cout << "------------BAI TAP 3, CHUONG 2, DANH SACH LIEN KET------------\n";
	cout << "1. Khoi tao DSLK don rong" << endl;
	cout << "2. Them phan tu vao dau danh sach" << endl;
	cout << "3. Them phan tu vao cuoi danh sach" << endl;
	cout << "4. Xoa phan tu dau danh sach" << endl;
	cout << "5. Xoa phan tu cuoi danh sach" << endl;
	cout << "6. Xuat danh sach" << endl;
	cout << "7. Tim mot phan tu gia tri x" << endl;
	cout << "8. Tim phan tu co gia tri x va xoa no" << endl;
	cout << "9. Sap xep danh sach tang dan" << endl;
	cout << "10. Sap xep danh sach giam dan" << endl;
	cout << "11. Thoat" << endl;
	do {
		cout << "Lua chon: ";
		cin >> choice;
		switch(choice) {
		case 1:
			Init();
			cout << "Tao danh sach thanh cong\n";
			break;
		case 2:
			cout << "Nhap x: ";
			cin >> x;
			insertFirst(x);
			cout << "Done!\n";
			break;
		case 3:
			cout << "Nhap x: ";
			cin >> x;
			insertLast(x);
			cout << "Done";
			break;
		case 4:
			i = deleteFirst();
			if(i)
				cout << "Unsuccessful\n";
			else
				cout << "Successful\n";
			break;
		case 5: 
			i = deleteLast();
			if(i)
				cout << "Unsuccessful\n";
			else
				cout << "Successful\n";
			break;
		case 6:
			processList();
			break;
		case 7:
			cout << "Nhap x: ";
			cin >> x;
			p = search(x);
			if(p != NULL)
				cout << "Tim thay x\n";
			else
				cout << "Khong tim thay x\n";
			break;
		case 8: 
			cout << "Nhap x: ";
			cin >> x;
			i = searchAndDelete(x);
			if(i)
				cout << "Successful\n";
			else
				cout << "Unsuccessful\n";
			break;
		default:
			break;
		}
	} while(choice != 0);
	system("pause");
	return 0;
}