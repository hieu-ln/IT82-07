//#include <iostream>
//using namespace std;
////11.1 Khai bao cau truc queue
//struct Node {
//	int info;
//	Node *link;
//};
//Node *front, *rear;
////11.2 Khoi tao queue rong
//void init() {
//	front = NULL;
//	rear = NULL;
//}
////11.3 Kiem tra queue rong
//int isEmpty() {
//	if(front == NULL)
//		return 1;
//	return 0;
//}
////11.4 Them phan tu vao queue
//void push(int x) {
//	Node *p = new Node;
//	p->info = x;
//	p->link = NULL;
//	if(rear == NULL)
//		front = p;
//	else
//		rear->link = p;
//	rear = p;
//}
////11.5 Lay phan tu ra khoi queue
//int pop(int &x) {
//	if(front != NULL) {
//		Node *p = front;
//		front = p->link;
//		x = p->info;
//		if(front == NULL)
//			rear = NULL;
//		delete p;
//		return 1;
//	}
//	return 0;
//}
////Xuat queue
//void processQueue() {
//	if(front != NULL) {
//		Node *p = front;
//		cout << "<-- ";
//		do {
//			cout << p->info << " ";
//			p = p->link;
//		} while(p != NULL);
//		cout << endl;
//	}
//}	
//int main() {
//	int choice, x, i;
//	system("cls");
//	cout << "-------------BAI TAP 11 CHUONG 2, QUEUE LINKED LIST-------------\n";
//	cout << "1. Khoi tao queue rong\n";
//	cout << "2. Them phan tu vao queue\n";
//	cout << "3. Lay phan tu ra khoi queue\n";
//	cout << "4. Kiem tra queue co rong hay khong\n";
//	cout << "5. Xuat queue\n";
//	cout << "6. Thoat\n";
//	do {
//		cout << "Nhap lua chon: ";
//		cin >> choice;
//		switch(choice) {
//		case 1:
//			init();
//			cout << "Khoi tao queue thanh cong\n";
//			break;
//		case 2:
//			cout << "Nhap gia tri x: ";
//			cin >> x;
//			push(x);
//			cout << "Queue sau khi them: ";
//			processQueue();
//			break;
//		case 3:
//			pop(x);
//			cout << "Phan tu lay ra khoi queue la: " << x << "\nQueue sau khi lay ra la: ";
//			processQueue();
//			break;
//		case 4:
//			if(isEmpty())
//				cout << "Queue rong\n";
//			else
//				cout << "Queue khong rong\n";
//			break;
//		case 5:
//			cout << "Queue hien tai la: ";
//			processQueue();
//			break;
//		case 6:
//			cout << "Goodbye\n";
//			break;
//		default:
//			break;
//		}
//	} while(choice != 6);
//	system("pause");
//	return 0;
//}