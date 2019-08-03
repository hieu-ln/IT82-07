#include <iostream>
using namespace std;

//2.1 Khai bao cau truc cay nhi phan tim kiem
struct Node {
	int info;
	Node *left;
	Node *right;
};
Node *root;
Node *createNode(int x) {
	Node *p = new Node();
	p->info = NULL;
	p->left = p->right = NULL;
	return p;
}
//2.4 Tim mot phan tu trong cay khong dung de quy
Node *find(Node *root, int x) {
	if(root == NULL)
		return NULL;
	Node *p = root;
	while(p != NULL)
		if(p->info > x)
			p = p->left;
		else
			p = p->right;
	return p;
}

//2.3 Them mot phan tu trong cay khong dung de quy
void insertNode(Node *&root, int x) {
	Node *n = createNode(x);
	if(root == NULL) {
		root = n;
		return;
	}
	else {
		Node *f = find(root, x);
		if(f != NULL)
			if(f->info > x)
				f->left = n;
			else
				f->right = n;
	}
}
int leftOf(const int value, const Node *root) {
	return value < root->info;
}
int rightOf(const int value, const Node *root) {
	return value > root->info;
}
int leftMostValue(const Node *root) {
	while(root->left != NULL)
		root = root->left;
	return root->info;
}
//2.5 Xoa mot nut trong cay dung de quy
Node *deleteNode(Node *root, int value) {
	if(root == NULL)
		return root;
	if(leftOf(value, root))
		root->left = deleteNode(root->left, value);
	else
		if(rightOf(value, root))
			root->right = deleteNode(root->right, value);
		else {
			if(root->left == NULL) {
				Node *newRoot = root->right;
				free(root);
				return newRoot;
			}
			if(root->right == NULL) {
				Node *newRoot = root->left;
				free(root);
				return newRoot;
			}
			root->info = leftMostValue(root->right);
			root->right = deleteNode(root->right, root->info);
		}
		return root;
}
void createTree(Node *&root, int a[], int n) {
	for(int i = 0; i < n; i++)
		insertNode(root, a[i]);
}