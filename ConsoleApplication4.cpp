// ConsoleApplication4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

long double fact(int N)
{
   if (N == 0) 
        return 1;
    else 
        return N * fact(N - 1); 
}

void print(int* x,int n,int pos)
{
    cout << pos+1 <<"\t"<<"->{";
    for (int k = 0; k < n; k++) cout << " " << x[k];
    cout <<" }"<< "\n";
}

void swap(int* a, int i, int j)
{
    int s = a[i];
    a[i] = a[j];
    a[j] = s;
}

//--------------алгоритм только для N=3------------------
// оценка сложности получившегося алгоритма O(С) 
void PerestanV1(int* a)
{
    int k = 0;
    while (fact(3) > k)
    {
        for (int i = 0; i < 2; i++)
        {
            swap(a,i,i+1);
            print(a, 3, k++);
        }
    }
}
//--------------алгоритм для любого n------------------------
// оценка сложности получившегося алгоритма O(N!) 
bool elmove(int* a, int n)
{
    int j = n - 2;
    while (j != -1 && a[j] >= a[j + 1]) j--;
    if (j == -1)
        return false;
    int k = n - 1;
    while (a[j] >= a[k]) k--;
    swap(a, j, k);
    int l = j + 1, r = n - 1;
    while (l < r)
        swap(a, l++, r--);
    return true;
}

void PerestanV2(int* a,int n)
{
    int k = 0;
    print(a, n,k);
    while (elmove(a, n))
        print(a, n,++k);
}

void Inputmas(int* a,int n)
{
    for (int i = 0; i < n; i++) a[i] = i + 1;
}

int main()
{
    // оценка сложности получившегося алгоритма O(N!)   
    int* a;
    cout << "For N=3" << "\n";
    int n=3;    
    a = new int[n];
    Inputmas(a,n);
    PerestanV1(a);
    delete[] a;
    cout << "N = ";
    cin >> n;
    a = new int[n];
    Inputmas(a, n);
    PerestanV2(a,n);
    delete[] a;
}

