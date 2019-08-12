#include <iostream>
#include <stdio.h>
#include <fstream>
#include <iomanip>
#include <set>
#include <conio.h>
#include <wmsnamedvalues.h>



using namespace std;
#define MAX 100


int a[MAX][MAX];
int n;// so dinh cua do thi
char vertex[MAX];  // ten dinh
void InitGraph()
{
	n=0;
}


// nhap ma tran ke cua do thi
void intGraph()
{
	cout<<"Nhap so dinh cua do thi n:";
	cin>>n;
	cout<<"Nhap ten dinh : ";
	for(int i=0; i<n;i++)
		cin>>vertex[i];
	for (int i=0;i<n; i++)
	{
		cout<<"Nhap vao dong thu"<<i+1<<" : ";
		for(int j=0; j<n; j++)
			cin>>a[i][j];
	}
}

// xuat ma tran ke cua do thi
void outGraph()
{
	cout<<setw(5)<<left;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout<<a[i][j]<<setw(5)<<left;
		cout<<endl;
	}
}

// krukal

struct Edge 
{
	int x,y;
};
void Kruskal(int **a, int n)
{
	int *D=new int[n];
	Edge*L=new Edge[n-1];
	int min=MAXINT, Dem=0, Sum=0, T=0, temp;
	for (int i=0;i<n;i++)
		D[i]=0;
	do{
		min=MAXINT;
		for (int i=0;i<n;i++)
			for (int j=0; j<n; j++)
				if(a[i][j]>0 && min>a[i][j] && !(D[i]!=0 && D[i]==D[j]))
			{
				min =a[i][j];
				L[Dem].x=i;
				L[Dem].y=j;

			}
			if(D[L[Dem].x]==0 && D[L[Dem].y]!=0)
			{
				T++;
				D[L[Dem].x]=D[L[Dem].y]=T;
			}
			if(D[L[Dem].x]==0 && D[L[Dem].y]==0)
			{
				D[L[Dem].x]=D[L[Dem].y];
			}
			if(D[L[Dem].x]!=D[L[Dem].y] && D[L[Dem].y]!=0)
			{
				temp=D[L[Dem].x];
				for(int i=0; i<n;i++)
					if(temp==D[i])
						D[i]=D[L[Dem].y];

			}
			Sum+=min;
			Dem++;
	}while(Dem<n-1);

}
int w[500], dau[500],cuoi[500], father[50];
int n,m,minl,connect;
int dt[], ct[];
void Heap( int First, int Last)
{
	int j,k,t1,t2,t3;
	j=First;
	while (j<=(Last/2))
	{
		if((2*j)<Last && w[2*j+1]<w[2*j])
			k=2*j+1;
		else
			k=2*j+1;
		if(w[k]<w[j])
		{
			t1=dau[j];
			t2=cuoi[j];
			t3=w[j];
			dau[j]=dau[k];
			cuoi[j]=cuoi[k];
			w[j]=w[k];
			dau[k]=t1;
			cuoi[k]=t2;
			w[k]=t3;
			j=k;
		}
		else j=Last;
	}
}

int Find(int i)
{
	int tro=i;
	while (father[tro]>0)
		tro=father[tro];
	return(tro);
}

void Uni(int i, int j)
{
	int x=father[i] + father[j];
	if(father[i]>father[j])
	{
		father[i]=j;
		father[j]=x;
	}
	else
	{
		father[j]=i;
		father[i]=x;
	}
}

void Kruskal()
{
	int last, u, v, r1,r2, ncanh, ndinh;
	for(int i=1; i<=n;i++)
		father[i]=-1;
	// thuat toan vun đống
	for(int i=m/2;i>0;i--)
		Heap(i,m);
	last=m; ncanh=0; ndinh=0; minl=0; connect=True;
	// chọn cạnh bổ xung vào cây khung
	while(ndinh<n-1 && ncanh<m)
	{
		ncanh=ncanh+1;
		u=dau[1];
		v=cuoi[1];
		// tìm phân hoạch 1
		r1=Find(u);
		// tìm phân hoạch 2
		r2=Find(v);
		if(r1!=r2)
		{
			ndinh=ndinh+1;
			Uni(r1,r2);
			dt[ndinh]=u;
			ct[ndinh]=v;
			minl=minl+w[1];

		}
		dau[1]=dau[last];
		cuoi[1]=cuoi[last];
		w[1]=w[last];
		last=last-1;
		Heap(1,last);
	}
	if(ndinh!=n-1)
		connect=FALSE;

}

void Result()
{
	cout<<"Do dai cay khung nho nhat:"<<minl<<endl;
	cout<<"Cac canh cua cay khung nho nhat:"<<endl;
	for(int i=1; i<n;i++)
		cout<<dt[i]<<" "<<ct[i]<<endl;
}

int main()
{
	int choice,x,i;
	system("cls");
	cout<<" ----- Bai tap 4, Chuong 6------"<<endl;
	cout<<"1. Khoi tao MA TRAN KE rong "<< endl;
	cout<<"2. Nhap Ma Tran Ke"<< endl;
	cout<<"3. Xuat Ma Tran Ke"<< endl;
	cout<<"4. Tim Cay Khung Toi Thieu bang Kruskal cai tien:"<<endl
	cout<<"5. Thoat"<< endl;
	do
	{
		cout<<"\nVui long chon so de thuc hien:";
		cin >> choice; 
		switch(choice)
		{
		case 1:
			InitGraph();
				cout << "Ban vua khoi tao MA TAN KE rong thanh cong!\n";
			break ; 
		case 2:
			intGraph();
			break ; 
		case 3:
			outGraph();
			break ; 
		case 4:
			Kruskal();
			Result();
			getch();
		case 5: 
			cout << "Goodbye..........!" <<endl; 
			break; 
		default:
			break ; 
		}
	}while (choice!=6);
	system("pause");
	return 0;
}

}
			