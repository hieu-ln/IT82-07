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
Node *first[MAX];
Node *sp;
Node *front, *rear;
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

void init ()
{
	for (int i = 0; i < n ; i++)
		first[i] = NULL;
}

#define MAX 20
struct Node 
{
	int info;
	Node *link;
};
Node *first[MAX];
int n;

void insert_first(Node *&f, int x)
{
	Node *p;
	p = new Node;
	p -> info = x;
	p -> link = f;
	f = p;
}
void input ()
{
	int d,x,m;
	cout << "Nhap so dinh do thi n: ";
	cin >> n;
	for(int i = 0; i <n; i ++)
	{
		cout << "\Nhap dinh thu " << i +1 << ":"; 
		cin >> d;
		insert_first(first[i],d);

	}
}