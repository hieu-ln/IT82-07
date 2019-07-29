//Bai 1 - Chuong 3: Xep thu tu, tim kiem
#include <iostream>
#include <stdio.h>
#include <ctime>
using namespace std;

#define MAX 3000
//Cau 1.1
int a[MAX];
int n;

//Cau 1.0:
void init(int a[], int &n)
{
	cout << "Nhap vao so luong phan tu cua danh sach: ";
	cin >> n;
	for(int i = 0; i<n; i++)
	{
		a[i] = rand() % 10000 + 1;
	}
	cout << "Danh sach da duoc nhap ngau nhien nhu sau: \n";
	for(int i=0; i<n; i++)
	{
		cout << a[i] << "\t";
	}
	cout << endl;
}

//Cau 1.2
void input(int a[], int &n)
{
	cout << "Nhap vao so luong phan tu cua danh sach: ";
	cin >> n;
	cout << "Nhap vao cac phan tu cua danh sach:\n";
	for(int i=0; i<n; i++)
	{
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}
}
//Cau 1.3
void output(int a[], int &n)
{
	for(int i=0; i<n; i++)
	{
		cout << a[i] << "\t";
	}
	cout << endl;
}

void CopyArray(int a[], int b[], int n)
{
	for(int i=0; i<n; i++)
	{
		b[i] = a[i];
	}
}

