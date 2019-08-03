//#include <iostream>
//using namespace std; 
//#define COUNT 100
//
////1.1 Khai bao cau truc cay nhi phan tim kiem
//struct Node {
//	int info;
//	Node *left;
//	Node *right;
//};
//Node *root;
//
////1.2 Khoi tao cay rong
//void init() {
//	root = NULL;
//}
//
////1.3 Them mot phan tu vao cay dung de quy khong su dung dia chi con tro
//int insertNodeRecursive(int x, Node *q) {
//	if(q->info == x)
//		return 0;
//	else if(q->info > x) {
//		if(q->left == NULL) {
//			Node *p = new Node;
//			p->info = x;
//			p->left = NULL;
//			p->right = NULL;
//			q->left = p;
//			return 1;
//		}
//		else
//			return insertNodeRecursive(x, q->left);
//	}
//	else
//		if(q->right == NULL) {
//			Node *p = new Node;
//			p->info = x;
//			p->left = NULL;
//			p->right = NULL;
//			q->right = p;
//			return 1;
//		}
//		else
//			return insertNodeRecursive(x, q->right);
//}
//
////1.3b Them mot phan tu trong cay dung de quy co su dung dia chi con tro
//void insertNode(Node *&p, int x) {
//	if(p == NULL) {
//		p = new Node;
//		p->info = x;
//		p->left = NULL;
//		p->right = NULL;
//	}
//	else {
//		if(p->info == x)
//			return;
//		else
//			if(p->info > x)
//				return insertNode(p->left, x);
//			else
//				return insertNode(p->right, x);
//	}
//}
//
////1.4 Tim mot phan tu dung de quy
//Node *search(Node *p, int x) {
//	if(p != NULL) {
//		if(p->info == x)
//			return p;
//		else
//			if(x > p->info)
//				return search(p->right, x);
//			else
//				return search(p->left, x);
//	}
//	return NULL;
//
//}
//
////1.5 Xoa mot nut trong cay dung de quy
//void searchStandFor(Node *&p, Node *&q) {
//	if(q->left == NULL) {
//		p->info = q->info;
//		p = q;
//		q = q->right;
//	}
//	else
//		searchStandFor(p, q->left);
//}
//int deleteNode(Node *&t, int x) {
//	if(t == NULL)
//		return 0;
//	if(t->info == x) {
//		Node *p = t;
//		if(t->left == NULL) //LV1
//			t = t->right;
//		else
//			if(t->right == NULL) //LV1
//				t = t->left;
//			else //LV2
//				searchStandFor(p, t->right);
//		delete p;
//		return 1;
//	}
//	if(t->info < x)
//		return deleteNode(t->right, x);
//	if(t->info > x)
//		return deleteNode(t->left, x);
//}
//
////1.6 Duyet cay theo LNR dung de quy
//void processLNR(Node *p) {
//	if(p != NULL) {
//		processLNR(p->left);
//		cout << p->info << " ";
//		processLNR(p->right);
//	}
//}
//
////1.7 Duyet cay theo NLR dung de quy
//void processNLR(Node *p) {
//	if(p != NULL) {
//		cout << p->info << " ";
//		processNLR(p->left);
//		processNLR(p->right);
//	}
//}
//
////1.8 Duyet cay theo LRN dung de quy
//void processLRN(Node *p) {
//	if(p != NULL) {
//		processLRN(p->left);
//		processLNR(p->right);
//		cout << p->info << " ";
//	}
//}
//void printTree(Node *p, int space) {
//	if(p == NULL)
//		return;
//	space += COUNT;
//	printTree(p->right, space);
//	cout << endl;
//	for(int i = COUNT; i < space; i++)
//		cout << " ";
//	cout << p->info << endl;
//	printTree(p->left, space);
//}
//void processTree() {
//	printTree(root, 0);
//}
//int main() {
//	int choice, x, i;
//	Node *p;
//	system("cls");
//	cout << "---------------BAI TAP 1, CHUONG 4, CAY NHI PHAN TIM KIEM---------------\n";
//	cout << "1. Khoi tao cay nhi phan rong\n";
//	cout << "2. Them phan tu vao cay\n";
//	cout << "3. Tim kiem phan tu co gia tri x trong cay\n";
//	cout << "4. Xoa phan tu co gia tri x trong cay\n";
//	cout << "5. Duyet LNR\n";
//	cout << "6. Duyet NLR\n";
//	cout << "7. Duyet LRN\n";
//	cout << "8. Xuat cay nhi phan tim kiem\n";
//	cout << "9. Thoat\n";
//	do {
//		cout << "Nhap lua chon: ";
//		cin >> choice;
//		switch(choice) {
//		case 1:
//			init();
//			cout << "Khoi tao thanh cong\n";
//			break;
//		case 2:
//			cout << "Nhap gia tri x can them: ";
//			cin >> x;
//			insertNode(root, x);
//			cout << "Cay sau khi them: ";
//			processTree();
//			break;
//		case 3:
//			cout << "Nhap gia tri x can tim: ";
//			cin >> x;
//			p = search(root, x);
//			if(p != NULL)
//				cout << "Tim thay x =" << x << "trong cay NPTK\n";
//			break;
//		case 4:
//			cout << "Nhap gia tri x can xoa: ";
//			cin >> x;
//			i = deleteNode(root, x);
//			if(i) {
//				cout << "Da xoa thanh cong, cay sau khi xoa la: ";
//				processTree();
//			}
//			break;
//		case 5:
//			cout << "Duyet LNR: ";
//			processLNR(root);
//			break;
//		case 6:
//			cout << "Duyet NLR: ";
//			processNLR(root);
//			break;
//		case 7:
//			cout << "Duyet LRN: ";
//			processLRN(root);
//			break;
//		case 8:
//			processTree();
//			break;
//		case 9:
//			cout << "Goodbye!\n";
//			break;
//		default:
//			break;
//		}
//	}while(choice != 9);
//	system("pause");
//	return 0;
//}
