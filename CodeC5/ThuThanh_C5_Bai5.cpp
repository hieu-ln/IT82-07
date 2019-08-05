//CHUONG 5 - BAI 5: DO THI
#include<stdio.h>
#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;

const int MAX = 100;

//Khai bao DSLK su dung Stack, Queue va Danh sach ke
struct Node
{
	int info;
	Node *link;
};

Node *First[MAX]; //Mang chua cac danh sach ke
int n; //So dinh cua do thi
char vertex[MAX]; //Mang chua ten cac dinh

Node *sp;
Node *front, *rear;

//STACK
//Khoi tao Stack rong
void Init_Stack()
{
	sp = NULL;
}

//Kiem tra Stack rong
int isEmpty_Stack()
{
	if (sp == NULL)
		return 1;
	else
		return 0;
}

//Them mot phan tu vao Stack
void Push_Stack(int x)
{
	Node *p = new Node;
	p->info = x;
	p->link = sp;
	sp = p;
}

//Lay mot phan tu ra khoi Stack
int Pop_Stack(int &x)
{
	int result = isEmpty_Stack();

	if (result == 0)
	{
		Node *p = sp;
		x = p->info;
		sp = p->link;
		delete p;
		return 1;
	}
	else
		return 0;
}
//END STACK

//QUEUE
//Khoi tao Queue rong
void Init_Queue()
{
	front = NULL;
	rear = NULL;
}

//Kiem tra Queue rong
int isEmpty_Queue()
{
	if (front == NULL)
		return 1;
	else
		return 0;
}

//Them mot phan tu vao Queue
void Push_Queue(int x)
{
	Node *p = new Node;
	p->info = x;
	p->link = NULL;
	if (rear == NULL)
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

//Lay mot phan tu ra khoi Queue
int Pop_Queue(int &x)
{
	int result = isEmpty_Queue();

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
	else
		return 0;
}
//END QUEUE

//Khoi tao do thi
void Init_Graph()
{
	n = 0;
}

// Them phan tu vao danh sach ke
void Insert_Last(Node *&first, Node *p)
{
	if (first == NULL)
		first = p;
	else
	{
		Node *q = first;
		while (q->link != NULL)
			q = q->link;
		q->link = p;
	}
}

// NHAP DO THI TU FILE *TXT
void Input_Graph_fromText()
{
	string line;
	ifstream myfile("danhsachke1.txt");
	if (myfile.is_open())
	{
		myfile >> n;
		for (int i = 0; i < n; i++)
			myfile >> vertex[i];

		string str;
		int i = 0;
		while (getline(myfile, str))
		{
			istringstream ss(str);
			int u;
			while (ss >> u)
			{
				//Dinh u
				Node *p = new Node;
				p->info = u;
				p->link = NULL;
				Insert_Last(First[i - 1], p);
			}
			i++;
		}
	}
}

//CAU 5.1: Nhap danh sach ke tu do thi vi du 5.1
void Input_Graph()
{
	cout << "Nhap so dinh cua do thi: ";
	cin >> n;
	cout << "Nhap ten dinh: ";
	for (int i = 0; i < n; i++)
		cin >> vertex[i];

	for (int i = 0; i < n; i++)
	{
		cout << "Nhap danh sach ke cua dinh thu " << i << " (" << vertex[i] << "): ";
		int u;
		while (cin >> u)
		{
			Node *p = new Node;
			p->info = u;
			p->link = NULL;
			Insert_Last(First[i - 1], p);
		}
	}
}

//CAU 5.2: Xuat danh sach ke cua do thi
void Output_Graph()
{
	for (int i = 0; i < n; i++)
	{
		cout << "Dinh " << i << " (" << vertex[i] << "): ";
		Node *p = First[i];
		while (p != NULL)
		{
			cout << p->info << "\t";
			p = p->link;
		}
		cout << endl;
	}
}

void Output(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << vertex[a[i]] << "\t";
}

//CAU 5.3: Duyet do thi theo BFS (Su dung Queue voi DSLK)
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
	int p; //Dinh dang xet
	Node *w; //Dinh ke
	Push_Queue(v);
	C[v] = 0;

	while (front != NULL)
	{
		Pop_Queue(p);
		bfs[nbfs] = p;
		w = First[p];
		nbfs++;

		while (w != NULL)
		{
			if (C[w->info])
			{
				Push_Queue(w->info);
				C[w->info] = 0;
			}
			w = w->link;
		}
	}
}

//CAU 5.4: Duyet do thi theo DFS (Su dung Stack voi DSLK)
int dfs[MAX];
int ndfs = 0;

void DFS(int s) //s la dinh bat dau
{
	Push_Stack(s);
	dfs[ndfs] = s;
	ndfs++;
	C[s] = 0;

	int u = s; //u la dinh dang xet
	Node *v = NULL; //v la dinh ke

	while (isEmpty_Stack() == 0)
	{
		if (v == NULL)
			Pop_Stack(u);
		v = First[u];
		while (v != NULL)
		{
			if (C[v->info] == 1)
			{
				Push_Stack(u);
				Push_Stack(v->info);
				dfs[ndfs] = v->info;
				ndfs++;
				C[v->info] = 0;
				u = v->info;
				break;
			}
			v = v->link;
		}
	}
}

//CAU 5.5: Kiem tra dinh x co ton tai trong do thi theo BFS
void Search_by_BFS(int x, int v) //v la dinh bat dau
{
	int p;
	Node *w;
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
		w = First[p];
		while (w != NULL)
		{
			if (C[w->info])
			{
				Push_Queue(w->info);
				C[w->info] = 0;
			}
			w = w->link;
		}
	}

	cout << "Khong tim thay dinh x = " << x << " trong do thi!" << endl;
}

int main()
{
	int a[MAX];
	int b[MAX];
	int choice, result, x;

	system("cls");

	cout << "---------- CHUONG 5 - BAI 5: DO THI ----------" << endl;
	cout << "1. Khoi tao DANH SACH KE rong" << endl;
	cout << "2. Nhap DANH SACH KE tu FILE *TXT" << endl;
	cout << "3. Nhap DANH SACH KE" << endl;
	cout << "4. Xuat DANH SACH KE" << endl;
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
			cout << "Khoi tao DANH SACH KE rong thanh cong!" << endl;
			cout << endl;
			break;
		case 2:
			Input_Graph_fromText();
			cout << "Nhap DANH SACH KE tu FILE *TXT thanh cong!" << endl;
			cout << "DANH SACH KE hien tai la: " << endl;
			Output_Graph();
			cout << endl;
			break;
		case 3:
			//Input_Graph();
			cout << "ERROR!" << endl;
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