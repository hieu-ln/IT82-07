//#include <iostream>
//using namespace std;
//10.1 Khai bao cau truc stack
//struct Node {
//	int info;
//	Node *link;
//};
//Node *sp;
//10.2 Khoi tao stack rong
//void init() {
//	sp = NULL;
//}
//10.3 Kiem tra stack rong
//int isEmpty() {
//	if(sp == NULL)
//		return 1;
//	return 0;
//}
//10.4 Them phan tu vao stack
//void push(int x) {
//	Node *p = new Node;
//	p->info = x;
//	p->link = sp;
//	sp = p;
//}
//10.5 Lay phan tu ra khoi stack
//int pop(int &x) {
//	if(sp != NULL) {
//		Node *p = sp;
//		x = p->info;
//		sp = p->link;
//		delete p;
//		return 1;
//	}
//	return 0;
//}
//Xuat stack
//void processStack() {
//	Node *p = sp;
//	do {
//		cout << p->info << " ";
//		p = p->link;
//	} while(p != NULL);
//	cout << endl;
//}
//int main() {
//	int choice, x, i;
//	system("cls");
//	cout << "-------------BAI TAP 10 CHUONG 2, STACK LINKED LIST-------------\n";
//	cout << "1. Khoi tao stack rong\n";
//	cout << "2. Them phan tu vao queue\n";
//	cout << "3. Lay phan tu ra khoi queue\n";
//	cout << "4. Xuat stack\n";
//	cout << "5. Thoat\n";
//	do {
//		cout << "Nhap lua chon: ";
//		cin >> choice;
//		switch(choice) {
//		case 1:
//			init();
//			cout << "Khoi tao stack thanh cong\n";
//			break;
//		case 2:
//			cout << "Nhap gia tri x: ";
//			cin >> x;
//			push(x);
//			cout << "Stack sau khi them: ";
//			processStack();
//			break;
//		case 3:
//			pop(x);
//			cout << "Phan tu lay ra khoi stack la: " << x << "\nStack sau khi lay ra la: ";
//			processStack();
//			break;
//		case 4:
//			cout << "Stack hien tai la: ";
//			processStack();
//			break;
//		case 5:
//			cout << "Goodbye\n";
//			break;
//		default:
//			break;
//		}
//	} while(choice != 5);
//	system("pause");
//	return 0;
//}