#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;

#define MAX 100
struct Node
{
	int info;
	Node *left;
	Node *right;
};
Node *roof;
Node* CreatNode(int x)
{
	Node* p=new Node();
	p->info=x;
	p->left=p->right=NULL;
	return p;

}




void Duyet_NLR(struct Node* roof)
{
	
	if(roof=NULL)
		return;
	stack <Node *> NodeStack;
	NodeStack.push(roof);
	while(NodeStack.empty()==false)
	{
		struct Node* tempt_Node=NodeStack.top();
		cout<<tempt_Node->info<<" ";
		NodeStack.pop();
		if(tempt_Node->right)
			NodeStack.push(tempt_Node->right);
		if(tempt_Node->left)
			NodeStack.push(tempt_Node->left);
	}
	

	
}