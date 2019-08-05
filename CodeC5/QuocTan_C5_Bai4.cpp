#include <iostream>
#include <fstream>
using namespace std;

#define MAX 20
int a[MAX][MAX];
int n;
char vertex[MAX];

// DSLK su dung cho stack va queue
struct Node {
	int info;
	Node *link;
};
Node *sp;
Node *front, *rear;
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
// Graph
void initGraph() {
	n = 0;
}
void inputGrapFromText() {
	string line;
	ifstream myFile("matranke1.txt");
	if(myFile.is_open()) {
		myFile >> n;
		for(int i = 0; i < n; i++)
			myFile >> vertex[i];
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				myFile >> a[i][j];
	}
}
//4.1 Nhap ma tran ke cua do thi
void inputGraph() {
	cout << "Nhap so dinh do thi: ";
	cin >> n;
	for(int i = 0; i < n; i++) {
		cout << "Nhap ten dinh: ";
		cin >> vertex[i];
		cout << "Nhap vao dong thu " << i + 1 << " : ";
		for(int j = 0; j < n; j++)
			cin >> a[i][j];
	}
}
//4.2 Xuat ma tran ke do thi
void outputGraph() {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
}
void output(int a[], int n) {
	for(int i = 0; i < n; i++)
		cout << vertex[a[i]] << " ";
}
//4.3 Duyet do thi theo chieu rong BFS (dung queue va dslk don)
int c[100], bfs[100];
int nbfs = 0;
void initC() {
	for(int i = 0; i < n; i++)
		c[i] = 1;
}
void BFS(int v) {
	int w, p;
	pushQueue(v);
	c[v] = 0;
	while(front != NULL) {
		popQueue(p);
		bfs[nbfs] = p;
		nbfs++;
		for(w = 0; w < n; w++)
			if(c[w] && a[p][w] == 1) {
				pushQueue(w);
				c[w] = 0;
			}
	}
}
//4.4 Duyet do thi theo chieu sau DFS (dung stack va dslk don)
int dfs[100];
int ndfs = 0;
void DFS(int s) {
	pushStack(s);
	dfs[ndfs] = s;
	ndfs++;
	c[s] = 0;
	int v = -1, u = s;
	while(isEmptyStack() == 0) {
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
//4.5 Dung BFS tim x tren do thi
void searchByBFS(int x, int v) {
	int w, p;
	pushQueue(v);
	c[v] = 0;
	while(front != NULL) {
		popQueue(p);
		if(x == p) {
			cout << "Tim thay " << x << endl;
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
	int a[MAX], b[MAX], choice, sp, sp_b, x, i;
	system("cls");
	cout << "---------------BAI TAP 4, CHUONG 6, DO THI---------------\n";
	cout << "1. Khoi tao ma tran ke rong\n";
	cout << "2. Nhap ma tran ke tu file text\n";
	cout << "3. Nhap ma tran ke\n";
	cout << "4. Xuat ma tran ke\n";
	cout << "5. Duyet do thi theo chieu rong BFS - DSLK\n";
	cout << "6. Duyet do thi theo chieu sau DFS - DSLK\n";
	cout << "7. Tim dinh co gia tri x theo BFS\n";
	cout << "8. Thoat\n";
	do {
		cout << "Nhap lua chon: ";
		cin >> choice;
		switch(choice) {
		case 1:
			initGraph();
			cout << "Khoi tao ma tran ke thanh cong\n";
			break;
		case 2:
			inputGrapFromText();
			cout << "Nhap ma tran ke tu file thanh cong\n";
			outputGraph();
			break;
		case 3:
			inputGraph;
			break;
		case 4:
			outputGraph();
			break;
		case 5:
			initQueue();
			initC();
			cout << "Nhap dinh xuat phat: ";
			cin >> x;
			nbfs = 0;
			BFS(x);
			cout << "Thu tu dinh sau khi duyet BFS:\n";
			output(bfs, n);
			break;
		case 6:
			initStack();
			initC();
			cout << "Nhap dinh xuat phat: ";
			cin >> x;
			ndfs = 0;
			DFS(x);
			cout << "Thu tu dinh sau khi duyet DFS:\n";
			output(dfs, n); 
			break;
		case 7:
			cout << "Nhap gia tri x can tim: ";
			cin >> x;
			searchByBFS(x, 0);
			break;
		case 8:
			cout << "Goodbye!\n";
			break;
		default:
			break;
		}
	}while(choice != 8);
	system("pause");
	return 0;
}
