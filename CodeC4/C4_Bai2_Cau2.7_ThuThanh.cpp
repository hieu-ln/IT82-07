// Bai 2.7 Chuong 4 : Quan ly cay nhi phan 

#include <stdio.h>
#include <iostream>
using namespace std;

#define COUNT 100

// cau 1 : khai bao cau truc cay NPTK
 struct Node 
 {
	 int info;
	 Node *left;
	 Node *right;
 };
 Node *root;

 struct Stack
 {
	int info;
	Stack *link;
 };
Stack *sp;

 // cau 2: khoi tao cay rong 
  void Tree_empty()
  {
	  root = NULL;
  }

  void Init_Stack_Empty()
  {
	sp = NULL;
  }
  //cau 3: them mot phan tu vao cay (khong dung de quy)
  void InsertNode (Node *&p , int x)
  {
	  if (p == NULL)
	  {
		  p = new Node ;
		  p->info = x;
		  p->left = NULL;
		  p->right=NULL;
	  }
	  else
	  {
		  if ( p->info  == x)
			  return ;
		  else if (x < p->info)
			  InsertNode (p->left, x);
		  else 
			  InsertNode (p->right, x);
	  }
  }
  void Push(int x)
  {
	 Stack *p = new Stack;
	 p->info = x;
	 p->link = sp;
	 sp = p;
  }

int Pop(int &x)
{
	if (sp != NULL)
	{
		Stack *p = sp;
		x = p->info;
		sp = p->link;
		delete p;
		return 1;
	}
	return 0;
}

// In ra cay nhi phan TK
 void print2DUtil( Node *p, int space )
 {
	 // Base case 
	 if (p == NULL)
	 {
		 return ;
	 }
	 space += COUNT;
	 print2DUtil(p->right,space);
	 cout<< endl;
	 for (int i = COUNT ;i < space ; i++)
	 { 
		cout <<" ";
	 }
		cout << p->info <<"\n";
		print2DUtil (p->left, space);
 }
 // cau 2.7: duyet cay theo LNR
 void Process_LNR(Node *p)
{
	if (p != NULL)
	{   
		Process_LNR(p->right);
		Push(p->info);
		Process_LNR(p->left);
	}
}

 void  Process_tree()
 {
	 print2DUtil(root, 0);
 }

 int main ()
 {
	 int choice = 0;
	 int x, i;
	 Node *p;
	 system ("cls");
	 cout << " ---- BAI TAP 1_ CHUONG 4_CAY NPTK ------"<< endl;
	 cout <<"1. Khoi tao cay NPTK rong ."<< endl;
	 cout <<"2. Them phan tu vao cay NPTK ."<< endl;
	 cout <<"3. Duyet cay NPTK theo LNR."<< endl;
	 cout <<"4. Xuat cay NPTK."<< endl;
	 cout <<"5. Thoat !"<< endl;
	 do
	 {
		 cout << " Vui long chon thao tac thuc hien : ";
		 cin>> choice;
		 switch(choice)
		 {
		 case 1:
			 Tree_empty();
			 cout << " Ban vua khoi tao thanh cong cay NPTK!"<< endl;
			 break;
		 case 2:
			 cout << " Vui long nhap gia tri x can them : " ;
			 cin >> x;
			 InsertNode (root,x);
			 cout <<"  Cay NPTK sau khi them la : "<< endl;
			 Process_tree();
			 cout<<endl;
			 break;
		 case 3: 
			 cout << "Cay nhi phan tim kiem duyet theo LNR la: " << endl;
			 Process_LNR(root);
			 while (sp != NULL)
			 {
				Pop(x);
				cout << x << "\t";
			 }
			 cout << endl << endl;
			 break;
		 case 4:
			 cout << " Cay NPTK nhu sau :" << endl;
			 Process_tree();
			 break;
		 case 5:
			 cout << "Goodbye...!" << endl;
			 cout << endl;
			 break;
		 default:
			 break;
		 }
	 }
	 while (choice != 5);
	 system ("pause");
	 return 0;
 }