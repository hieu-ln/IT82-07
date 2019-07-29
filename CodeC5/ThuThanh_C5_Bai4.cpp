//BAI 4 CHUONG 5_ DO THI
#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

#define MAX 20
int A[MAX][MAX];
int n;//so dinh
char vertex[MAX];//ten dinh

struct Node 
{
	int info;
	Node *link;
};
Node *sp;
Node *front, *rear;

void InitStack()
{
	sp= NULL;
}
int isEmptyS()
{
	if (sp =NULL)
		return 1;
	return 0;
}
void PushS(int x)
{
	Node *p = new Node;
	p -> info = x;
	p -> link = sp;
	sp = p;
}
int PopS(int &x)
{
	if(sp != NULL)
	{
		Node *p = sp;
		x = p -> info;
		sp = p -> link;
		delete p;
		return 1;
	}
	return 0;
}
//end stack

void InitQueue()
{
	front = NULL;
	rear = NULL;
}
int isEmpty()
{
	if(front == NULL)
		return 1;
	return 0;
}
void PushQ(int x)
{
	Node *p = new Node;
	p -> info = x;
	p -> link = NULL;
	if(rear == NULL)
		front = p;
	else 
		rear -> link = p;
	rear = p;
}
int PopQ(int &x)
{
	if (front !=NULL) 
	{
		Node *p = front;
		front = p -> link;
		x = p -> info;
		if(front == NULL)
			rear = NULL;
		delete p;
		return 1;
	}
	return 0;
}

void InitGraph()
{
	n=0;
}

void InputGraphFromText()
{
	string line;
	ifstream myfile ("matranke.txt");
	if(myfile.is_open())
	{
		myfile >> n;
		for (int i = 0; i< n; i++)
			myfile >> vertex[i];
		for (int i = 0; i <n; i++)
		{
			for (int j = 0; j <n; j++)
				myfile >> A[i][j];
		}
	}
}

//cau4.1: Nhap ma tran ke cua do thi
void inputGraph()
{
	cout << "Nhap so dinh cua do thi n: ";
	cin >> n;
	for (int i = 0; i <n; i++)
	{
		cout << "Nhap ten dinh: ";
		cin >> vertex[i];
		cout << "nhap vao dong thu "<< i + 1 << ": ";
		for (int j = 0; j < n; j++)
			cin >> A[i][j];
	}
}
//cau 4.2: xuat ma tran ke cua do thi
void outputGraph()
{
	for (int i=0; i<n; i ++)
	{
		for (int j = 0; j < n ; j ++)
			cout << A[i][j] << " ";
		cout << endl;
	}
}

void output(int a[], int n)
{
	for (int i = 0;i < n; i ++)
		cout << vertex [a[i]] << " ";
}

//cau 4.3 duyet do thi theo chieu rong BFS(dung QUEUE va DSLK don)
int C[100], bfs[100];
int nbfs = 0;
void InitC()
{
	for (int i = 0; i < n; i ++)// n la so dinh
		C[i] = 1;
}
void BFS(int v) //dinh bat dau
{
	int w, p;
	PushQ(v);
	C[v] = 0;
	while (front != NULL)
	{
		PopQ(p);
		bfs[nbfs] = p;
		nbfs++;
		for (w= 0; w<n; w++)
			if (C[w] && A[p][w] == 1)
			{
				PushQ(w);
				C[w] = 0;
			}
	}
}
//cau 4.4: duyet do thi theo chieu sau DFS(dung STACK va DSLK don)
int dfs[100];
int ndfs=0;
void DFS(int s)
{
	PushS(s);
	dfs[ndfs] = s;
	ndfs++;
	C[s] = 0;
	int v = -1, u = s;
	while (isEmptyS() == 0)
	{
		if (v==n)
			PopS(u);
		for (v = 0; v < n; v++)
			if(A[u][v] != 0 && C[v] == 1)
			{
				PushS(u);
				PushS(v);
				dfs[ndfs] = v;
				ndfs++;
				C[v] = 0;
				u = v;
				break;
			}
	}
}

//cau 4.5: Dung BFS tim x tren do thi
void Search_by_BFS(int x, int v)// v la dinh bat dau
{
	int w, p;
	PushQ(v);
	C[v] = 0;
	while (front != NULL)
	{
		PopQ(p);
		if(x == p)
		{
			cout << "Tim thay x= " << x << endl;
			return;
		}
		for (w= 0; w <n; w++)
			if( C[w] && A[p][w] == 1)
			{
				PushQ(w);
				C[w] = 0;
			}
	}
}

int main()
{
	int a[MAX];
	int b[MAX];
	int choice, sp,sp_b, x, i;
	system("cls");
	cout << "----------BAI TAP 4, CHUONG 5, DO THI----------" << endl;
	cout << "1. Khoi tao ma tran ke rong" << endl;
	cout << "2. Nhap ma tran ke tu file text" << endl;
	cout << "3. Nhap ma tran ke" << endl;
	cout << "4. Xuat ma tran ke" << endl;
	cout << "5. Duyet do thi theo chieu rong BFS -DSLK" << endl;
	cout << "6. Duyet do thi theo chieu rong DFS -DSLK" << endl;
	cout << "7. Tim dinh co gia tri x theo BFS" << endl;
	cout << "8. Thoat" << endl;
	do 
	{
		cout << "\nVui long chon so de thuc hien: ";
		cin >> choice;
		switch(choice)
		{
		case 1:
			InitGraph();
			cout << "Ban vua khoi tao MA TRAN KE rong thanh cong!\n" ;
			break;
		case 2:
			InputGraphFromText();
			cout << "ban vua nhap MA TRAN KE tu file: \n";
			outputGraph();
			break;
		case 3:
			inputGraph();
			break;
		case 4:
			outputGraph();
			break;
		case 5: InitQueue();
			InitC();
			cout << "Vui long nhap dinh xuat phat: ";
			cin >> x;
			nbfs = 0;
			BFS(x);
			cout << "thu tu din sau khi duyet BFS: " << endl;
			output(bfs, n);
			break;
		case 6:
			InitStack();
			InitC();
			cout << "Vui long nhap dinh xuat phat: ";
			cin >> x;
			ndfs = 0;
			DFS(x);
			cout << "Thu tu dinh sau khi duyet DFS" << endl;
			output(dfs,n);
			break;
		case 7: 
			cout << "Vui long nhap gia tri x can tim: ";
			cin >> x;
			Search_by_BFS(x,0);
			break;
		case 8:
			cout << "Goodbye.......!" << endl;
			break;
		default:
			break;
		}
	}
	while (choice != 8);
	system("pause");
	return 0;
}