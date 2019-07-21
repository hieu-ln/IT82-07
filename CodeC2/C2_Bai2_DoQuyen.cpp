// Bai 2, chuong 2 
#include <stdio.h>
#include <iostream>

using namespace std;
#define MAX 100
//2.1 Khai bao
int a[MAX];
int n;

//2.0 Nhap danh sach tu dong
void init ( int a[], int &n)
{
	cout<<" Nhap vao so luong phan tu cua danh sach: "<<endl;
	cin>> n;
	for( int i = 0; i <n; i ++)
	{
		a[i] = rand() % 10000 + 1;
	}
	cout<<" Danh sach da duoc nhap ngau nhien nhu sau: "<<endl;
	for( int i =0; i<n; i++)
	{
		cout<< a[i] <<"    ";
	}
	cout<<endl;
}

// 2.2 Them mot phan tu vao danh sach da co thu tu
int Search (int a[], int x, int &n)
{
	int i = 0;
	while(!(x < a[i] && x > a[i-1]))
			i++;
	// da co i, vi tri them, doi cac fan tu sau i wa 1 vitri
	for(int j= n; j>i; j--)
		a[j]=a[j-1];
	n++;
	a[i]=x;
	
	return i;
}

// 2.3 Xuat Danh Sach
void output(int a[], int n )
{
	for (int i = 0; i < n; i ++)
	{
		cout<<a[i]<<"\t";
	}
	cout<<endl;
}

// 2.4 tim kiem tuan tu
int SearchSequence ( int a[], int n, int x)
{
	int i = 0; 
	while (i < n && a[i] != x)
		i ++;
	if (i< n)
		return i;
	return -1;
}

// 2.5 tim kiem nhi phan
int SearchBinary(int a[], int n, int x)
{
	int left = 0, right = n-1, mid;
	while (left <= right)
	{
		mid = (left + right)/2;
		if(a[mid]==x) return mid;
		if(x>a[mid]) left = mid + 1;
		else right = mid-1;
	}
	return -1;
}
// 2.6 Tim va xoa phan tu
int Delete (int a[], int &n, int i)
{
	if(i >= 0 && i < n)
	{
		for ( int j = i ;j < n ; j ++)
			a[j] = a[j+1];
		n--;
		return 1;
	}
	return 0;
}
int searchAndDelete (int a[], int &n , int x)
{
	for ( int i = 0; i < n ; i++)
	{
		if(a[i] == x)
		{
			Delete(a, n ,i );
				return 1;
		}
	}
	return 0;
}

int main()
{
	
	int choice = 0;
	int x, i;
	int m=7;
	system("cls");
	cout<<"----BAI TAP 2, CHUONG 2 : DANH SACH DAT BT LAM THEM-----"<<endl;
	cout<<"0. Khoi tao danh sach ngay nhien "<<endl;
	cout<<"1. Them mot phan tu vao danh sach da co thu tu "<<endl;
	cout<<"2. Xuat danh sach "<<endl;
	cout<<"3. Tim mot phan tu trong danh sach ( tim kiem tuan tu )"<<endl;
	cout<<"4. Tim mot phan tu trong danh sach ( tim kiem nhi phan )"<<endl;
	cout<<"5. Tim mot phan tu va xoa "<<endl;
	cout<<"6. Thoat "<<endl;
	do
	{
		cout<<"Vui long chon so de thuc hien: "<<endl;
		cin>> choice;
		switch (choice)
		{
		case 0:
			init(a, n);
			break;
		case 1:
			cout<<" Vui long nhap gia tri can them: "<<endl;
			cin>>x;
			
			i=Search(a,x,n);
			
			cout<<"i="<<i<<endl;
			output(a, n);
			break;
		case 2:
			cout<<" Danh sach da nhap la: "<<endl;
			output(a, n);
			break;
		case 3:
			cout<<" Vui long nhap x can tim : "<<endl;
			cin>>x;
			i = SearchSequence(a,n, x);
			if( i == -1)
				cout<<" khong tim thay phan tu x= "<<x<<endl;
			else
				cout<<" tim thay x tai vi tri i = "<<i<<endl;
			break;
		case 4:
			cout<<" vui long nhap x can tim : "<<endl;
			cin>>x;
			i = SearchBinary(a, n, x);
			if( i == -1)
				cout<<" khong tim thay phan tu x= "<<x<<endl;
			else
				cout<<" tim thay x tai vi tri i = "<<i<<endl;

	break;
		case 5:
			cout<<" Vui long nhap gia tri can xoa: "<<endl;
			cin>>x;
			i = searchAndDelete(a, n, x);
			if( i == 1)
			{
				cout<<"Xoa thanh cong phan tu x= "<<x<<endl;
				cout<<"Danh sach sau khi xoa la: \n";
				output(a, n);
			}
			else 
				cout<<" Khong co phan tu nao de xoa !"<<endl;
			break;
		case 6:
			cout<<"\n GOODbYE...!"<<endl;
			break;
		
		default:
			break;
		}
	}while (choice != 6);
		system("pause");
		return 0;
}


