#include <iostream>
using namespace std;
#define MAX 100
int n, m;
//1.1 Xuat phan tu thuoc tap hop hai danh sach
void output(int a[], int t) {
	for(int i = 0; i < t; i++)
		cout << a[i] << " ";
	cout << endl;
}
// Thu tuc nhap cac phan tu vao danh sach
void input(int a[], int &t) {
	cout << "Nhap so phan tu tap hop: ";
	cin >> t;
	for(int i = 0; i < t; i++) {
		cout << "Nhap phan tu thu: " << i << ": ";
		cin >> a[i];
	}
}
//1.2 Thu tuc xuat cac phan tu thuoc tap giao cua hai danh sach
void intersection(int a[], int b[], int t, int k) {
	for(int i = 0; i < t; i++)
		for(int j = 0; j < k; j++)
			if(a[j] == b[i])
				cout << a[j] << " ";
	cout << endl;
}
// 1.3 Thu tuc xuat cac phan tu thuoc tap bu cua hai danh sach
void complement(int a[], int b[], int t, int k) {
	bool flag;
	for(int i = 0; i < t; i++) {
		flag = true;
		for(int j = 0; j < k; j++)
			if(a[i] == b[j])
				flag = false;
		if(flag)
			cout << a[i] << " ";
	}
	cout << endl;
}
int main() {
	int arrA[MAX], arrB[MAX], choice;
	system("cls");
	cout << "----------BAI TAP CHUONG 2 BAI TAP 15----------\n";
	cout << "1. Nhap hai danh sach\n";
	cout << "2. Xuat cac phan tu thuoc tap hop hai danh sach\n";
	cout << "3. Xuat cac phan tu thuoc tap giao hai danh sach\n";
	cout << "4. Xuat cac phan tu thuoc tap bu hai danh sach\n";
	cout << "5. Thoat\n";
	do {
		cout << "Nhap lua chon: ";
		cin >> choice;
		switch(choice) {
		case 1:
			input(arrA, n);
			input(arrB, m);
			break;
		case 2:
			cout << "Tap hop danh sach thu 1: ";
			output(arrA, n);
			cout << "Tap hop danh sach thu 2: ";
			output(arrB, m);
			break;
		case 3:
			cout << "Phan tu thuoc tap giao hai danh sach la: ";
			intersection(arrA, arrB, n, m);
			break;
		case 4:
			cout << "Tap A bu B: ";
			complement(arrB, arrA, m, n);
			cout << "Tap B bu A: ";
			complement(arrA, arrB, n, m);
			break;
		case 5:
			cout << "Goodbye!\n";
			break;
		default:
			break;
		}
	} while(choice != 5);
	system("pause");
	return 0;
}