/ bai 2 chuong 4 
#include <iostream>
#include <stack >

using namespace std ;

//2.1 khia bao cau truc cay nhi phan 
struct Node
{
	int info ;
	Node *left ;
	Node*right;
};
Node*CreateNode (int x )
{
	Node *p = new Node();
	p->info= x;
	p->left= p->right = NULL;
	return p ;
}
// 2.4 viet thu tuc tim mot phan tu trong cay 

Node *Find ( Node *root , int x )
{
	if ( root == NULL)
	{
		return NULL;	
	}
	Node *p = root ;
	while (p != NULL)
	{
		if ( p -> info > x)
		{
			p = p ->left;
		}
		else 
		{
			p=p ->right;
		}
	}
	return p ;
}
