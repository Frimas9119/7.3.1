#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;
void Create(int** a, const int k, const int n, const int Low, const int High);
void Print1(int** a, const int k, const int n);
void Print2(int* b, const int k);
void Math1(int** a, int* b, const int k, const int n);

int main()
{
	srand((unsigned)time(NULL));
	int Low = -10;
	int High = 10;
	int n;
	int k;
	int z=0;
	cout << "n = "; cin >> n;
	cout << "k = "; cin >> k;
	int** a = (int**) new int[k][5];
	int* b = new int [k];
	for (int i = 0; i < k; i++)
		a[i] = new int[n];
	Create(a, k, n, Low, High);
	for (int i = 0; i < k; i++) {
		for (int j = 0;j < n;j++) {
			if (a[i][j] < 0) {
				z = z - a[i][j];
			}
		}
		b[i] = z;
		z = 0;
	}
	Print1(a, k, n);
	Print2(b, k);
	Math1(a, b, k, n);
	Print2(b, k);
	Print1(a, k, n);
	for (int i = 0; i < k; i++)
		delete[] a[i];
	delete[] a;
	delete[] b;
	return 0;
}
void Create(int** a, const int k, const int n, const int Low, const int High)
{
	for (int i = 0; i < k; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = Low + rand() % (High - Low + 1);

}
void Print1(int** a, const int k, const int n)
{
	cout << endl;
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}
void Print2(int* b, const int k)
{
	cout << endl;
	for (int i = 0; i < k; i++)
	{
			cout << b[i];
		cout << endl;
	}
	cout << endl;
}
void Math1(int** a, int* b, const int k, const int n) {
	int tmp;
	for (int i = 0;i < k;i++) {
		for (int j = 0;j < k;j++) {
			for(int z=0;z<n;z++){
				if (b[i] > b[j]) {
					tmp = b[i];
					b[i] = b[j];
					b[j] = tmp;

					tmp = a[i][z];
					a[i][z] = a[j][z];
					a[j][z] = tmp;
				}
			}
		}
	}
}