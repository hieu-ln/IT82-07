//BAI 6 CHUONG 5: MA TRAN KE (DANH SACH DAC)
#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

#define MAX 20
int A[MAX][MAX];
int n;//so dinh
char vertex[MAX];//ten dinh
int a[MAX]; 
int sp; //Khai bao toan cuc cho Stack
int front, rear; //Khai bao toan cuc cho Queue

//Stack
//Khoi tao Stack rong
void InitStack()
{
	sp = -1;
}

//Kiem tra Stack rong
int isEmptyS()
{
	if (sp == -1)
		return 1;
	return 0;
}

//Them mot phan tu vao Stack
int PushS(int x)
{
	if (sp < MAX -1)
	{
		a[++sp] = x;
		return 1;
	}
	return 0;
}

//Xoa mot phan tu
int PopS(int &x)
{
	if (sp != -1)
	{
		x = a[sp--];
		return 1;
	}
	return 0;
}

//Queue
//Khoi tao QUEUE rong
void InitQueue()
{
	front = -1;
	rear = -1;
}

//Kiem tra QUEUE rong
int isEmptyQ()
{
	if (front == -1)
		return 1;
	else 
		return 0;
}

//Them phan tu vao QUEUE
void PushQ(int x)
{
	if( rear == -1)
	{
		a[0] = x ;
		rear = 0;
		front = 0;
	}
	else
	{
		front = 0;		
		rear++;
		a[rear] = x;
	}
}

//Xoa 1 phan tu ra khoi QUEUE
void PopQ(int &x)
{
	if (rear == 0)
	{
		rear--;
		x = a[0];			
	}
	else if(rear > 0)
	{	
		int m = rear; 
		x = a[0];
		for (int i = m ; i > 0; i--)	
			a[i - 1] = a[i];	
		rear--;
	}	
	else if (rear == -1) 
	{
		front = -1;
	}		
}

//Nhap ma tran tu file

void InitGraph()
{
	n=0;
}

void InputGraphFromText()
{
	string line;
	ifstream myfile ("matranke1.txt");
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

//Cau 6.1: Nhap ma tran ke cua do thi
void inputGraph()
{
	cout << "Nhap so dinh cua do thi n: ";
	cin >> n;
	cout << "Nhap ten dinh: ";
	for (int i = 0; i <n; i++)
	{
		cin >> vertex[i];
	}

	for (int i = 0; i <n; i++)
	{
		cout << "Nhap vao dong thu "<< i + 1 << ": ";
		for (int j = 0; j < n; j++)
			cin >> A[i][j];
	}
}
//Cau 6.2: Xuat ma tran ke cua do thi
void outputGraph()
{
	for (int i=0; i<n; i++)
	{
		for (int j = 0; j < n ; j++)
			cout << A[i][j] << " ";
		cout << endl;
	}
}

void output(int b[], int n)
{
	for (int i = 0;i < n; i++)
		cout << vertex [b[i]] << " ";
}


//Cau 6.3: Duyet do thi theo chieu rong BFS (Dung QUEUE va DS DAC)
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
	while (front != -1)
	{
		PopQ(p);
		bfs[nbfs] = p;
		nbfs++;
		for (w= 0; w < n; w++)
			if (C[w] && A[p][w] == 1)
			{
				C[w] = 0;
				PushQ(w);
			}
	}
}

//Cau 6.4: Duyet do thi theo chieu sau DFS (Dung QUEUE va DS DAC)
int dfs[100];
int ndfs = 0;
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

//Cau 6.5: Dung BFS tim x tren do thi
void Search_by_BFS(int x, int v)// v la dinh bat dau
{
	int w, p;
	PushQ(v);
	C[v] = 0;
	while (isEmptyQ() == 0)
	{
		PopQ(p);
		if(x == p)
		{
			cout << "Tim thay x = " << x << endl;
			return;
		}
		for (w= 0; w <n; w++)
			if( C[w] && A[p][w] == 1)
			{
				PushQ(w);
				C[w] = 0;
			}
	}
	cout <<"Khong tim thay x = "<<x<<" !"<<endl;
}

int main()
{
	InitQueue();
	int choice, x, i;
	system("cls");
	cout << "----------BAI TAP 6, CHUONG 5: MA TRAN KE (DS DAC)----------" << endl;
	cout << "1. Khoi tao ma tran ke rong" << endl;
	cout << "2. Nhap ma tran ke tu file text" << endl;
	cout << "3. Nhap ma tran ke" << endl;
	cout << "4. Xuat ma tran ke" << endl;
	cout << "5. Duyet do thi theo chieu rong BFS - DSLK" << endl;
	cout << "6. Duyet do thi theo chieu rong DFS - DSLK" << endl;
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
			cout << "Ban vua nhap MA TRAN KE tu file: \n";
			outputGraph();
			break;
		case 3:
			inputGraph();
			break;
		case 4:
			outputGraph();
			break;
		case 5: 
			InitQueue();
			InitC();
			cout << "Vui long nhap dinh xuat phat: ";
			cin >> x;
			nbfs = 0;
			BFS(x);
			cout << "Thu tu dinh sau khi duyet BFS: " << endl;
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
			output(dfs, n);
			break;
		case 7: 
			InitQueue();
			InitC();
			nbfs = 0;
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