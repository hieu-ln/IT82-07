#include <stdio.h>
#include <iostream>
#include <ctime>
#include <math.h>
using namespace std;

#define MAX 2000
// khoi taoo danh sach ngau nhien

void init(int a[], int &n)
{
	cout<<"Nhap vao so luong phan tu cua danh sach:"<<endl;
	cin>>n;
	for (int i=0; i<n; i++)
	{
		a[i]=rand() %10000 +1;

	}
	cout<<"Danh sach da duoc nhap ngau nhien nhu sau"<<endl;
	for(int i=0; i<n; i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;

}
//Cau 1.1: Khai bao cau truc danh sach
int a[MAX];
int n;

// Cau 1.2: Viet thu tuc nhap danh sach 
void input(int a[], int &n)
{
	cout<<"Nhap vao so luong phan tu cua danh sach:"<<endl;
	cin>>n;
	cout<<"Nhap vao cac phan tu cua danh sach:"<<endl;
	for(int i=0; i<n; i++)
	{
		cout<<"a["<<i<<"]"<<endl;
		cin>>a[i];
	}
	
}

// cau 1.3: Viet thu tuc xuat danh sach
void output(int a[], int n)
{
	for (int i=0; i<n; i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

void CoppyArray(int a[], int b[], int n)
{
	for (int i=0; i<n; i++)
	{
		b[i]=a[i];
	}
}

// 1.4: viet thu tuc sap xep danh sach theo thu tu tang dan bang thuat toan selectionsort. Danh gia do phuc tap cua thuat toan

// ham doi cho
void swap(int &a, int &b)
{
	int tempt=a;
	a=b;
	tempt=b;
}





void SelectionSort(int a[], int n)
{
	int i,j, min;
	for(i=0; i<n-1; j=i++)
	{
		min=i; // tim phan tu nho nhat trong mang
		for(j=i+1;j<n;j++)
		{
			if( a[j]<a[min])
				min=j;
		}
		// doi cho phan tu nho nhat voi phan tu dau tien
		swap(a[min], a[i]);
	}
}
// do phuc tap cua thuat toan . Xet chuong trinh co 2 vong lap for.
// Vong for thu nhat, truong hop xau nhat bang n-1. -> Do phuc tap O(n)
// Vong for thu hai, truong hop xau nhat bang n. -> Do phuc tap O(n)
// => Do phuc tap thuat toan la O(n^2)


//1.5: Viet  thu tic sap xep danh sach theo thu tu tan dan bang thuat toan InserctionSort. Danh gia do phuc tap cua thua toan
void InsertionSort( int a[], int n)
{
	int i, key, j;
	for (i=1; i<n; i++)
	{
		key=a[i];
		j=i-1;

		while ( i>=0 && a[j] >key) // di chuyen cac phan tu có gia tri lon hon gia tri key ve sau mot vi tri so voi vi tri ban dau cua no
		{
			a[j+1]=a[j];
			j=j+1;
		}
		a[j+1]=key;
	}
}
// Do phuc tap cua thuat toan. Co 1 vòng for, trương hop xau nhat  bang n. =>Do phuc tap cua chuong trinh O(n)



// 1.6 Viet thu tuc sap xep danh sach theo thu tu tang dan bang thuat toan InterchangSort. Danh gia do phuc tap cua thuat toan
void InterchangSort(int a[], int n)
{
	for(int i=0; i<n; i++)
	{
		for(int j=i+1; j<n; j++)
			if(a[i]>a[j])
				swap(a[i],a[j]);
	}
}
// Do phuc tap cua thuat toan. Co 2 vong for. 
// Vong for 1. truong hop xau nhat bang n.=>Do phuc tap O(n)
// Vong for 2. truong hop xuau nhat bang n. -> Do phuc tap O(n)
//=> Do phuc tap thuat toan O(n^2)

//1.7 Viet thu tuc sap xep danh sach theo thu tu tang dan bang thuat toan BubbleSort. Danh gia do phuc tap cua thuat toan
void BubbleSort(int a[], int n)
{
	for (int i=0; i<n; i++)
	{
		for (int j=0; j =n-1; j--)
			if(a[j-1]>a[i])
				swap(a[j],a[j-1]);
	}

}
//Vong for 1. truong hop xau nhat bang n.=>Do phuc tap O(n)
// Vong for 2. truong hop xuau nhat bang n-1. -> Do phuc tap O(n)
//=> Do phuc tap thuat toan O(n^2)

//1.8: Viet thu tuc sap xep danh sach theo thu tu tang dan bang thuat toan QuickSort. Danh gia do phuc tap cua thuat toan
void QuickSort(int a[], int left, int right)
{
	
	int x=a[(left+right)/2];
	int i=left;
	int j=right;
	while (i<j)
	{
		while (a[i]<x)
			i++;
		while (a[j]>x)
			j--;
		if(i<=j)
		{
			swap(a[i],a[j]); // doi cho
			i++;
			j--;
		}

	}
	if(left<j)
		QuickSort( a,left,j);
	if(i<right)
		QuickSort(a,i,right);



}

//1.9: Viet thu tuc sap xep danh sach theo thu tu tang dan bang thuat toan HeapSort. Danh gia do phuc tap cua thuat toan
void shift(int a[], int i, int n)
{
	int j=2*i+1;
	if(j>=n)
		return;
	if(j+1<n)
		if(a[j]<a[j+1])
			j++;
	if(a[i]>=a[j])
		return;
	else
	{
		int x=a[i];
		a[i]=a[j];
		a[j]=x;
		shift(a,j,n);
	}
}

void HeapSort(int a[], int n)
{
	int i=n/2-1;
	while(i>=0)
	{
		shift(a,i,n);
		i--;
	}
	int right = n-1;
	while (right >0)
	{
		swap(a[0], a[right]);
		right --;
		if(right >0)
			shift(a,0,right);
	}
}

//1.10 Viet thu tuc tim kiem mot phan tu trong danh ach thu tu (dung phuong phap tim kiem tuan tu). Danh gia do phuc tap cua thuat toan
int searchSequence (int a[], int n, int x)
{
	int i=0;
	while(i<n && a[i] !=x)
	{
		i++;
	}
	if (i==n)
		return -1;
	else
		return i;
}

// 1.11  Viet thu tuc tim kiem mot phan tu trong danh ach thu tu (dung phuong phap tim kiem nhi phan). Danh gia do phuc tap cua thuat toan
int searchBinary(int a[], int l, int r, int x)
{
	if(r>=1)
	{
		int mid=l+(r-1)/2;
		if(a[mid]==x)
			return mid;
		if(a[mid]>x)
			return searchBinary(a,l,mid-1,x);
		return searchBinary(a,mid+1,r,x);

	}
	return -1;
}

int main()
{
	int b[MAX];
	clock_t start;
	double duration;
	int choice,x,i;
	double CLOCK_PER_SEC;
	system("cls");
	cout <<"0. Khoi tao danh sach:"<<endl;
	cout<<"1. Nhap danh sach:"<<endl;
	cout<<"2.Xuat danh sach:"<<endl;
	cout<<"3. Xep thu tu bang SelectionSort"<<endl;
	cout<<"4. Xep thu tu bang InsertionSort"<<endl;
	cout<<"5.Xep thu tu bang BubbleSort"<<endl;
	cout<<"6.Xep thu tu bang InterchangeSort"<<endl;
	cout<<"7.Xep thu tu bang QuickSort"<<endl;
	cout<<"8.Xep thu tu bang HeapSort"<<endl;
	cout<<"9.Tim kiem phan tu x bang tim kiem tuan tu "<<endl;
	cout<<"10.Tim kiem phan tu x bang tim kiem nhi phan "<<endl;
	cout<<"11.Thoat"<<endl;

	do
	{
		cout<<"Chon buoc thuc hien:"<<endl;
		cin>>choice;
		switch(choice)
		{
		case 0: // khoi tao random
			init(a,n);
			break;
		case 1: 
			input(a,n);
			break;
		case 2: 
			cout<<"Danh sach la:"<<endl;
			output(a,n);
			break;
		case 3: 
			CoppyArray(a,b,n);
			start=clock();
			SelectionSort(b,n);
			duration=(clock()-start)/ CLOCK_PER_SEC;
			if (n<100)
			{
				cout <<"DS sau khi xep thu tu bang Seletion:"<<endl;
				output(b,n);
			}
			if(duration >0)
				cout<<"Thoi gian SelectionSort:"<<duration*10000000 <<"Microseconds"<<endl;
			break;
		case 4:
			CoppyArray(a,b,n);
			start = clock();
			InsertionSort(b,n);
			duration=(clock()-start)/ CLOCK_PER_SEC;
			if (n<100)
			{
				cout <<"DS sau khi xep thu tu bang Seletion:"<<endl;
				output(b,n);
			}
			if(duration >0)
				cout<<"Thoi gian InsertionSort:"<<duration*10000000 <<"Microseconds"<<endl;
			break;
		case 5:
			CoppyArray(a,b,n);
			start = clock();
			BubbleSort(b,n);
			duration=(clock()-start)/ CLOCK_PER_SEC;
			if (n<100)
			{
				cout <<"DS sau khi xep thu tu bang Seletion:"<<endl;
				output(b,n);
			}
			if(duration >0)
				cout<<"Thoi gian BubbleSort:"<<duration*10000000 <<"Microseconds"<<endl;
			break;
		case 6: 
			CoppyArray(a,b,n);
			start = clock();
			InterchangSort(b,n);
			duration=(clock()-start)/ CLOCK_PER_SEC;
			if (n<100)
			{
				cout <<"DS sau khi xep thu tu bang Seletion:"<<endl;
				output(b,n);
			}
			if(duration >0)
				cout<<"Thoi gian InterchangeSort:"<<duration*10000000 <<"Microseconds"<<endl;
			break;
		case 7:
			CoppyArray(a,b,n);
			start = clock();
			QuickSort(b,0,n-1);
			duration=(clock()-start)/ CLOCK_PER_SEC;
			if (n<100)
			{
				cout <<"DS sau khi xep thu tu bang Seletion:"<<endl;
				output(b,n);
			}
			if(duration >0)
				cout<<"Thoi gian QuickSort:"<<duration*10000000 <<"Microseconds"<<endl;
			break;
		case 8:
			CoppyArray(a,b,n);
			start=clock();
			HeapSort(b,n);
			duration=(clock()-start)/ CLOCK_PER_SEC;
			if (n<100)
			{
				cout <<"DS sau khi xep thu tu bang Seletion:"<<endl;
				output(b,n);
			}
			if(duration >0)
				cout<<"Thoi gian HeapSort:"<<duration*10000000 <<"Microseconds"<<endl;
			break;
		case 9: 
			cout<<"Nhap gia tri tim x:"<<endl;
			cin>>x;
			start=clock();
			i=searchSequence(a,n,x);
			if (i == -1)
				cout<<"Khong tim thay x = "<<x<<" trong danh sach! "<<endl;
			else 
				cout<<"Tim thay x = "<<x<<" tai vi tri i = "<<i<<endl;
			duration=(clock()-start)/ CLOCK_PER_SEC;
			if (n<100)
			{
				cout <<"DS sau tim kiem bang tuan tu:"<<endl;
				output(b,n);
			}
			if(duration >0)
				cout<<"Thoi gian tim kiem tuan tu:"<<duration*10000000 <<"Microseconds"<<endl;
			break;
		case 10:
			cout<<"Nhap gia tri tim x:"<<endl;
			cin>>x;
			start=clock();
			i=searchBinary(b,0,n,x);

			if (i == -1)
				cout<<"Khong tim thay x = "<<x<<" trong danh sach! "<<endl;
			else 
				cout<<"Tim thay x = "<<x<<" tai vi tri i = "<<i<<endl;
			duration=(clock()-start)/ CLOCK_PER_SEC;
			if (n<100)
			{
				cout <<"DS sau tim kiem bang nhi phan:"<<endl;
				output(b,n);
			}
			if(duration >0)
				cout<<"Thoi gian tim kiem nhi phan:"<<duration*10000000 <<"Microseconds"<<endl;
			break;
		case 11:
			cout<<"exit"<<endl;
			break;
		default:
			break;

		}
	}while (choice!=11);
	system("pause");
	return 0;
}