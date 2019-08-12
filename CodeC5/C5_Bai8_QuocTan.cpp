#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
#define max 20
int a[max][max];
int n;
char vertex[max];

// Cau truc danh sach lien ket
struct Node {
	int info;
	Node *link;
};
Node *front, *rear;
Node *sp;
Node *first[max];

// Queue
void initQueue() {
	front = NULL;
	rear = NULL;
}
int isEmptyQueue() {
	if(front == NULL)
		return 1;
	return 0;
}

void pushQueue(int x) {
	Node *p = new Node;
	p->info = x;
	p->link = NULL;
	if(rear == NULL)
		front = p;
	else
		rear->link = p;
	rear = p;
}

int popQueue(int &x) {
	if(front != NULL) {
		Node *p = front;
		front = p->link;
		x = p->info;
		if(front == NULL)
			rear = NULL;
		delete p;
		return 1;
	}
	return 0;
}

// Stack
void initStack() {
	sp = NULL;
}

int isEmptyStack() {
	if(sp == NULL)
		return 1;
	return 0;
}

void pushStack(int x) {
	Node *p = new Node;
	p->info = x;
	p->link = sp;
	sp = p;
}

int popStack(int &x) {
	if(sp != NULL) {
		Node *p = sp;
		x = p->info;
		sp = p->link;
		delete p;
		return 1;
	}
	return 0;
}

// 8.1 Nhap ma tran ke tu file text
void initGraph() {
	n = 0;
}

void insertLast(Node *&first, Node *p) {
	if(first == NULL)
		first = p;
	else {
		Node *q = first;
		while(q->link != NULL)
			q = q->link;
		q->link = p;
	}
}

void inputFromText() {
	string line;
	ifstream myFile("matranke1.txt");
	if (myFile.is_open()) {
		myFile >> n;
		for(int i = 0; i < n; i++) {
			myFile >> vertex[i];
		}
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				myFile >> a[i][j];
	}
}

// Danh sach ke
void inputList()
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
				Node *p = new Node;
				p->info = u;
				p->link = NULL;
				insertLast(first[i-1], p);
			}
			i++;
		}
		cout << i;
	}
}

// 8.2 Xuat cac dinh do thi bang phuong phap DFS (Queue)
// 8.3 Xuat cac dinh do thi bang phuong phap BFS (Stack)
// 8.4 Xuat cac dinh do thi bang phep duyet BFS (De quy)
// Em khong biet lam

// BFS with Queue
int c[100];
int bfs[100];
int nbfs = 0;
void BFS(int v) {
	int w, p;
	pushQueue(v);
	c[v] = 0;
	while(front != NULL) {
		popQueue(p);
		bfs[nbfs] = p;
		nbfs++;
		for(w =0; w < n; w++)
			if(c[w] && a[p][w] == 1) {
				pushQueue(w);
				c[w] = 0;
			}
	}
}

void initC() {
	for(int i = 0; i < n; i++)
		c[i] = 1;
}

void outputBFS() {
	for(int i = 0; i < nbfs; i++)
		cout << bfs[i] << " ";
	cout << endl;
}

// DFS with Stack
int dfs[100];
int ndfs = 0;
void DFS(int s) {
	pushStack(s);
	dfs[ndfs] = s;
	ndfs++;
	c[s] = 0;
	int v = -1, u = s;
	while(!isEmptyStack()) {
		if(v == n)
			popStack(u);
		for(v = 0; v < n; v++)
			if(a[u][v] != 0 && c[v] == 1) {
				pushStack(u);
				pushStack(v);
				dfs[ndfs] = v;
				ndfs++;
				c[v] = 0;
				u = v;
				break;
			}
	}
}

void outputDFS() {
	for(int i = 0; i < ndfs; i++)
		cout << dfs[i] << " ";
	cout << endl;
}

// Search with BFS
void search(int x, int v) {
	int w, p;
	pushQueue(v);
	c[v] = 0;
	while(front != NULL) {
		popQueue(p);
		if(x == p) {
			cout << x << " la dinh cua do thi\n";
			return;
		}
		for(w = 0; w < n; w++)
			if(c[w] && a[p][w] == 1) {
				pushQueue(w);
				c[w] = 0;
			}
	}
}

int main() {
	int choice, x, y;
	system("cls");
	cout << "---------------BAI TAP 8, CHUONG 5, DO THI---------------\n";
	cout << "1. Doc file va khoi tao do thi\n";
	cout << "2. Xuat dinh do thi bang DFS (Queue)\n";
	cout << "3. Xuat dinh do thi bang BFS (Stack)\n";
	cout << "4. Xuat dinh do thi bang BFS (De quy)\n";
	cout << "5. Kiem tra dinh x co thuoc do thi hay khong\n";
	cout << "6. Thoat\n";
	do {
		cout << "Nhap lua chon: ";
		cin >> choice;
		switch(choice) {
		case 1:
			initGraph();
			inputFromText();
			cout << "Do thi da khoi tao:\n";
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++)
					cout << a[i][j] << " ";
				cout << endl;
			}
			inputList();
			cout << endl;
			break;
		case 2:
			initQueue();
			initC();
			cout << "Nhap dinh bat dau duyet: ";
			cin >> x;
			BFS(x);
			outputBFS();
			break;
		case 3:
			initStack();
			initC();
			cout << "Nhap dinh bat dau duyet: ";
			cin >> x;
			DFS(x);
			outputDFS();
			break;
		case 4:
			initQueue();
			initC();
			cout << "Nhap dinh bat dau duyet: ";
			cin >> x;
			BFS(x);
			outputBFS();
			break;
		case 5:
			initQueue();
			initC;
			cout << "Nhap gia tri can xet: ";
			cin >> x;
			cout << "Nhap dinh xuat phat: ";
			cin >> y;
			search(x, y);
			break;
		case 6:
			cout << "Goodbye!\n";
			break;
		default:
			break;
		}
	}while(choice != 6);
	system("pause");
	return 0;
}