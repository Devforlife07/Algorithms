#include <iostream>
using namespace std;
void merge(int *a, int s, int e)
{
    int temp[1000];
    int i = s;
    int mid = (s + e) / 2;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= e)
    {
        if (a[i] <= a[j])
        {
            temp[k++] = a[i];
            i++;
        }
        else
        {
            temp[k++] = a[j];
            j++;
        }
    }
    while (i <= mid)
    {
        temp[k++] = a[i];
        i++;
    }
    while (j <= e)
    {
        temp[k++] = a[j];
        j++;
    }

    for (int i = s; i <= e; i++)
    {

        a[i] = temp[i - s];
    }
}
void mergeSort(int *a, int s, int e)
{
    if (s >= e)
        return;
    int mid = (s + e) / 2;
    mergeSort(a, s, mid);
    mergeSort(a, mid + 1, e);
    merge(a, s, e);
}
int main()
{
    int a[] = {8327, 11, 3313, 133, 4, 45, 25, 252, 5};
    int n = sizeof(a) / sizeof(int);
    mergeSort(a, 0, n - 1);
    for (int x : a)
    {
        cout << x << " ";
    }
}