//CHUONG 5 - BAI 4: DO THI
#include<stdio.h>
#include<iostream>
#include<fstream>
using namespace std;

//KHAI BAO
const int MAX = 100;
int a[MAX][MAX]; //Ma tran ke
int n; //So dinh cua do thi
char vertex[MAX]; //Ten dinh cua do thi

//KHAI BAO DSLK CHO STACK VA QUEUE
struct Node
{
	int info;
	Node *link;
};

Node *sp;
Node *front, *rear;

//STACK
void Init_Stack()
{
	sp = NULL;
}

int isEmptyS()
{
	if (sp == NULL)
		return 1;
	else
		return 0;
}

void Push_Stack(int x)
{
	Node *p = new Node;
	p->info = x;
	p->link = sp;
	sp = p;
}

int Pop_Stack(int &x)
{
	int result = isEmptyS();

	if (result == 0)
	{
		Node *p = sp;
		x = p->info;
		sp = p->link;
		delete p;
		return 1;
	}
	return 0;
}
//END STACK

//QUEUE
void Init_Queue()
{
	front = NULL;
	rear = NULL;
}

int isEmptyQ()
{
	if (front == NULL)
		return 1;
	else
		return 0;
}

void Push_Queue(int x)
{
	int result = isEmptyQ();

	Node *p = new Node;
	p->info = x;
	p->link = NULL;

	if (result == 1)
	{
		front = p;
		rear = p;
	}
	else
	{
		rear->link = p;
		rear = p;
	}
}

int Pop_Queue(int &x)
{
	int result = isEmptyQ();

	if (result == 0)
	{
		Node *p = front;
		front = p->link;
		x = p->info;
		if (front == NULL)
			rear = NULL;
		delete p;
		return 1;
	}
	return 0;
}
//END QUEUE

//KHOI TAO DO THI
void Init_Graph()
{
	n = 0;
}

//KHOI TAO DO THI TU FILE *TXT
void Input_Graph_fromText()
{
	string line;
	ifstream myfile("matranke1.txt");
	if (myfile.is_open())
	{
		myfile >> n; //Doc so dinh

		for (int i = 0; i < n; i++) //Doc ten dinh
			myfile >> vertex[i]; 

		for (int i = 0; i < n; i++) //Doc ma tran
			for (int j = 0; j < n; j++)
				myfile >> a[i][j];
	}
}

//CAU 4.1: Nhap ma tran ke tu do thi vi du 5.1
void Input_Graph()
{
	cout << "Nhap so dinh (n) cua do thi: ";
	cin >> n;

	cout << "Nhap ten cac dinh cua do thi: ";
	for (int i = 0; i < n; i++)
		cin >> vertex[i];

	for (int i = 0; i < n; i++)
	{
		cout << "Nhap dong thu " << (i + 1) << ": ";
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	}
}

//CAU 4.2: Xuat ma tran ke cua do thi
void Output_Graph()
{
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
			cout << "\t";

		if (i == (n - 1))
			cout << vertex[i] << endl;
		else
			cout << vertex[i] << "\t";
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j == 0)
					cout << vertex[i] << "\t";
			if (j == (n - 1))
				cout << a[i][j] << endl;
			else
				cout << a[i][j] << "\t";
		}
	}
}

void Output(int a[], int n)
{
	for (int i = 0; i < n; i++)
		//if (i == (n - 1))
		//	cout << vertex[a[i]] << endl;
		//else
			cout << vertex[a[i]] << "\t";
}

//CAU 4.3: Duyet do thi theo BFS (Su dung Queue voi DSLK)
int C[MAX];
int bfs[MAX];
int nbfs = 0;

void InitC()
{
	for (int i = 0; i < n; i++)
		C[i] = 1;
}

void BFS(int v) //v la dinh bat dau
{
	int w, p;
	Push_Queue(v);
	C[v] = 0;

	while (front != NULL)
	{
		Pop_Queue(p);
		bfs[nbfs] = p;
		nbfs++;

		for (w = 0; w < n; w++)
			if (C[w] && (a[p][w] == 1))
			{
				Push_Queue(w);
				C[w] = 0;
			}
	}
}

