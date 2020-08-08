#include <iostream>
using namespace std;
void bubblesort(int *a, int i, int j, int n)
{
    if (n - 1 == 1)
    {
        return;
    }
    if (j == n - 1)
    {
        bubblesort(a, i + 1, 0, n - 1);
        return;
    }
    if (a[j] > a[j + 1])
    {
        int temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
        bubblesort(a, i, j + 1, n);
    }
    else
    {
        bubblesort(a, i, j + 1, n);
    }
}
int main()
{
    int a[] = {2938, 12, 12, 132, 4, 89};
    int n = sizeof(a) / sizeof(int);
    bubblesort(a, 0, 0, n);
    for (auto x : a)
        cout << x << " ";

    return 0;
}