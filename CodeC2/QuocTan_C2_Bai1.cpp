#include <iostream>
using namespace std;
//1.1
#define MAX 100
int a[MAX];
int n;
//1.2
void input(int a[], int n) {
	cout << "Nhap n: ";
	cin >> n;
	for(int i = 0; i < n; i++) {
		cout << "Nhap a[" << i << "]: ";
		cin >> a[i];
	}
}
//1.3
void output(int a[], int n) {
	for(int i = 0; i < n; i++)
		cout << a[i] << endl;
}
//1.4
int search(int a[], int n, int x) {
	int i = 0;
	while((i < n) && (a[i] != x))
		i++;
	if(i == n)
		return -1;
	return i;
}
//1.5
void insert_last(int a[], int &n, int x) {
	a[n] = x;
	n++;
}
//1.6
void delete_last(int a[], int &n) {
	n--;
}
//1.7
int delete_i(int a[], int &n, int i) {
	if(i >= 0 && i < n) {
		for(int j = i; j < n - 1; j++)
			a[j] = a[j + 1];
		n--;
		return 1;
	}
	return 0;
}
//1.8
void search_and_delete(int a[], int &n, int z) {
	for(int i = 0; i < n; i++)
		if(i == z)
			delete_i(a, n, i);
}
int main() {
	int choice = 0;
	int x, y;
	system("cls");
	cout << "------------BAI TAP 1, CHUONG 2, DANH SACH DAC------------\n";
	cout << "1. Nhap danh sach" << endl;
	cout << "2. Xuat danh sach" << endl;
	cout << "3. Tim gia tri x trong danh sach" << endl;
	cout << "4. Them phan tu vao cuoi danh sach" << endl;
	cout << "5. Xoa phan tu cuoi danh sach" << endl;
	cout << "6. Xoa phan tu tai vi tri thu i" << endl;
	cout << "7. Tim va xoa" << endl;
	do {
		cout << "Lua chon: ";
		cin >> choice;
		switch(choice) {
		case 1:
			input(a, n);
			cout << "Done!\n";
			break;
		case 2:
			output(a, n);
			cout << "Done!\n";
			break;
		case 3:
			cout << "Nhap gia tri x can tim: ";
			cin >> x;
			if(search(a, n, x) >= 0)
				cout << x << "o vi tri: " << search(a, n, x) << endl;
			else
				cout << "Khong tim thay!\n";
			break;
		case 4:
			cout << "Nhap phan tu can them: ";
			cin >> x;
			insert_last(a, n, x);
			output(a, n);
			break;
		case 5: 
			delete_last(a, n);
			output(a, n);
			break;
		case 6:
			cout << "Nhap vi tri can xoa phan tu: ";
			cin >> y;
			delete_i(a, n, y);
			output(a, n);
			break;
		case 7:
			cout << "Nhap gia tri can tim va xoa: ";
			cin >> x;
			search_and_delete(a, n, x);
			output(a, n);
			break;
		default:
			break;
		}
	} while(choice != 0);
	system("pause");
	return 0;
}