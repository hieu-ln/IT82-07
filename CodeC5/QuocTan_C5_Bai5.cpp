#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;

#define max 20

/// DSLK su dung cho STACK va QUEUE va DANH SACH KE
struct Node
{
	int info;
	Node *link;
};

Node *sp;
Node *front, *rear;

Node *First[max]; // DS cac DSK
int n; // so dinh cua do thi
char vertex[max]; // ten dinh

///STACK
void InitStack()
{
	sp = NULL;
}
int isEmptyS()
{
	if(sp == NULL)
		return 1;
	return 0;
}
void PushS(int x)
{
	Node *p = new Node;
	p->info = x;
	p->link = sp;
	sp = p;
}
int PopS(int &x)
{
	if(sp != NULL)
	{
		Node *p = sp;
		x = p->info;
		sp = p->link;
		delete p;
		return 1;
	}
	return 0;
}
/// end STACK

/// QUEUE
void InitQueue()
{
	front = NULL;
	rear = NULL;
}
int isEmptyQ()
{
	if(front == NULL)
		return 1;
	return 0;
}
void PushQ(int x)
{
	Node * p = new Node;
	p->info = x;
	p->link = NULL;
	if(rear == NULL)
		front = p;
	else
		rear->link = p;
	rear = p;
}
int PopQ(int &x)
{
	if(front != NULL)
	{
		Node *p = front;
		front = p->link;
		x = p->info;
		if(front ==NULL)
		{
			rear = NULL;
		}
		delete p;
		return 1;
	}
	return 0;
}
/// end QUEUE
void InitGraph()
{
	n = 0;
}
void InsertLast(Node *&first, Node *p)
{
	if(first == NULL)
		first = p;
	else
	{
		Node * q = first;
		while(q->link != NULL)
		{
			q = q->link;
		}
		q->link = p;
	}
}
void inputGraphFromText()
{
	string line;
	ifstream myfile ("danhsachke1.txt");
	if(myfile.is_open())
	{
		myfile >> n;
		for(int i = 0; i < n; i++)
			myfile >> vertex[i];
		string str;
		int i = 0;
		while(getline(myfile, str))
		{
			istringstream ss(str);
			int u;
			while(ss >> u)
			{
				// Dinh u
				Node *p = new Node;
				p->info = u;
				p->link = NULL;
				InsertLast(First[i-1], p);
			}
			i++;
		}
		cout << i;
	}
}

// Cau 4.1: Nhap danh sach ke cua do thi
void inputGraph()
{
	cout << "Nhap so dinh do thi n: ";
	cin >> n;
	cout << "Nhap ten dinh: ";
	for(int i = 0; i < n; i++)
		cin >> vertex[i];
	for(int i = 0; i < n + 1; i++)
	{
		if(i > 0)
			cout << "Nhap DSK cua dinh thu " << i-1 << " (" << vertex[i-1] << ") : ";
		int u;
		string str;
		while(getline(cin, str))
		{
			istringstream ss(str);
			while(ss >> u)
			{
				Node *p = new Node;
				p->info = u;
				p->link = NULL;
				InsertLast(First[i-1], p);
			}
			break;
		}
	}
}
 
// Cau 4.2: Xuat danh sach ke cua do thi
void outputGraph()
{
	for(int i = 0; i < n; i++)
	{
		cout << "Dinh " << i << " (" << vertex[i] << "): ";
		Node *p = First[i];
		while(p != NULL)
		{
			cout << p->info << " ";
			p = p->link;
		}
		cout << endl;
	}
}
void output(int a[], int n)
{
	for(int i = 0; i < n; i++)
		cout << vertex[a[i]] << " ";
	cout << endl;
}
 // Cau 4.4: Duyet do thi theo BFS
int c[100], bfs[100];
int nbfs = 0;
void Initc()
{
	for(int i = 0; i < n; i++) // n la so dinh cua do tho
		c[i] = 1;
}
void BFS(int v) // v la dinh bat dau
{
	int p;
	Node *w;
	PushQ(v);
	c[v] = 0;
	while(front != NULL)
	{
		PopQ(p);
		bfs[nbfs] = p;
		w = First[p];
		nbfs++;
		while(w != NULL)
		{
			if(c[w->info])
			{
				PushQ(w->info);
				c[w->info] = 0;
			}
			w = w->link;
		}
	}
}

// Cau 4.4: Duyet do thi theo DFS
int dfs[100];
int ndfs = 0;
void DFS(int s)
{
	PushS(s);
	dfs[ndfs] = s;
	ndfs++;
	c[s] = 0;
	int u = s;
	Node *v = NULL;
	while(isEmptyS() == 0)
	{
		if(v == NULL)
			PopS(u);
		v = First[u];
		while(v != NULL)
		{
			if(c[v->info] == 1)
			{
				PushS(u);
				PushS(v->info);
				dfs[ndfs] = v->info;
				ndfs++;
				c[v->info] = 0;
				u = v->info;
				break;
			}
			v = v->link;
		}
	}
}

// Cau 4.5: Dung BFS tim x tren do thi
void Search_by_BFS(int x, int v) // v la dinh bat dau
{
	int p;
	Node *w;
	PushQ(v);
	c[v] = 0;
	while(front != NULL)
	{
		PopQ(p);
		if(x == p)
		{
			cout << "Tim thay x = " << x << endl;
			return;
		}
		w = First[p];
		while(w != NULL)
		{
			if(c[w->info] == 1)
			{
				PushQ(w->info);
				c[w->info] = 0;
			}
			w = w->link;
		}
	}
	cout << "Khong tim thay " << x << endl;
}

int main()
{
	int choice, x;
	system("cls");
	cout << " ---------  BAI TAP 5, CHUONG 5, DO THI  ----------\n";
	cout << "1. Khoi tao DANH SACH KE rong\n2. Nhap DANH SACH KE tu file text\n3. Nhap DANH SACH KE\n4. Xuat DANH SACH KE\n5. Duyet do thi theo chieu rong BFS\n6. Duyet do thi theo chieu sau DFS\n7. Tim dinh co gia tri x theo BFS\n8. Thoat\n";
	do
	{
		cout << "Vui long chon so de thuc hien: ";
		cin >> choice;
		switch(choice)
		{
		case 1:
			InitGraph();
			cout << "Ban vua khoi tao DANH SACH KE rong thanh cong!\n";
			break;
		case 2:
			inputGraphFromText();
			cout << "Ban vua nhap DANH SACH KE tu file! \n";
			break;
		case 3:
			inputGraph();
			break;
		case 4:
			outputGraph();
			break;
		case 5:
			InitQueue();
			Initc();
			cout << "Vui long nhap dinh xuat phat: ";
			cin >> x;
			nbfs = 0;
			BFS(x);
			cout << "Thu tu dinh sau khi duyet BFS: ";
			output(bfs, n);
			break;
		case 6:
			InitQueue();
			Initc();
			cout << "Vui long nhap dinh xuat phat: ";
			cin >> x;
			ndfs = 0;
			DFS(x);
			cout << "Thu tu dinh sau khi duyet DFS: ";
			output(dfs, n);
			break;
		case 7:
			InitQueue();
			Initc();
			nbfs = 0;
			cout << "Vui long nhap gia tri x can tim: ";
			cin >> x;
			Search_by_BFS(x, 0);
			break;
		case 8:
			cout << "Goodbye .....!" << endl;
			break;
		}
	}while(choice != 8);
	system("pause");
	return 0;
}