#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** a, const int k, const int n, const int Low, const int High);
void Print(int** a, const int k, const int n);
int SumMinOddRows(int** a, const int k, const int n);

int main()
{
    srand((unsigned)time(NULL));
    int Low = 1;
    int High = 100;
    int k, n;
    cout << "k = "; cin >> k;
    cout << "n = "; cin >> n;

    int** a = new int* [k];
    for (int i = 0; i < k; i++)
        a[i] = new int[n];

    Create(a, k, n, Low, High);

    Print(a, k, n);

    int sumMin = SumMinOddRows(a, k, n);
    cout << "Sum of minimum elements in odd rows: " << sumMin << endl;

    for (int i = 0; i < k; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Create(int** a, const int k, const int n, const int Low, const int High)
{
    for (int i = 0; i < k; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int k, const int n)
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

int SumMinOddRows(int** a, const int k, const int n)
{
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        if (i % 2 != 0)
        {
            int minElement = a[i][0];
            for (int j = 1; j < n; j++)
            {
                if (a[i][j] < minElement)
                    minElement = a[i][j];
            }
            sum += minElement;
        }
    }
    return sum;
}
