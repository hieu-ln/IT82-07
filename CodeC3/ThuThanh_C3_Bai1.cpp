//Chuong 3: Bai 1 _ Xep thu tu, tim kiem
#include <stdio.h>
#include <iostream>
#include <ctime>
using namespace std;

#define MAX 100
//Cau 1.1
int a[MAX];
int n;

//Cau 1.2.0: Nhap danh sach tu dong 
void init (int a[], int &n)
{
	cout << "Nhap vao so luong phan tu cua danh sach: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 10000 + 1;
	}
	cout << "Danh sach da duoc nhap ngau nhien nhu sau: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "  ";
	}
	cout << endl;
}

//Cau 1.2.1: Nhap danh sach 
void input (int a[], int &n)
{
	cout << "Nhap vao so luong phan tu cua danh sach: ";
	cin >> n;
	cout << "Nhap vao cac phan tu cua danh sach: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}
	
}

//Cau 1.3: Xuat danh sach
void output (int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "  ";
	}
	cout << endl;
}

void CopyArray (int a[], int b[], int n)
{
	for (int i = 0; i < n; i++)
	{
		b[i] = a[i];
	}
}

//Cau 1.4: Insertion Sort
void insertionSort (int a[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = a[i];
		j = i - 1;

		/* Di chuyển các phần tử có giá trị lớn hơn giá trị key
		về sau một vị trí so với vị trí ban đầu của nó */
		while (j >= 0 && a[j] > key)
		{
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = key;
	}
}

//ham doi cho 2 so nguyen
void swap (int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}

//Cau 1.5: Selection Sort
void selectionSort (int a[], int n)
{
	int i, j, min_idx;
	//Di chuyển ranh giới của mảng đã sắp xếp và chưa sắp xếp
	for (i = 0; i < n - 1; i++)
	{
		//Tìm phần tử nhỏ nhất trong mảng chưa sắp xếp
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (a[j] < a[min_idx])
				min_idx = j;

		//Đổi chỗ phần tử nhỏ nhất với phần tử đầu tiên
		swap(a[min_idx], a[i]);
	}
}

//Cau 1.6: Interchange Sort
void interchangeSort (int a[], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] > a[j])
				swap(a[i], a[j]); //Đổi chỗ
}

//Cau 1.7: Bubble Sort
void bubbleSort (int arr[], int n)
{
	int i, j;
	bool haveSwap = false;
	for (i = 0; i < n -1 ; i++)
	{
		//i phần tử cuối cùng đã được sắp xếp
		haveSwap = false;
		for (j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
				haveSwap = true; //kiểm tra lần nhập này có swap không
			}	
		}
		//Nếu không có swap nào thực thiện => mảng đã được sắp xếp. Không cần lặp thêm
		if (haveSwap == false)
			break;
	}
}

int partition (int a[], int low, int high)
{
	int pivot = a[high];
	int left = low;
	int right = high - 1;
	while (true)
	{
		while (left <= right && a[left] < pivot) left ++;
		while (right >= left && a[right] > pivot) right --;
		if (left >= right) break;
		swap (a[left], a[right]);
		left++;
		right--;
	}
	swap (a[left], a[high]);
	return left;
}
//Cau 1.8: QUICK SORT
void quickSort(int a[], int left, int right)
{
	int x = a[(left + right)/2];
	int i = left;
	int j = right;
	while (i < j)
	{
		while (a[i] < x)
			i++;
		while (a[j] > x)
			j--;
		if( i <= j)
		{
			swap (a[i], a[j]); //doi cho
			i++;
			j--;
		}
	}
	if (left < j)
			quickSort(a, left, j);
	if (i < right)
		quickSort(a,i,right);
}

//Cau 1.9: HEAP SORT
void heapify(int a[], int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && a[l] > a[largest])
		largest = l;

	if (r < n && a[r] > a[largest])
		largest = r;

	if (largest != i)
	{
		swap(a[i], a[largest]);

		heapify(a, n, largest);
	}
}
void heapSort (int a[], int n)
{
	for (int i = n/2 - 1; i >= 0; i--)
		heapify(a, n, i);

	for (int i = n - 1; i >= 0; i--)
	{
		swap(a[0], a[i]);

		heapify(a, i, 0);
	}
}

//Cau 1.10: Tim kiem tuan tu
int searchSequence (int a[], int n, int x)
{
	int i = 0;
	while (i < n && a[i] != x)
	{
		i++;
	}
	if (i == n)
		return -1;
	else
		return i;
}

//Cau 1.11: Tim kiem nhi phan
int searchBinary (int a[], int l, int r, int x)
{
	if (r >= l)
	{
		int mid = l + (r - l) / 2; //Tương đương (l+r)/2 nhưng ưu điểm để tránh tràn số khi l, r lớn

		//Nếu a[mid] = x, trả về chỉ số và kết thúc
		if (a[mid] == x)
			return mid;

		//Nếu a[mid] > x, thực hiện tìm kiếm nửa trái của hàm
		if (a[mid] > x)
			return searchBinary(a, l, mid - 1, x);

		//Nếu a[mid] < x, thực hiện tìm kiếm nửa phải của hàm
		return searchBinary(a, mid + 1, r, x);
	}
	 // Nếu không tìm thấy
	return -1;
}

