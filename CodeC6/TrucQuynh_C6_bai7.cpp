#include <iostream>
#include <stdio.h>
#include <fstream>
#include <iomanip>

using namespace std;

//khai bao ma tran bang mang hai chieu
# define MAX 20
int a[MAX][MAX];
int n;// so dinh cua do thi
char vertex[MAX];  // ten dinh

void InitGraph()
{
	n=0;
}

void inputGraphFromTxt()
{
	string line;
	ifstream mylife("do_thi_1.txt");
	if(mylife.is_open())
	{
		mylife >>n;
		for(int i=0; i<n;i++)
			mylife>>vertex[i];
		for(int i=0; i<n; i++)
		{
			for (int j=0;j<n; j++)
				mylife>>a[i][j];
		}
	}
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

// khoi tao tap E
int E1[MAX];
int E2[MAX];
int wE[MAX];
int nE=0;  // so phan tu tap E

//khoi bao tap T
int T1[MAX];
int T2[MAX];
int wT[MAX];
int nT=0; // so phan tu tap T

int TonTai(int d, int D[], int nD)
{
	for(int i=0;i<nD; i++)
		if(D[i]==d)
			return 1;
	return 0;
}

void XoaViTriE(int i)
{
	for(int j=i;j<nE; j++)
	{
		E1[j]=E1[j+1];
		E2[j]=E2[j+1];
		wE[j]=wE[j+1];
	}
	nE--;
}

void XoaCanhE(int u, int v)
{
	for (int i=0; i<nE;i++)
		if(E1[i]==u&&E2[i]==v)
		{
			XoaViTriE(i);
			break;
		}
}

// 7.1 Giai3 thuật Prim
void Prim(int s) // s la dinh bat dau
{

	int u=s,min, i, d1, d2;
	while(nT<n-1)
	{
		for(int v=0; v<n;v++)
			if(a[u][v]!=0)
				if(TonTai(v,T2,nT)==0)
				{
					E1[nE]=u;
					E2[nE]=v;
					wE[nE]=a[u][v];
					nE++;
				}
			for (int i=0;i<nE; i++)
				if(TonTai(E2[i],T2,nT)==0)
				{
					min=wE[i];
		            d1=E1[i];
			        d2=E2[i];
			        break;
				}
			for (i=0;i<nE;i++)
				if(TonTai(E2[i],T2,nT)==0)
					if(min>wE[i])
					{
						min=wE[i]; 
						d1=E1[i];
						d2=E2[i];
					}
			T1[nT]=d1;
			T2[nT]=d2;
			wT[nT]=a[d1][d2];
			a[d1][d2]=0;
			a[d2][d1]=0;
			nT++;
			XoaCanhE(d1,d2);
			u=d2;
		

	

	
		}
}

void output(bool VertexName)
{
	int tong=0;
	for(int i=0;i<nT;i++)
	{
		if(VertexName)
			cout<<endl<<"("<<vertex[T1[i]]<<","<<vertex[T2[i]]<<")="<<wT[i];
		else
			cout<<endl<<"("<<T1[i]<<","<<T2[i]<<")="<<wT[i];
		tong+=wT[i];
	}
	cout<<"\n Tong="<<tong;
}

//7.2 Gia3i thuật Kruskal
// hàm swap 
void swap(int &a, int &b)
{
	int tempt=a;
	a=b;
	tempt=b;
}


void Sort()
{
	for (int i=0;i<nE-1;i++)
		for(int j=i+1;j<nE;j++)
			if(wE[i]>wE[j])
			{
				swap(wE[i],wE[j]);
				swap (E1[i],E2[j]);
				swap(E2[i],E2[j]);

			}
}


void Kruskal()
{
	for(int i=0; i<nE;i++)
	{
		if(TonTai(E1[i], T1, nT)==1 && TonTai(E2[i], T2, nT)==1)
			continue;
		T1[nT]=E1[i];
		T2[nT]=E2[i];
		wT[nT]=wE[i];
		nT++;
		if(nT==n-1)
			break;
		
		Sort();

	}
}

// 7.3: giải thuật Kruskal cải tiến
// ghi file ra tệp tim


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

void Kruskaltt()
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
	cout<<"2. Nhap MA TRAN KE tu file text "<< endl;
	cout<<"3. Xuat Ma Tran Ke"<< endl;
	cout<<"4.tim Cay Khung Toi Thieu bang PRIM "<< endl;
	cout<<"5. Tim cay khung toi thieu Kruskal"<<endl;
	cout<<"6.Tim cay khung toi thieu Kruskal tien tien"<<endl;
	cout<<"7.Thoat"<<endl;
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
			inputGraphFromTxt();
			cout << "Ban vua nhap MA TAN KE tu file: \n";
			outGraph();
			break ; 
		case 3:
			outGraph();
			break ; 
		case 4:
			cout << "Vui long nhap dinh xuat phat: ";
			cin >> x;
			Prim(x);
			cout <<" Cay khun toi thieu voi PRIM: "<<endl; 
			output(true );
		case 5:
			cout <<" Cay khun toi thieu voi Krusal: "<<endl;
			Kruskal();
			output(true);
		case 6:
			cout<<"Cay khung toi thieu Kruskal tien tien"<<endl;
			Kruskaltt();
			Result();
			output(true);
		}

	}while (choice!=6);
	system("pause");
	return 0;

}