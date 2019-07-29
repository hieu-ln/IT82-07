#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define MAX 5000
//1.1 Khai bao cau truc danh sach
int a[MAX];
int n;

//1.2a Nhap danh sach ngau nhien
void init(int a[], int &n) {
	cout << "Nhap vao so luong phan tu trong danh sach: ";
	cin >> n;
	for(int i = 0; i < n; i++)
		a[i] = rand() % 10000 + 1;
	cout << "Danh sach da duoc nhap ngau nhien nhu sau:\n";
	for(int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}

//1.2b Nhap danh sach thu cong
void input(int a[], int &n) {
	cout << "Nhap vao so luong phan tu trong danh sach: ";
	cin >> n;
	for(int i = 0; i < n; i++) {
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}	
}

//1.3 Xuat danh sach
void output(int a[], int &n) {
	for(int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
void copyArray(int a[], int b[], int n) {
	for(int i = 0; i < n; i++)
		b[i] = a[i];
}

//1.4 Insertion Sort
void insertionSort(int a[], int n) {
	int i, key, j;
	for(i = 1; i < n; i++) {
		key = a[i];
		j = i - 1;
		while(j >= 0 && a[j] > key) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}	
}

//Ham doi cho 2 so nguyen
void swap(int &u, int &v) {
	int t = u;
	u = v;
	v = t;
}

//1.5 Selection Sort
void selectionSort(int a[], int n) {
	int i, j, min_idx;
	for(i = 0; i < n; i++) {
		min_idx = i;
		for(j = i + 1; j < n; j++)
			if(a[i] < a[min_idx])
				min_idx = j;
		swap(a[min_idx], a[i]);
	}
}

//1.6 Interchange Sort
void interchangeSort(int a[], int n) {
	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++)
			if(a[i] > a[j])
				swap(a[i], a[j]);
}

//1.7 Bubble Sort
void bubbleSort(int a[], int n) {
	int i, j;
	bool haveSwap = false;
	for(i = 0; i < n - 1; i++) {
		for(j = 0; j < n - i - 1; j++) {
			if(a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
				haveSwap = true;
			}
		}
		if(haveSwap == false)
			break;
	}
}

//1.8 Quick Sort
int partition(int a[], int low, int high) {
	int pivot = a[high];
	int left = low;
	int right = high - 1;
	while(1) {
		while(left <= right && a[left] < pivot)
			left++;
		while(right >= left && a[right] > pivot)
			right--;
		if(left >= right)
			break;
	}
	swap(a[left], a[high]);
	return left;
}

void quickSort(int a[], int low, int high) {
	if(low < high) {
		int pi = partition(a, low, high);
		quickSort(a, low, pi - 1);
		quickSort(a, pi + 1, high);
	}
}

//1.9 Heap Sort
void heapify(int a[], int n, int i) {
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if(l < n && a[l] > a[largest])
		largest = l;
	if(r < n && a[r] > a[largest])
		largest = r;
	if(largest != i) {
		swap(a[i], a[largest]);
		heapify(a, n, largest);
	}
}
void heapSort(int a[], int n) {
	for(int i = n / 2 - 1; i >= 0; i--)
		heapify(a, n, i);
	for(int i = n - 1; i >= 0; i--) {
		swap(a[0], a[i]);
		heapify(a, i, 0);
	}
}

//1.10 Tim kiem tuan tu
void searchSequence(int a[], int n, int x) {
	int i = 0;
	while(i < n && a[i] != x)
		i++;
	if(i == n)
		cout << "Khong tim thay\n";
	else
		cout << "Tim thay tai vi tri: " << i << endl;
}

//1.11 tim kiem nhi phan
int binarySearch(int a[], int l, int r, int x) {
	if(r >= l) {
		int mid = l + (r - 1) / 2;
		if(a[mid] == x)
			return mid;
		if(a[mid] > x)
			return binarySearch(a, l, mid - 1, x);
		return binarySearch(a, mid + 1, r, x);
	}
	return -1;
}

int main() {
	int b[MAX];
	clock_t start;
	double duration;
	int choice, x, i;
	system("cls");
	cout << "-------------------BAI TAP 1 CHUONG 3, XEP THU TU VA TIM KIEM-------------------\n";
	cout << "0. Khoi tao danh sach ngau nhien\n";
	cout << "1. Nhap danh sach\n";
	cout << "2. Xuat danh sach\n";
	cout << "3. Selection Sort\n";
	cout << "4. Insertion Sort\n";
	cout << "5. Bubble Sort\n";
	cout << "6. Interchange Sort\n";
	cout << "7. Quick Sort\n";
	cout << "8. Heap Sort\n";
	cout << "9. Tim kiem tuan tu\n";
	cout << "10. Tim kiem nhi phan\n";
	cout << "11. THOAT\n";
	do {
		cout << "Nhap lua chon: ";
		cin >> choice;
		switch(choice) {
		case 0:
			init(a, n);
			break;
		case 1:
			input(a, n);
			break;
		case 2:
			output(a, n);
			break;
		case 3:
			copyArray(a, b, n);
			start = clock();
			selectionSort(b, n);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			if(n < 100) {
				cout << "Danh sach sau khi xep thu tu voi Seclection Sort la:\n";
				output(b, n);
			}
			if(duration > 0)
				cout << "Thoi gian thuc thi: " << duration * 1000000 << "microsecond(s)\n";
			break;
		case 4:
			copyArray(a, b, n);
			start = clock();
			insertionSort(b, n);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			if(n < 100) {
				cout << "Danh sach sau khi xep thu tu voi Insertion Sort la:\n";
				output(b, n);
			}
			if(duration > 0)
				cout << "Thoi gian thuc thi: " << duration * 1000000 << "microsecond(s)\n";
			break;
		case 5:
			copyArray(a, b, n);
			start = clock();
			bubbleSort(b, n);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			if(n < 100) {
				cout << "Danh sach sau khi xep thu tu voi Bubble Sort la:\n";
				output(b, n);
			}
			if(duration > 0)
				cout << "Thoi gian thuc thi: " << duration * 1000000 << "microsecond(s)\n";
			break;
		case 6:
			copyArray(a, b, n);
			start = clock();
			interchangeSort(b, n);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			if(n < 100) {
				cout << "Danh sach sau khi xep thu tu voi Interchange Sort la:\n";
				output(b, n);
			}
			if(duration > 0)
				cout << "Thoi gian thuc thi: " << duration * 1000000 << "microsecond(s)\n";
			break;
		case 7:
			copyArray(a, b, n);
			start = clock();
			quickSort(a, 0, n);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			if(n < 100) {
				cout << "Danh sach sau khi xep thu tu voi Quick Sort la:\n";
				output(b, n);
			}
			if(duration > 0)
				cout << "Thoi gian thuc thi: " << duration * 1000000 << "microsecond(s)\n";
			break;
		case 8:
			copyArray(a, b, n);
			start = clock();
			heapSort(b, n);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			if(n < 100) {
				cout << "Danh sach sau khi xep thu tu voi Heap Sort la:\n";
				output(b, n);
			}
			if(duration > 0)
				cout << "Thoi gian thuc thi: " << duration * 1000000 << "microsecond(s)\n";
			break;
		case 9:
			cout << "Nhap gia tri x: ";
			cin >> x;
			start = clock();
			searchSequence(a, n, x);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			if(duration > 0)
				cout << "Thoi gian thuc thi: " << duration * 1000000 << "microsecond(s)\n";
			break;
		case 10:
			cout << "Nhap gia tri x: ";
			cin >> x;
			start = clock();
			i = binarySearch(a, 0, n, x);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			if(i == -1)
				cout << "Khong tim thay\n";
			else
				cout << "Tim thay x tai vi tri: " << i << endl;
			if(duration > 0)
				cout << "Thoi gian thuc thi: " << duration * 1000000 << "microsecond(s)\n";
			break;
		case 11:
			cout << "Goobbye!\n";
			break;
		default:
			break;
		}
	} while(choice != 11);
	system("pause");
	return 0;
}