//Cau 1.4
void insertionSort(int a[], int n)
{
	int i, key, j;
	for(i = 1; i<n; i++)
	{
		key=a[i];
		j=i-1;
		while(j>=0 && a[j]>key)
		{
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=key;
	}
}

void swap(int &a, int &b)
{
	int t=a;
	a=b;
	b=t;
}

//Cau 1.5
void selectionSort(int a[], int n)
{
	int i, j, min_idx;
	for(i=0; i<n; i++)
	{
		min_idx=i;
		for(j=i+1; j<n;j++)
			if(a[j]<a[min_idx])
				min_idx=j;
		swap(a[min_idx], a[i]);
	}
}

//Cau 1.6
void interchangeSort(int a[], int n)
{
	for(int i = 0; i< n-1; i++)
		for(int j = i+1; j<n; j++)
			if(a[i] > a[j])
				swap(a[i], a[j]);
}

//Cau 1.7
void bubbleSort(int arr[], int n)
{
	int i, j;
	bool haveSwap = false;
	for(i=0; i<n-1; i++)
	{
		haveSwap = false;
		for(j=0; j<n-i-1; j++)
		{
			if(arr[j]>arr[j+1])
			{
				swap(arr[j], arr[j+1]);
				haveSwap = true;
			}
		}
		if(haveSwap==false)
		{
			break;
		}
	}
}

//Cau 1.8
void quickSort(int a[], int left, int right)
{
	int x = a[(left+right)/2];
	int i = left;
	int j = right;
	while(i < j)
	{
		while(a[i] < x)
			i++;
		while(a[i] >= x)
			j--;
		if(i<=j)
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	if(left < j)
		quickSort(a, left, j);
	if(i < right)
		quickSort(a, i, right);
}

//Cau 1.9
void shift(int a[], int i, int n)
{
	int j = 2*i+1;
	if(j>=n)
		return;
	if(j+1 < n)
		if(a[j]<a[j+1])
			j++;
	if(a[i] >= a[j])
		return;
	else
	{
		int x = a[i];
		a[i] = a[j];
		a[j] = x;
		shift(a, j, n);
	}
}
void heapSort(int a[], int n)
{
	int i = n/2 -1;
	while(i>=0)
	{
		shift(a, i, n);
		i--;
	}
	int right = n-1;
	while(right>0)
	{
		swap(a[0], a[right]);
		right--;
		if(right >0)
			shift(a, 0, right);
	}
}

//Cau 1.10
int searchSequence(int a[], int n, int x)
{
	int i=0;
	while(i<n && a[i] != x)
	{
		i++;
	}
	if(i==n)
		return -1;
	else
		return i;
}

//Cau 1.11
int searchBinary(int a[], int l, int r, int x)
{
	if(r>=1)
	{
		int mid = 1+(r-1)/2;
		if(a[mid]==x)
			return mid;
		if(a[mid]>x)
			return searchBinary(a, l, mid-1, x);
		return searchBinary(a, mid+1, r, x);
	}
	return -1;
}

int main()
{
	int b[MAX];
	clock_t start;
	double duration;
	int choice, x, i;
	system("cls");
	cout << "----------BAI TAP 1, CHUONG 3, XEP THU TU VA TIM KIEM----------\n";
	cout << "0. Khoi tao danh sach ngau nhien\n";
	cout << "1. Nhap danh sach\n";
	cout << "2. Xuat danh sach\n";
	cout << "3. Selection Sort\n";
	cout << "4. Insertion Sort\n";
	cout << "5. Bubble Sort\n";
	cout << "6. Interchange Sort\n";
	cout << "7. Quick Sort\n";
	cout << "8. Heap Sort\n";
	cout << "9. Tim kiem phan tu x bang TIM KIEM TUAN TU\n";
	cout << "10. Tim kiem phan tu x bang TIM KIEM NHI PHAN\n";
	cout << "11. Thoat\n";
	do{
		cout << "\nVui long chon so de thuc hien: ";
		cin >> choice;
		switch(choice)
		{
		case 0:
			init(a,n);
			break;
		case 1:
			input(a,n);
			break;
		case 2:
			cout << "Danh sach la: \n";
			output(a, n);
			break;
		case 3:
			CopyArray(a, b, n);
			start = clock();
			selectionSort(b, n);
			duration = (clock() - start)/(double) CLOCKS_PER_SEC;
			if(n<100)
			{
				cout << "DS sau khi sap xep SELECTION SORT la: \n";
				output(b,n);
			}
			if(duration>0)
				cout << "Thoi gian SELECTION SORT: "<< duration* 1000000 << " Microseconds";
			break;
		case 4:
			CopyArray(a, b, n);
			start = clock();
			insertionSort(b, n);
			duration = (clock() - start)/(double) CLOCKS_PER_SEC;
			if(n<100)
			{
				cout << "DS sau khi sap xep INSERTION SORT la: \n";
				output(b,n);
			}
			if(duration>0)
				cout << "Thoi gian INSERTION SORT: "<< duration* 1000000 << " Microseconds";
			break;
		case 5:
			CopyArray(a, b, n);
			start = clock();
			bubbleSort(b, n);
			duration = (clock() - start)/(double) CLOCKS_PER_SEC;
			if(n<100)
			{
				cout << "DS sau khi sap xep BUBBLE SORT la: \n";
				output(b,n);
			}
			if(duration>0)
				cout << "Thoi gian BUBBLE SORT: "<< duration* 1000000 << " Microseconds";
			break;
		case 6:
			CopyArray(a, b, n);
			start = clock();
			interchangeSort(b, n);
			duration = (clock() - start)/(double) CLOCKS_PER_SEC;
			if(n<100)
			{
				cout << "DS sau khi sap xep INTERCHANGE SORT la: \n";
				output(b,n);
			}
			if(duration>0)
				cout << "Thoi gian INTERCHANGE SORT: "<< duration* 1000000 << " Microseconds";
			break;
		case 7:
			CopyArray(a, b, n);
			start = clock();
			quickSort(b,0, n);
			duration = (clock() - start)/(double) CLOCKS_PER_SEC;
			if(n<100)
			{
				cout << "DS sau khi sap xep QUICK SORT la: \n";
				output(b,n);
			}
			if(duration>0)
				cout << "Thoi gian QUICK SORT: "<< duration* 1000000 << " Microseconds";
			break;
		case 8:
			CopyArray(a, b, n);
			start = clock();
			heapSort(b, n);
			duration = (clock() - start)/(double) CLOCKS_PER_SEC;
			if(n<100)
			{
				cout << "DS sau khi sap xep HEAP SORT la: \n";
				output(b,n);
			}
			if(duration>0)
				cout << "Thoi gian HEAP SORT: "<< duration* 1000000 << " Microseconds";
			break;
		case 9:
			cout << "Vui long nhap gia tri x = ";
			cin >> x;
			start = clock();
			i = searchSequence(a, n, x);
			if(i==-1)
				cout << "Khong tim thay x = "<< x << "trong mang!\n";
			else
				cout << "Tim thay x = " << x << "tai vi tri i = " << i << "\n";
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			if(duration>0)
				cout << "Thoi gian tim kiem TUAN TU la: "<< duration* 1000000 << " Microseconds";
			break;
		case 10:
			cout << "Vui long nhap gia tri x = ";
			cin >> x;
			start = clock();
			i = searchBinary(b, 0, n, x);
			if(i==-1)
				cout << "Khong tim thay x = "<< x << "trong mang!\n";
			else
				cout << "Tim thay x = " << x << "tai vi tri i = " << i << "\n";
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			if(duration>0)
				cout << "Thoi gian tim kiem NHI PHAN la: "<< duration* 1000000 << " Microseconds";
			break;
		case 11:
			cout << "\nGood bye!!\n";
			break;
		default:
			break;
		}
	}while(choice!=11);
	system("pause");
	return 0;
}