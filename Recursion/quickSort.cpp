#include <iostream>
using namespace std;
int partition(int *a, int s, int e)
{
    int i = s - 1;
    int j = s;
    int pivot = a[e];
    for (; j <= e - 1;)
    {
        if (a[j] <= pivot)
        {
            i += 1;
            swap(a[i], a[j]);
        }

        j += 1;
    }
    swap(a[i + 1], a[e]);
    return i + 1;
}
void quickSort(int *a, int s, int e)
{
    if (s >= e)
        return;
    int p = partition(a, s, e);
    quickSort(a, s, p - 1);
    quickSort(a, p + 1, e);
}
int main()
{
    int a[] = {131, 23, 1, 2, 3, 1, 32442, 42};
    int n = sizeof(a) / sizeof(n);
    quickSort(a, 0, n - 1);
    for (auto x : a)
    {
        cout << x << " ";
    }
}