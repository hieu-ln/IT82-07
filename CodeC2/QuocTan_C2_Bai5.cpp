//#include <iostream>
//using namespace std;
//#define MAX 100
// 5.2 Khoi tao stack rong
//void init(int a[], int &sp) {
//	sp = -1;
//}
// 5.3 Kiem tra ngan xep rong
//int isEmpty(int a[], int sp) {
//	if(sp == -1)
//		return 1;
//	return 0;
//}
// 5.4 Kiem tra ngan xep day
//int isFull(int a[], int sp) {
//	if(sp == MAX - 1)
//		return 1;
//	return 0;
//}
//5.5 Them phan tu vao ngan xep
//int push(int a[], int &sp, int x) {
//	if(sp < MAX - 1) {
//		a[++sp] = x;
//		return 1;
//	}
//	return 0;
//}
//5.6 Xoa mot phan tu
//int pop(int a[], int &sp, int &x) {
//	if(sp != -1) {
//		x = a[sp--];
//		return 1;
//	}
//	return 0;
//}
//5.7 Output Stack
//void processStack(int a[], int &sp) {
//	for(int i = 0; i < sp + 1; i++)
//		cout << a[i] << "\t";
//	cout << endl;
//}
//int main() {
//	int a[MAX];
//	int choice, sp, x, i;
//	system("cls");
//	cout << "-------------------BAI TAP 5 CHUONG 2, STACK-------------------\n";
//	cout << "1. Khoi tao stack rong\n";
//	cout << "2. Them phan tu vao stack\n";
//	cout << "3. Lay phan tu ra khoi stack\n";
//	cout << "4. Kiem tra stack co day hay khong\n";
//	cout << "5. Kiem tra stack co rong hay khong\n";
//	cout << "6. Xuat stack ra man hinh\n";
//	cout << "7. Thoat\n";
//	do {
//		cout << "Nhap lua chon: ";
//		cin >> choice;
//		switch(choice) {
//		case 1:
//			init(a, sp);
//			cout << "Khoi tao thanh cong\n";
//			break;
//		case 2:
//			cout << "Nhap gia tri x: ";
//			cin >> x;
//			i = push(a, sp, x);
//			cout << "Stack sau khi them: ";
//			processStack(a, sp);
//			break;
//		case 3:
//			i = pop(a, sp, x);
//			cout << "Phan tu vua lay ra khoi stack la: " << x << endl << "Stack sau khi lay la: ";
//			processStack(a, sp);
//			break;
//		case 4:
//			if(isFull(a, sp) == 0)
//				cout << "Stack chua day\n";
//			else
//				cout << "Stack da day\n";
//			break;
//		case 5:
//			if(isEmpty(a, sp) == 0)
//				cout << "Stack khong rong\n";
//			else
//				cout << "Stack rong\n";
//			break;
//		case 6:
//			processStack(a, sp);
//			break;
//		case 7:
//			cout << "Goodbye!\n";
//			break;
//		default:
//			break;
//		}
//	} while(choice != 7);
//	system("pause");
//	return 0;
//}