//CAU 4.4: Duyet do thi theo DFS (Su dung Stack voi DSLK)
int dfs[MAX];
int ndfs = 0;

void DFS(int s) //s la dinh bat dau
{
	Push_Stack(s);
	dfs[ndfs] = s;
	ndfs++;
	C[s] = 0;
	int v = -1, u = s;

	while (isEmptyS() == 0)
	{
		if (v == n)
			Pop_Stack(u);
		for (v = 0; v < n; v++)
			if (a[u][v] != 0 && C[v] == 1)
			{
				Push_Stack(u);
				Push_Stack(v);
				dfs[ndfs] = v;
				ndfs++;
				C[v] = 0;
				u = v;
				break;
			}
	}
}

//CAU 4.5: Kiem tra dinh x co ton tai trong do thi theo BFS
void Search_by_BFS(int x, int v) //v la dinh bat dau
{
	int w, p;
	Push_Queue(v);
	C[v] = 0;

	while (front != NULL)
	{
		Pop_Queue(p);
		if (x == p)
		{
			cout << "Tim thay dinh x = " << x << " trong do thi!" << endl;
			return;
		}

		for (w = 0; w < n; w++)
			if (C[w] && a[p][w] == 1)
			{
				Push_Queue(w);
				C[w] = 0;
			}
	}

	if (front == NULL)
		cout << "Khong tim thay x " << x << " trong do thi!" << endl;
}

int main()
{
	int a[MAX];
	int b[MAX];
	int choice, x, result;

	system("cls");

	cout << "---------- CHUONG 5 - BAI 4: DO THI ----------" << endl;
	cout << "1. Khoi tao MA TRAN KE rong" << endl;
	cout << "2. Nhap MA TRAN KE tu FILE *TXT" << endl;
	cout << "3. Nhap MA TRAN KE" << endl;
	cout << "4. Xuat MA TRAN KE" << endl;
	cout << "5. Duyet do thi theo BFS (su dung DSLK)" << endl;
	cout << "6. Duyet do thi theo DFS (su dung DSLK)" << endl;
	cout << "7. Tim dinh x theo BFS" << endl;
	cout << "8. Thoat" << endl;

	do
	{
		cout << "Vui long chon so de thuc hien: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			Init_Graph();
			cout << "Khoi tao MA TRAN KE rong thanh cong!" << endl;
			cout << endl;
			break;
		case 2:
			Input_Graph_fromText();
			cout << "Nhap MA TRAN KE tu file *txt thanh cong!" << endl;
			cout << "MA TRAN KE hien tai la: " << endl;
			Output_Graph();
			cout << endl;
			break;
		case 3:
			Input_Graph();
			cout << endl;
			break;
		case 4:
			cout << "MA TRAN KE hien tai la: " << endl;
			Output_Graph();
			cout << endl;
			break;
		case 5:
			Init_Queue();
			InitC();
			cout << "Nhap dinh (x) bat dau: ";
			cin >> x;
			nbfs = 0;
			BFS(x);
			cout << "Thu tu cac dinh sau khi duyet theo BFS la:" << endl;
			Output(bfs, n);
			cout << endl;
			break;
		case 6:
			Init_Stack();
			InitC();
			cout << "Nhap dinh (x) bat dau: ";
			cin >> x;
			ndfs = 0;
			DFS(x);
			cout << "Thu tu cac dinh sau khi duyet theo DFS la:" << endl;
			Output(dfs, n);
			cout << endl;
			break;
		case 7:
			Init_Queue();
			InitC();
			nbfs = 0;
			cout << "Vui long nhap dinh (x) can tim: ";
			cin >> x;
			Search_by_BFS(x, 0);
			cout << endl;
			break;
		case 8:
			cout << "Goodbye...!" << endl;
			cout << endl;
			break;
		default:
			break;
		}
	} while (choice != 8);

	system("pause");
	return 0;
}