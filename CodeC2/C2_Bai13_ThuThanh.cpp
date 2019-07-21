//CHUONG 2 - BAI TAP 13: BAI TAP THUC HANH NHOM 7
/*Nguyen Thi Thu Thanh
MSSV: 1654050100
DA THUC - DANH SACH DAC*/
#include <stdio.h>
#include <iostream>
using namespace std;

#define MAX 100
//13.1: Khai bao cau truc danh sach
struct DaThuc
{
	int a[MAX];
	int n;
};

void KhoiTaoDaThucRong(DaThuc &dt)
{
	dt.n = 0;
	for (int i = 0; i < MAX; i++)
		dt.a[i] = 0;
}

//Nhap vao mot da thuc co dang: a + bx + cx^2 + dx^3 +.....
void input(DaThuc &dt)
{
	KhoiTaoDaThucRong(dt);
	cout<<"Nhap vao so bac cua da thuc: ";
	cin >> dt.n;
	cout<<"Nhap vao he so cua tung bac trong da thuc:"<<endl;
	for(int i = 0; i <= dt.n; i++)
	{
		cout<<"He so cua bac "<<i<<" la: ";
		cin >> dt.a[i];
	}
}

//Xuat da thuc
void output(DaThuc &dt)
{
	cout<<"->Da thuc bac "<<dt.n<<" : ";
	for(int i = 0; i <= dt.n; i++)
	{
		cout << dt.a[i]<<"*x^"<<i;
		if(i < dt.n)
			cout <<" + ";
	}
	cout<<endl;
}

DaThuc TinhTong_DaThuc(DaThuc &a, DaThuc &b)
{
	DaThuc ketqua;
	KhoiTaoDaThucRong(ketqua);
	// nếu bậc đa thức a lớn hơn bậc đa thức b
	if(a.n > b.n)
	{
		ketqua.n = a.n;  // bậc đa thức kết quả là bậc đa thức a
	}
	else
	{
		ketqua.n = b.n;
	}
	// xét hệ số đa thức kết quả:
	for(int i = 0; i <= ketqua.n; i++)
	{
		ketqua.a[i] = a.a[i] + b.a[i];
	}
	return ketqua;
}

// Tính hiệu đa thức
DaThuc TinhHieu_DaThuc(DaThuc &a, DaThuc &b)
{
	DaThuc ketqua;
	KhoiTaoDaThucRong(ketqua);
	// nếu bậc đa thức a lớn hơn bậc đa thức b
	if(a.n > b.n)
	{
		ketqua.n = a.n;  // bậc đa thức kết quả là bậc đa thức a
	}
	else
	{
		ketqua.n = b.n;
	}
	// xét hệ số đa thức kết quả:
	for(int i = 0; i <= ketqua.n; i++)
	{
		ketqua.a[i] = a.a[i] - b.a[i];
	}
	return ketqua;
}

DaThuc TinhTich_DaThuc(DaThuc a, DaThuc b)
{
	DaThuc ketqua;
	KhoiTaoDaThucRong(ketqua);

	// xét bậc đa thức kết quả
	ketqua.n = a.n + b.n; 

	// Xét hệ số đa thức kết quả
	int i, j;
	for(i = 0; i <= a.n; i++)
	{
		for(j = 0; j <= b.n; j++)
		{
			ketqua.a[i + j] += a.a[i] * b.a[j];
		}
	}
	return ketqua;
}

DaThuc TinhThuong_DaThuc(DaThuc a, DaThuc b)
{
	DaThuc ketqua;
	KhoiTaoDaThucRong(ketqua);
	if(a.n > b.n)
	{
		ketqua.n = a.n - b.n; 
	}
	else
	{
		ketqua.n = b.n - a.n; 
	}
	int i, j;
	for(i = 0; i <= a.n; i++)
	{
		for(j = 0; j <= b.n; j++)
		{
			ketqua.a[i + j] += a.a[i] / b.a[j];
		}
	}
	return ketqua;
}
int main()
{
	int choice;
	DaThuc dt1,dt2;
	system("cls");
	cout<<"-----BAI 13, CHUONG 2: DA THUC - DANH SACH DAC-----"<<endl;
	cout<<"1. Nhap da thuc"<<endl;
	cout<<"2. Xuat da thuc"<<endl;
	cout<<"3. Cong hai da thuc"<<endl;
	cout<<"4. Tru hai da thuc"<<endl;
	cout<<"5. Nhan hai da thuc"<<endl;
	cout<<"6. Chia hai da thuc"<<endl;
	cout<<"7. Thoat"<<endl;
	do
	{
		cout<<"\nVui long chon so de thuc hien: ";
		cin >> choice;
		switch(choice)
		{
		case 1:
			cout<<"Nhap vao da thuc thu nhat! "<<endl;
			input(dt1);
			cout<<"Nhap vao da thuc thu hai! "<<endl;
			input(dt2);
			break;
		case 2:
			cout<<"Da thuc thu nhat ban da nhap: ";
			output(dt1);
			cout<<"Da thuc thu hai ban da nhap: ";
			output(dt2);
			break;
		case 3:
			cout<<"Tong hai da thuc! "<<endl;
			output(TinhTong_DaThuc(dt1, dt2));
			break;
		case 4:
			cout<<"Hieu hai da thuc! "<<endl;
			output(TinhHieu_DaThuc(dt1, dt2));
			break;
		case 5:
			cout<<"Ket qua sau khi nhan hai da thuc! "<<endl;
			output(TinhTich_DaThuc(dt1, dt2));
			break;
		case 6:
			cout<<"Ket qua sau khi chia hai da thuc! "<<endl;
			output(TinhThuong_DaThuc(dt1, dt2));
			break;
		case 7:
			cout<<"Thank you - Goodbye!!!"<<endl;
			break;
		default:
			break;
		}
	}while(choice != 7);
	system("pause");
	return 0;
}