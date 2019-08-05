#include <iostream>
#include <stdio.h>
using namespace std;

#define COUNT 100

//1. khai bao cau truc tim kiem cay nhi phan
struct Node
{
	int info;
	Node *left;
	Node *right;
};
Node *roof;

// 2. Thu tuc tao cay rong
void Tree_emty()
{
	roof=NULL;
}

//3. Them 1 phan tu vao cay (dung de quy)
int Insert_Node(int x, Node*q)
{
	if(q->info==x)
		return 0;
	else if(q->info > x)
	{
		if (q->left ==NULL)
		{
			Node*p=new Node;
			p->info=x;
			p->left=NULL;
			p->right=NULL;
			q->left=p;
			return 1;

		}
		else
			return Insert_Node(x,q->right);

	}
}

//Them phan tu su dung de quy, dung con tro
void Insert_NodeTro( Node *&p, int x)
{
	if(p==NULL)
	{
		p=new Node;
		p->info=x;
		p->left=NULL;
		p->right=NULL;
	}
	else
	{
		if(p->info ==x)
			return;
		else if (p->info >x)
			return Insert_NodeTro(p->left,x);
		else
		return Insert_NodeTro(p->right,x);
	}
}

// 4. Tim mot phan tu trong cay su dung de quy
Node *Search (Node *p, int x)
{
	if( p!=NULL)
	{
		if(p->info==x)
			return p;
		else if (x > p->info)
			return Search (p->right,x);
		else
			return Search(p->left,x);

	}
	return NULL;
}

// 5. xoa mot nut trong cay su dung de quy
void SearchStand(Node *&p, Node *&q)
{
	if(q->left ==NULL)
	{
		p->info=q->info; // p là node bi xoa, q la node cuc trai di do tim
		p=q;
		q=q->right;
	}
	else
		SearchStand(p,q->left);
		
}
int Delete (Node *&T, int x)
{
	if(T==NULL)
		return 0;
	if (T->info==x)
	{
		Node *p =T;
		if(T->left==NULL)
			T=T->right;
		else if (T->right==NULL)
			T=T->left;
		else
			SearchStand(p,T->right);
		delete p;
		return 1;

	}
	if (T->info <x)
		return Delete(T->right,x);
	if (T->info >x)
		return Delete (T->left,x);
}

// 6.Duyet cay theo NLR dung de quy
void DuyetNLR(Node *p)
{
	if(p!=NULL)
	{
		cout<<p->info<<" ";
		DuyetNLR(p->left);
		DuyetNLR(p->right);
	}
}

// 7. duyet cay theo LNR dung de quy
void DuyetLNR(Node *p)
{
	if(p!=NULL) // duyet node con ben trai cua node p
	{
		DuyetLNR(p->left);
		cout<<p->info<<" ";
		DuyetLNR(p->right);
	}
}

// 8. duyet cay theo LRN
void DuyetLRN(Node *p)
{
	if(p!=NULL)
	{
		DuyetLRN(p->left);
		DuyetLNR(p->right);
		cout<<p->info<<" ";

	}
}

void print2DUtil( Node *p, int space )
 {
	 // Base case 
	 if (p == NULL)
		 return ;
	 space += COUNT;
	 print2DUtil(p->right,space);
	 cout<< endl;
	 for (int i = COUNT ;i < space ; i++)
		 cout <<" ";
	 cout << p->info <<"\n";
	 print2DUtil (p->left, space);
 }

 void  Process_tree()
 {
	 print2DUtil(roof, 0);
 }


int main()
{
	int choice = 0;
	 int x, i;
	 Node *p;
	 system ("cls");
	 cout << " ---- BAI TAP 1_ CHUONG 4_CAY NPTK ------"<< endl;
	 cout <<"1. Khoi tao cay NPTK rong ."<< endl;
	 cout <<"2. Them phan tu vao cay NPTK ."<< endl;
	 cout <<"3. Tim phan tu co gia x trong cay NPTK."<< endl;
	 cout <<"4. Xoa phan tu co gia tri x trong cay NPTK."<< endl;
	 cout <<"5. Duyet cay NPTK theo NLR."<< endl;
	 cout <<"6. Duyet cay NPTK theo LNR."<< endl;
	 cout <<"7. Duyet cay NPTK theo LRN."<< endl;
	 cout <<"8. Xuat cay NPTK."<< endl;
	 cout <<"9. Thoat !"<< endl;
	 do
	 {
		 cout << " Vui long chon thao tac thuc hien : ";
		 cin>> choice;
		 switch(choice)
		 {
		 case 1:
			 Tree_emty();
			 cout << " Ban vua khoi tao thanh cong cay NPTK!"<< endl;
			 break;
		 case 2:
			 cout << " Vui long nhap gia tri x can them : " ;
			 cin >> x;
			 Insert_NodeTro(roof,x);
			  Process_tree();
			 break;
		 case 3:
			 cout << " Vui long nhap gia tri x can tim : "<< endl;
			 cin >> x;
			 p = Search(roof,x);
			 if ( p !=NULL)
				 cout<< " Tim thay  x = "<< x<< " trong cay TKNP " << endl;
			 else 
				 cout << " Khong tim thay x = " << x<< " trong cay NPTK"<< endl;
			 break;
		 case 4:
			 cout << " Vui long nhap nhap gia tri x can xoa : " ;
			 cin >> x;
			 i= Delete ( roof, x);
			 if ( i == 0)
				  cout << " khong tim thay x = "<< x << " de xoa "<< endl;
			 else 
				  {
				 cout<< " Da xoa thanh cong x= "<< x<<" trong cay tKNP"<< endl;
				 cout << " cay NPTK  sau khi xoa : "<< endl;
				 Process_tree();
			 }
			 break;
		 case 5:
			 cout << " Cay NPTK duyet theo NLR la : " << endl;
			 DuyetNLR(roof);
			 break;
		 case 6:
			 cout << " Cay NPTK duyet theo LNR la : " << endl;
			 DuyetLNR(roof);
			 break;
		 case 7: 
			 cout << " Cay NPTK duyet theo LNR la : " << endl;
			 DuyetLRN(roof);
			 break;
		 case 8:
			 cout << " Cay NPTK nhu sau :" << endl;
			 Process_tree();
			 break;
		 default:
			 break;
		 }
	 }
	 while (choice != 9);
	 system ("pause");
	 return 0;

}