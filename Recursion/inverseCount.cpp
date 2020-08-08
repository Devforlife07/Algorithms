#include <iostream>
using namespace std;
int merge(int *a, int s, int e)
{
    int count = 0;
    int temp[1000];
    int i = s;
    int mid = (s + e) / 2;
    int j = mid + 1;
    int k = s;
    while (i <= mid && j <= e)
    {
        if (a[i] <= a[j])
        {
            temp[k++] = a[i];
            i++;
        }
        else
        {
            count += mid - i + 1;
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

        a[i] = temp[i];
    }
    return count;
}
int mergeSort(int *a, int s, int e)
{
    int count = 0;
    if (s >= e)
        return 0;
    int mid = (s + e) / 2;
    count += mergeSort(a, s, mid);
    count += mergeSort(a, mid + 1, e);
    count += merge(a, s, e);
    return count;
}
int main()
{
    int a[] = {8, 4, 2, 1};
    int n = sizeof(a) / sizeof(int);
    cout << mergeSort(a, 0, n - 1) << '\n';
    return 0;
}