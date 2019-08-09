#include <stdio.h>
#include <iostream>
#include <math.h>
#include <fstream>
#include <vector>
#include <conio.h>
using namespace std;

#define MAX 100
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
Node*List[MAX];
int u,v,m,n;

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

void PushStack(int x)// them mot phan tu
{
	Node*p=new Node;
	p->info=x;
	p->link=sp;
	sp=p;
}

int PopStack (int &x)// lay ra 1 phần tử
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
	rear=NULL;
}

int isEmptyQueue()  // ktra queue rỗng
{
	if(front==NULL)
		return 1;
	return 0;
}

void PushQueue(int x) // them mot phan tu
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

int PopQueue(int &x) // lấy 1 phần tử
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


// Khoi tao do thi
void InitGrap()
{
	n=0;
}

// Them phần tử vào ds kề
void Insert( Node *&List,Node *p)
{
	if(List=NULL)
		List=p;
	else
	{
		Node *q=List;
		while (q->link != NULL)
			q = q->link;
		q->link = p;
	}
}

// 5.1 Nhap danh sach ke cua do thi
void InputGrap()
{
	cout<<"Nhap so dinh cua do thi n:";
	cin>>n;
	cout<<"Nhap ten dinh:";
	for(int i=0; i<n; i++)
		cin>>vertex[i];
	for(int i=0;i<n;i++)
	{
		cout<<"Nhap vao danh sach ke cua dinh thu"<<i<<" ("<<vertex[i]<<"):";
		int t;
		while (cin>>t)
		{
			Node *p=new Node;
			p->info=t;
			p->link=NULL;
			Insert(List[i-1],p);

			
			
		}

	}
}

//5.2: Xuat danh sach kề
void OutGrap()
{
	for(int i=0; i<n; i++)
	{
		cout<<"Dinh"<<i<<" ("<<vertex[i]<<"):";
		Node *p=List[i];
		while (p != NULL)
		{
			cout << p->info <<"  ";
			p = p->link;
		}
		cout << endl;

	}
}

void ouput(int a[], int n)
{
	for(int i=0; i<n; i++)
		cout<<vertex[a[i]]<<"  ";

}

//5.3 Viết hàm duyệt đồ thị theo chiều rộng (dựa trên queue)
int C[100], bfs[100];
int nbfs=0;
void InintB()
{
	for(int i=0; i<n; i++) // n là số đỉnh
		C[i]=1;
}

void BFS(int v) // v là đỉnh bắt đầu
{
	int p; // đỉnh đang xét
	Node *d; // đỉnh kề
	PushQueue(v);
	C[v]=0;
	while (front!=NULL)
	{
		PopQueue(p);
		bfs[nbfs]=p;
		d=List[p];
		nbfs++;

		while (d!=NULL)
		{
			if(C[d->info])
			{
				PushQueue(d->info);
				C[d->info]=0;

			}
			d=d->link;
		}

	}
}



// 5.4 Duyệt theo chiều sâu (dùng stack)
int dfs[100];
int ndfs=0;
void DFS(int s)
{
	PushStack(s);
	dfs[ndfs]=s;
	ndfs++;
	C[s]=0;

	int  u=s; // u là đỉnh đang xét 
	Node *v=NULL; // v là đỉnh kề

	while (EmptyStack()==0)
	{
		if(v==NULL)
			PopStack(u);
		v=List[u];
		while(v!=NULL)
		{
			if (C[v->info] == 1)
			{
				PushStack(u);
				PushStack(v->info);
				dfs[ndfs]=v->info;
				ndfs++;
				C[v->info]=0;
				u=v->info;
				break;

			}
			v=v->link;

		}
	}

}

// 5.5 Nhap vao mot dinh x và ktra
void Search_BFS(int x, int v) // v là đỉnh bắt đầu
{
	int p;
	Node*w;
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
		w=List[p];
		while(w!=NULL)
		{
			if (C[w->info])
			{
				PushQueue(w->info);
				C[w->info] = 0;

			}
			w=w->link;
		}
	}
	cout << "Khong tim thay dinh x = " << x << " trong do thi" << endl;
}

int main()
{
	int a[MAX];
	int b[MAX];
	int choice, x, i;
	system("cls");
	cout<<"1.Khoi tao danh sach"<<endl;
	cout<<"2.Nhap ma tran ke"<<endl;
	cout<<"3.Xuat ma tran ke"<<endl;
	cout<<"4.Duyet do theo chieu rong BFS"<<endl;
	cout<<"5.Duyet do thi theo chieu dai DFS"<<endl;
	cout<<"6.Tim dinh co gia tri x bang BFS"<<endl;
	cout<<"7.EXIT"<<endl;
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
			cout<<"Ma tran ke ";
			OutGrap();
			break;
		case 3:
			initQueue();
			InintB();
			cout<<"Vui long nhap dinh xuat phat"<<endl;
			cin>>x;
			nbfs=0;
			BFS(x);
			cout<<"Thu tu dinh sau khi duyet BFS"<<endll;
			ouput(bfs,n);
			break;
		case 4:
			initStack();
			InintB();
			cout<<"Vui long nhap dinh xuat phat"<<endl;
			cin>>x;
			ndfs=0;
			DFS(x);
			cout<<"Thu tu dinh sau khi duyet DFS"<<endl;
			ouput(dfs,n);
			break;
		case 5:
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