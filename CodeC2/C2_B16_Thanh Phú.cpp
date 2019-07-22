#include<iostream>
using namespace std;

struct Node
{
    Node *next;
    int data;
};

typedef Node *List;

void Init(List &l)
{
    l= NULL;
}

Node *createNode(int x)
{
    Node *p = new Node;
    if(!p) exit(1);
    p->next = NULL;
    p->data = x;
    return p;
}

void addTail(List &l, Node *p )
{
    if(!l) l = p;
    else{
        Node *pp = l;
        while(pp->next) pp = pp->next;
        pp->next = p;
    }
}

void addHead(List &l, Node *p ){
    
    p->next = l;
    l = p;
}

Node *taphop(List l1, List l2)
{
    if(!l1 && !l2) return NULL;
    Node *p = new Node;
    List l; Init(l);
    while(l1 || l2)
    {
        if(!l1 && l2)
        {
            p = l2;
            l2 = p->next;
            addHead(l,p);
        }
        
        if(!l2 && l1)
        {
            p = l1;
            l1 = p->next;
            addHead(l,p);
        }
        if (l2!=NULL && l1!=NULL)
        {
            p = l1;
            l1 = p->next;
            addHead(l,p);
        }
    }
    return l;
}
Node *giao(List l1, List l2)
{
    Node *p = new Node;p=l1;
    Node *q = new Node;q=l2;
    List l; Init(l);
    if(l1 != NULL || l2 != NULL) return NULL;
    for(p; p != NULL;p=p->next)
    {
        for (q;q != NULL;q=q->next)
        {
            if (p->data == q->data) addHead(l, q);
        }
        q=l2;
    }
    return l;
}

Node *bu(List l1, List l2)
{
    int dem =0 ;
    Node*p=new Node;p=l1;
    Node*q=new Node;q=l2;
    List l; Init(l);
    l=taphop(l1, l2);
    for (p;p!=NULL ; p=p->next)
    {
        for (q;q!=NULL ; q->next)
        {
            if (p->data==q->data)
            {
                dem ++;
            }
        }
        if (dem==0) addHead(l, p);
        q=l2;
    }
    for (q;q!=NULL ; q=q->next)
    {
        for (p;p!=NULL ; p->next)
        {
            if (p->data==q->data)
            {
                dem ++;
            }
        }
        if (dem==0) addHead(l, p);
        q=l2;
    }
    return l;
}
void xuat(List l)
{
    while(l!=NULL)
    {
        cout<< l->data;
        l = l->next;
        if (l!=NULL) cout<<"=>";
    }
    cout<< endl;
}

void nhap(List &l){
    int n, x;
    cout<<"Nhap so ptu: "; cin>> n;
    while(n--){
        cout<<"Phan tu tiep theo: ";
        cin>> x;
        Node *p = createNode(x);
        addTail(l, p);
    }
}

int main(){
    List l1, l2, l;
    Init(l1); Init(l2); Init(l1);
    nhap(l1); nhap(l2);
    xuat(l1);
    xuat(l2);
    l=bu(l1, l2);
    xuat(l);
    system("pause");
    return 0;
}
// dù đã cố nhưng em không lm đc 16.2 và 16.3 (;.;) nó không báo lỗi nhưng nó không ra lun