int main()
{
	int b[MAX];
	clock_t start;
	double duration;
	int choice, x, i;
	system("cls");
	cout << " -------- BAI TAP 1, CHUONG 3, XEP THU TU & TIM KIEM --------" << endl;
	cout << "0. Khoi tao danh sach ngau nhien" << endl;
	cout << "1. Nhap danh sach" << endl;
	cout << "2. Xuat danh sach" << endl;
	cout << "3. Xep thu tu danh sach bang Selection Sort" << endl;
	cout << "4. Xep thu tu danh sach bang Insertion Sort " << endl;
	cout << "5. Xep thu tu danh sach bang Bubble Sort" << endl;
	cout << "6. Xep thu tu danh sach bang Interchange Sort" << endl;
	cout << "7. Xep thu tu danh sach bang Quick Sort" << endl;
	cout << "8. Xep thu tu danh sach bang Heap Sort" << endl;
	cout << "9. Tim kem phan tu x bang TIM KIEM TUAN TU" << endl;
	cout << "10. Tim kem phan tu x bang TIM KIEM NHI PHAN" << endl;
	cout << "11. Thoat" << endl;

	do
	{
		cout << "\nVui long chon so de thuc hien: ";
		cin >> choice;

		switch(choice)
		{
			case 0: //Khởi tạo random
				init(a,n);
				break;
			case 1:
				input(a,n);
				break;

			case 2:
				cout << "Danh sach la: " << endl;
				output(a,n);
				break;

			case 3:
				CopyArray(a,b,n);
				start = clock();
				selectionSort(b,n);
				duration = (clock() - start) / (double) CLOCKS_PER_SEC;
				if (n < 100)
				{
					cout << "DS sau khi xap thu tu voi Selection Sort la: " << endl;
					output(b,n);
				}
				if (duration > 0)
					cout << "Thoi gian Selection Sort: " << duration * 1000000 << " Microseconds" << endl;
				break;

			case 4:
				CopyArray(a,b,n);
				start = clock();
				insertionSort(b,n);
				duration = (clock() - start) / (double) CLOCKS_PER_SEC;
				if (n < 100)
				{
					cout << "DS sau khi xap thu tu voi Intertion Sort la: " << endl;
					output(b,n);
				}
				if (duration > 0)
					cout << "Thoi gian Intertion Sort: " << duration * 1000000 << " Microseconds" << endl;
				break;

			case 5:
				CopyArray(a,b,n);
				start = clock();
				bubbleSort(b,n);
				duration = (clock() - start) / (double) CLOCKS_PER_SEC;
				if (n < 100)
				{
					cout << "DS sau khi xap thu tu voi Bubble Sort la: " << endl;
					output(b,n);
				}
				if (duration > 0)
					cout << "Thoi gian Bubble Sort: " << duration * 1000000 << " Microseconds" << endl;
				break;


			case 6:
				CopyArray(a,b,n);
				start = clock();
				interchangeSort(b,n);
				duration = (clock() - start) / (double) CLOCKS_PER_SEC;
				if (n < 100)
				{
					cout << "DS sau khi xap thu tu voi Interchange Sort la: " << endl;
					output(b,n);
				}
				if (duration > 0)
					cout << "Thoi gian Interchange Sort: " << duration * 1000000 << " Microseconds" << endl;
				break;

			case 7:
				CopyArray(a,b,n);
				start = clock();
				quickSort(b, 0, n-1);
				duration = (clock() - start) / (double) CLOCKS_PER_SEC;
				if (n < 100)
				{
					cout << "DS sau khi xap thu tu voi Quick Sort la: " << endl;
					output(b,n);
				}
				if (duration > 0)
					cout << "Thoi gian Quick Sort: " << duration * 1000000 << " Microseconds" << endl;
				break;

			case 8:
				CopyArray(a,b,n);
				start = clock();
				heapSort(b,n);
				duration = (clock() - start) / (double) CLOCKS_PER_SEC;
				if (n < 100)
				{
					cout << "DS sau khi xap thu tu voi Heap Sort la: " << endl;
					output(b,n);
				}
				if (duration > 0)
					cout << "Thoi gian Heap Sort: " << duration * 1000000 << " Microseconds" << endl;
				break;

			case 9:
				cout << "Vui long nhap gia tri x = ";
				cin >> x;
				start = clock();
				i = searchSequence(a,n,x);
				if (i == -1)
					cout << "Khong tim thay x = " << x << " trong mang!" << endl;
				else
					cout << "Tim thay x = " << x << " tai vi tri i = " << i << endl;
				duration = (clock() - start) / (double) CLOCKS_PER_SEC;
				if (duration > 0)
					cout << "Thoi gian tiem kiem TUAN TU la: " << duration * 1000000 << " Microseconds" << endl;
				break;

			case 10:
				cout << "Vui long nhap gia tri x = ";
				cin >> x;
				start = clock();
				i = searchBinary(b,0,n,x);
				duration = (clock() - start) / (double) CLOCKS_PER_SEC;
				if (i == -1)
					cout << "Khong tim thay x = " << x << " trong mang!" << endl;
				else
					cout << "Tim thay x = " << x << " tai vi tri i = " << i << endl;
				
				if (duration > 0)
					cout << "Thoi gian tiem kiem NHI PHAN la: " << duration * 1000000 << " Microseconds" << endl;
				break;

			case 11: 
				cout << "\nGoodbye!" <<endl;
				break;
			default:
				break;
		}

	}while (choice != 11);
	system ("pause");
	return 0;
}