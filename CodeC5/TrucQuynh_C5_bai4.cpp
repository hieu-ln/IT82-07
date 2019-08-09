#include <stdio.h>
#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;

#define MAX 20
int a[MAX][MAX];   //mảng 2 chiều
int n; // số đỉnh của đồ thị
char vertex[MAX];  // tên đỉnh

struct Node
{
	int info;
	Node*link;
};
Node*sp;
Node*front,*rear;

// stack
void initStack()
{
	sp=NULL;
}

int EmptyStack()
{
	if(sp=NULL)
		return 1;
	return 0;
}

void PushStack(int x)
{
	Node*p=new Node;
	p->info=x;
	p->link=sp;
	sp=p;
}

int PopStack (int &x)
{
	if(sp!=NULL)
	{
		Node *p=sp;
		x=p->info;
		sp=p->link;
		delete p;
		return 1;
	}
	return 0;
}

// queue
void initQueue()
{
	front=NULL;
	front=NULL;
	rear=NULL;
}

int isEmptyQueue()
{
	if(front==NULL)
		return 1;
	return 0;
}

void PushQueue(int x)
{
	Node*p=new Node;
	p->info=x;
	p->link=NULL;
	if(rear==NULL)
	{
		front=p;

	}
	else
		rear->link=p;
	rear=p;
}

int PopQueue(int &x)
{
	if(front!=NULL)
	{
		Node*p=front;
		front=p->link;
		x=p->info;
		if(front==NULL)
		{
			rear=NULL;
		}
		delete p;
		return 1;
	}
	return 0;
}

// nhập biểu đồ từ file text
void InitGrap()
{
	string line;
	ifstream myfile ("matranke1.txt");
	if(myfile.is_open())
	{
		myfile>>n;   //cin>>n
		for(int i=0; i<n; i++)
			myfile>>vertex[i];
		for(int i=0; i<n;i++)
		{
			for(int j=0;j<n; j++)
				myfile>>a[i][j];
		}
	}

}

// Cau 4.1: Viet hàm nhập ma trận kề
void InputGrap()
{
	cout<<"Nhap so dinh cua do thi n:";
	cin>>n;
	cout<<"Nhap ten dinh:";
	for(int i=0; i<n; i++)
		cin>>vertex[i];
	for(int i=0;i<n;i++)
	{
		cout<<"Nhap vao dong thu "<<i+1<<":";
		for(int j=0; j<n; j++)
			cin>>a[i][j];
	}
}

// cau 4.2: Viết hàm xuất ma trận 
void OutGrap()
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			cout<<a[i][j]<< "  " ;
		cout<<endl;

	}
}

void ouput(int a[], int n)
{
	for(int i=0; i<n; i++)
		cout<<vertex[a[i]]<<"  ";

}

// 4.3: Duyet do thi theo chieu rong BFS (Dung queue dslk đơn)
int C[100], bfs[100];
int nbfs=0;
void InintB()
{
	for(int i=0; i<n; i++) // n là số đỉnh
		C[i]=1;
}

void BFS(int v) // v là đỉnh bắt đầu
{
	int w,p;
	PushQueue(v);
	C[v]=0;
	while (front!=NULL)
	{
		PopQueue(p);
		bfs[nbfs]=p;
		nbfs++;
		for(w=0;w<n;w++)
			if(C[w] && a[p][w]==1)
			{
				PushQueue(w);
				C[w]=0;

			}


	}
}

// 4.4: duyet do thi theo chieu sau DFS (dung stack và dslk đơn
int dfs[100];
int ndfs=0;
void DFS(int s)
{
	PushStack(s);
	dfs[ndfs]=s;
	ndfs++;
	C[s]=0;
	int v=-1, u=s;
	while (EmptyStack()==0)
	{
		if(v==n)
			PopStack(u);
		for(v=0; v<n; v++)
			if(a[u][v]!=0 && C[v]==1)
			{
				PushStack(u);
				PushStack(v);
				dfs[ndfs]=v;
				ndfs++;
				C[v]=0;
				u=v;
				break;
			}
	}
}


//4.5 Nhap vao một đỉnh X hãy kiểm tra X có tồn tại trên đồ thị hay không
void Search_BFS(int x, int v) // v là đỉnh bắt đầu
{
	int w,p;
	PushQueue(v);
	C[v]=0;
	while(front!=NULL)
	{
		PopQueue(p);
		if(x==p)
		{
			cout<<"tim thay x="<<x<<endl;
			return;
		}
		for(w=0; w<n; w++)
			if(C[w]&& a[p][w]==1)
			{
				PushQueue(w);
				C[w]=0;
			}
	}
}

int main()
{
	int a[MAX];
	int b[MAX];
	int choice, x, i;
	system("cls");
	cout<<"1.Khoi tao danh sach"<<endl;
	cout<<"2.Nhap ma tran ke tu file text"<<endl;
	cout<<"3.Nhap ma tran ke"<<endl;
	cout<<"4.Xuat ma tran ke"<<endl;
	cout<<"5.Duyet do theo chieu rong BFS"<<endl;
	cout<<"6.Duyet do thi theo chieu dai DFS"<<endl;
	cout<<"7.Tim dinh co gia tri x bang BFS"<<endl;
	cout<<"8.EXIT"<<endl;

	do
	{
		cout<<"Nhap vao lua chon"<<endl;
		cin>>choice;
		switch(choice)
		{
		case 1:
			InitGrap();
			cout<<"Ban tap ma tram rong thanh cong"<<endl;
			break;
		case 2:
			InitGrap();
			cout<<"Ban vua nhap ma tu file "<<endl;
			OutGrap();
			break;
		case 3:
			InputGrap();
			break;
		case 4:
			OutGrap();
			break;
		case 5: 
			initQueue();
			InintB();
			cout<<"Vui long nhap dinh xuat phat"<<endl;
			cin>>x;
			nbfs=0;
			BFS(x);
			cout<<"Thu tu dinh sau khi duyet BFS"<<endll;
			ouput(bfs,n);
			break;
		case 6:
			initStack();
			InintB();
			cout<<"Vui long nhap dinh xuat phat"<<endl;
			cin>>x;
			ndfs=0;
			DFS(x);
			cout<<"Thu tu dinh sau khi duyet DFS"<<endl;
			ouput(dfs,n);
			break;
		case 7:
			initQueue();
			InintB();;
			nbfs=0;
			cout<<"Vui long nhap gia tri x can tim"<<endl;
			cin>>x;
			Search_BFS(x,0);
			break;
		case 8:
			cout<<"bye"<<endl;
			break;
		default: 
			break;
		}



	}
	while(choice!=8);
	system("pause");
	return 0;

}