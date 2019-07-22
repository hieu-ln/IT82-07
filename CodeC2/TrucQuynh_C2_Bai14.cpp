#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;


// 14.1: khai bao cau truc danh sach
struct Donthuc
{
	int heso;
	int somu;
};


struct Node
{
	Donthuc Info;
	Node*Next;
};

struct DaThuc
{
	Node*Head;
	Node*Tail;
	
};

void KhoiTao(DaThuc &L)
{
	L.Head=NULL;
	L.Tail=NULL;
}

Node *CreatNode( Donthuc x) // tao node trong danh sach, trong node co chu he so va so mu
{
	Node *p=new Node; // cap phat node
	if( p==NULL) return NULL; // kiem tra vung nho 
	p->Info=x; // luu so mu vao somu
	p->Next=NULL; // luu he so vao heso
	
	return p;
	
}

void AddHead (DaThuc &L, Node*p)
{
	if(L.Tail==NULL)
	{
		L.Head=p;
		L.Tail=p;
	}
	else
	{
		p->Next=L.Head;
		L.Head=p;
	}
	
}
 void ThemDau(DaThuc &L, Donthuc x)
 {
	 Node*p;
	 p=CreatNode(x);
	 AddHead(L,p);
 }

 void nhap(Donthuc &x)
 {
	 cout<<"Nhap vao don thuc"<<endl;
	 cout<<"Nhap vao he so "<<endl;
	 cin>>x.heso;
	 cout<<"Nhap vao so mu"<<endl;
	 cin>>x.somu;
 }
 //14.2 nhap da thuc
 void Nhap( DaThuc &L)  // co thay doi nen can tham chieu
{
	
	int n;
	Donthuc x;
	Node *p;
	p=L.Head;
	cout<<"Nhap bac cua da thuc"<<endl;
	cin>>n;
	for(int i=0; i<=n; i++)
	{
		cout<<" nhap vao he so cua x^" <<i<<":";
		nhap(x);
		ThemDau(L,x);
	}
}


 //14.4: xuat da thuc
 void XuatDathuc(DaThuc L)
 {
	 Node*p;
	 p=L.Head;
	 while(p!=NULL)
	 {
		 cout<<(p->Info).heso<<"x^"<<(p->Info).somu;
		 if(p->Next!=NULL)
			 cout<<"+";
		 p=p->Next;
	 }
 }







 //14.5 cong da thuc
 void Cong (DaThuc &L, DaThuc L1, DaThuc &L2)
{
	Node*p= new Node, *q= new Node;
	int flag;
	p=L.Head;
	while(p!=NULL)
	{
		ThemDau(L2,p->Info);
		p=p->Next;
	}
	p=L1.Head;
	q=L2.Head;
	while(q!=NULL)
	{
		p=L1.Head;
		while (p!=NULL)
		{
			if(p->Info.somu==q->Info.somu)
			{
				q->Info.heso+=p->Info.heso;
				p=p->Next;
			}
		}
		p=p->Next;
	}
	p=L1.Head;
	while (p!=NULL)
	{
		flag=0;
		q=L2.Head;
		while(q!=NULL)
		{
			if(q->Info.somu==p->Info.somu)
				flag=1;
			q=q->Next;
		}
		ThemDau(L2,p->Info);
		p=p->Next;
	}
 }

 //14.6 : tru hai da thuc
 void Tru(DaThuc &L, DaThuc &L1, DaThuc&L3)
 {
	 Node*p= new Node, *q= new Node;
	int flag;
	p=L.Head;
	while(p!=NULL)
	{
		ThemDau(L3,p->Info);
		p=p->Next;
	}
	p=L1.Head;
	q=L3.Head;
	while(q!=NULL)
	{
		p=L1.Head;
		while (p!=NULL)
		{
			if(p->Info.somu==q->Info.somu)
			{
				q->Info.heso-=p->Info.heso;
				p=p->Next;
			}
		}
		p=p->Next;
	}
	p=L1.Head;
	while (p!=NULL)
	{
		flag=0;
		q=L3.Head;
		while(q!=NULL)
		{
			if(q->Info.somu==p->Info.somu)
				flag=1;
			q=q->Next;
		}
		if (flag==0)
		{
			p->Info.heso*=-1;
			ThemDau(L3,p->Info);
			p->Info.heso*=-1;
		}
		
		p=p->Next;
	}
 }

 //14.7: Viet thu tuc nhan hai da thuc
 void Nhan(DaThuc&L, DaThuc &L1, DaThuc &Ti)
 {
	 Node*p= new Node, *q= new Node;
	 int flag;
	 p=L.Head;
	 while(p!=NULL)
	 {
		 ThemDau(Ti,p->Info);
		 p=p->Next;
	 }
	 p=L1.Head;
	 q=Ti.Head;
	 while(q!=NULL)
	 {
		 p=L1.Head;
		 while(p!=NULL)
		 {
			 q->Info.heso*=p->Info.heso;
			 q->Info.somu+=p->Info.somu;
			 p=p->Next;
		 }
		 q=q->Next;
	 }
 }	


 
int main()
{
	DaThuc L,L1,L2,L3,Ti;
	KhoiTao(L);
	KhoiTao(L1);
	KhoiTao(L2);
	KhoiTao(L3);
	KhoiTao(Ti);
	Donthuc (x);
	
	Nhap(L);

	cout<<"Da thuc can cong:"<<endl;
	Nhap(L1);
	cout<<"Hai Da thuc:";
	XuatDathuc(L);
	XuatDathuc(L1);
	Cong(L,L1,L2);
	XuatDathuc(L2);
	cout<<endl;
	cout<<"da thuc tru"<<endl;
	XuatDathuc(L);
	XuatDathuc(L1);
	Tru(L,L1,L3);
	XuatDathuc(L3);
	cout<<"Da thuc nhan"<<endl;
	XuatDathuc(L);
	XuatDathuc(L1);

	Nhan(L,L1,Ti);
	XuatDathuc(Ti);
	getch();
}