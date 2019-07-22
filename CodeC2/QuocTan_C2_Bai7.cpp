//#include <iostream>
//using namespace std;
//#define MAX 100
////7.2: Khoi tao queue rong
//void init(int a[], int &front, int &rear) {
//	front = -1;
//	rear = -1;
//}
////7.3 Kiem tra queue rong
//int isEmpty(int a[], int &front, int &rear) {
//	if(front == rear)
//		return 1;
//	return 0;
//}
////7.4 Kiem tra queue day
//int isFull(int a[], int &front, int &rear) {
//	if(rear - front == MAX - 1)
//		return 1;
//	return 0;
//}
////7.5 Them phan tu vao queue
//int push(int a[], int &front, int &rear, int x) {
//	if(rear - front == MAX - 1)
//		return 0;
//	else {
//		if(front == -1)
//			front = 0;
//		if(front == MAX - 1) {
//			for(int i = front; i <= rear; i++)
//				a[i - front] = a[i];
//			rear = MAX - 1 - front;
//			front = 0;
//		}
//		a[++rear] = x;
//		return 1;
//	}
//	return 0;
//}
////7.6 Lay mot phan tu ra khoi queue
//int pop(int a[], int &front, int &rear, int&x) {
//	if(front = -1)
//		return 0;
//	else {
//		x = a[front++];
//		if(front > rear) {
//			front = -1;
//			rear = -1;
//		}
//		return 1;
//	}
//	return 0;
//}
//// Xuat queue ra man hinh
//void processQueue(int a[], int f, int r) {
//	cout << "f = " << f << "; r = " << r << endl;
//	if(f < r && f != -1) {
//		for(int i = f; i < (r + 1); i++)
//			cout << a[i] << " ";
//		cout << " <--" << endl;
//	}
//}
//int main() {
//	/*int a[MAX];
//	int choice, f, r, x, i;
//	system("cls");
//	cout << "-------------BAI TAP 7 CHUONG 2, QUEUE-------------\n";
//	cout << "1. Khoi tao queue rong\n";
//	cout << "2. Them phan tu vao queue\n";
//	cout << "3. Lay phan tu ra khoi queue\n";
//	cout << "4. Kiem tra queue co day hay khong\n";
//	cout << "5. Kiem tra queue co rong hay khong\n";
//	cout << "6. Xuat queue ra man hinh\n";
//	cout << "7. Thoat\n";
//	do {
//		cout << "Nhap lua chon: ";
//		cin >> choice;
//		switch(choice) {
//		case 1:
//			init(a, f, r);
//			cout << "Khoi tao thanh cong\n";
//			break;
//		case 2:
//			cout << "Nhap gia tri x: ";
//			cin >> x;
//			i = push(a, f, r, x);
//			cout << "Queue sau khi them: ";
//			processQueue(a, f, r);
//			break;
//		case 3:
//			i = pop(a, f, r, x);
//			cout << "Phan tu duoc lay ra la: " << x << endl << "Queue sau khi lay: ";
//			processQueue(a, f, r);
//			break;
//		case 4:
//			if(isFull(a, f, r))
//				cout << "Queue day\n";
//			else
//				cout << "Queue chua day\n";
//			break;
//		case 5:
//			if(isEmpty(a, f, r))
//				cout << "Queue rong\n";
//			else
//				cout << "Queue chua rong\n";
//			break;
//		case 6:
//			processQueue(a, f, r);
//			break;
//		case 7:
//			cout << "Goodbye\n";
//			break;
//		default:
//			break;
//		}
//	} while(choice != 7);
//	system("pause");
//	return 0;*/
//}