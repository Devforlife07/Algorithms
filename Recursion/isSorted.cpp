#include <bits/stdc++.h>
using namespace std;
bool isSorted(int a[], int i, int n)
{
    if (i == n - 1)
        return true;
    if (a[i] < a[i + 1])
        return isSorted(a, i + 1, n);
    else
        return false;
}
int main()
{
    int a[] = {1, 2, 3, 8, 7};
    int n = sizeof(a) / sizeof(n);
    if (isSorted(a, 0, n))
        cout << "True" << '\n';
    else
        cout << "False" << '\n';
}