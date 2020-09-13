#include <bits/stdc++.h>
using namespace std;
int binarySearch(int a[], int s, int e, int key)
{
    if (s > e)
        return -1;
    int mid = (s + e) / 2;
    if (a[mid] == key)
        return mid;
    else if (key > a[mid])
    {
        return binarySearch(a, mid + 1, e, key);
    }
    else
        return binarySearch(a, s, mid - 1, key);
}
int getPivotPoint(int a[], int s, int e)
{
    int high = e;
    int low = s;
    if (high < low)
        return -1;
    if (high == low)
        return low;
    int mid = (s + e) / 2;
    if (mid < high and a[mid] > a[mid + 1])
        return mid;
    if (mid > low and a[mid - 1] > a[mid]) //NOT A NECESSARY CONDITION
        return mid - 1;
    if (a[low] >= a[mid])
        return getPivotPoint(a, s, mid - 1);
    else
        return getPivotPoint(a, mid + 1, e);
}
int getResult(int a[], int n, int key)
{
    int pivot = getPivotPoint(a, 0, n - 1);
    cout << "Pivot Point" << pivot << "\n";
    if (pivot == -1)
        return binarySearch(a, 0, n - 1, key);
    if (key == a[pivot])
        return true;
    int ans = binarySearch(a, 0, pivot - 1, key);
    if (ans >= 0)
        return ans;
    else
        return binarySearch(a, pivot + 1, n - 1, key);
}
int main()
{

    int a[] = {2, 3, 4, 5, 1};
    int n = sizeof(a) / sizeof(a[0]);
    int key = 4;
    int ans = getResult(a, n, key);
    if (ans == -1)
        cout << "Item Not Found" << '\n';
    else
        cout << ans << '\n';
    return 0;
}