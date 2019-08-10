#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

//Khai bao ma tran bang mang hai chieu
#define max 20
int a[max][max];
int n; //So dinh cua do thi
char vertex[max]; //Ten dinh

void initGraph() {
	n = 0;
}

void inputGraphFromText() {
	string line;
	ifstream myFile("mat.txt");
	if(myFile.is_open()) {
		myFile >> n;
		for(int i = 0; i < n; i++)
			myFile >> vertex[i];
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				myFile >> a[i][j];
	}
}

void inputGraph() {
	cout << "Nhap so dinh cua do thi: ";
	cin >> n;
	cout << "Nhap ten dinh: ";
	for(int i = 0; i < n; i++)
		cin >> vertex[i];
	for(int i = 0; i < n; i++) {
		cout << "Nhap vao dong thu " << i + 1 << ": ";
		for(int j = 0; j < n; j++)
			cin >> a[i][j];
	}
}

//Xuat ma tran ke cua do thi
void outputGraph() {
	cout << setw(6) << left;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++)
			cout << a[i][j] << setw(6) << left;
		cout << endl;
	}
}

//Khai bao tap E
int E1[max], E2[max], wE[max], nE = 0; //nE so phan tu tap E
//Khai bao tap T
int T1[max], T2[max], wT[max], nT = 0; //nT so phan tu tap T

int existence(int d, int D[], int nD) {
	for(int i = 0; i < nD; i++)
		if(D[i] == d)
			return 1;
	return 0;
}

void delLocationE(int i) {
	for(int j = 0; j < nE; j++) {
		E1[j] = E1[j + 1];
		E2[j] = E2[j + 1];
		wE[j] = wE[j + 1];
	}
	nE--;
} // Xoa vi tri E

void delEdgeE(int u, int v) {
	for(int i = 0; i < nE; i++)
		if(E1[i] == u && E2[i] == v) {
			delLocationE(i);
			break;
		}
} // Xoa canh E

void prim(int s) { //s la dinh bat dau
	int u = s, min, i, d1, d2;
	while(nT < n - 1) {
		for(int v = 0; v < n; v++)
			if(!existence(v, T2, nT)) { //existence == 0; ton tai == 0
				E1[nE] = u;
				E2[nE] = v;
				wE[nE] = a[u][v];
				nE++;
			}
		for(int i = 0; i < nE; i++)
			if(!existence(E2[i], T2, nT)) {
				min = wE[i];
				d1 = E1[i];
				d2 = E2[i];
				break;
			}
		for(int i = 0; i < nE; i++)
			if(!existence(E2[i], T2, nT))
				if(min > wE[i]) {
					min = wE[i];
					d1 = E1[i];
					d2 = E2[i];
				}
		T1[nT] = d1;
		T2[nT] = d2;
		wT[nT] = a[d1][d2];
		a[d1][d2] = 0;
		a[d2][d1] = 0;
		nT++;
		delEdgeE(d1, d2);
		u = d2;
	}
}

void output(bool vertexName) {
	int sum = 0;
	for(int i = 0; i < nT; i++) {
		if(vertexName)
			cout << endl << "(" << vertex[T1[i]] << "," << vertex[T2[i]] << ") - " << wT[i];
		else
			cout << endl << "(" << T1[i] << "," << T2[i] << ") - " << wT[i];
		sum += wT[i];
	}
	cout << "\nTong trong so: " << sum << endl;
}

int main() {
	int x, choice, i;
	system("cls");
	cout << "---------------BAI TAP 4, CHUONG 6, CAY KHUNG TOI THIEU---------------\n";
	cout << "1. Khoi tao ma tran ke rong\n";
	cout << "2. Nhap ma tran ke tu file text\n";
	cout << "3. Nhap ma tran ke thu cong\n";
	cout << "4. Xuat ma tran ke\n";
	cout << "5. Tim cay khung toi thieu bang giai thuat Prim\n";
	cout << "6. Thoat\n";
	do {
		cout << "Nhap lua chon: ";
		cin >> choice;
		switch(choice) {
		case 1:
			initGraph();
			cout << "Khoi tao ma tran ke thanh cong\n";
			break;
		case 2:
			inputGraphFromText();
			cout << "Nhap ma tran ke tu file: ";
			outputGraph();
			break;
		case 3:
			inputGraph();
			break;
		case 4:
			outputGraph();
			break;
		case 5:
			cout << "Nhap gia tri dinh xuat phat: ";
			cin >> x;
			prim(x);
			cout << "Cay khung toi thieu sau khi dung giai thuat Prim:\n";
			output(true);
			break;
		case 6:
			cout << "Goodbye!\n";
			break;
		default:
			break;
		}
	}while(choice != 6);
	system("pause");
	return 0;
}