#include <iostream>
using namespace std;
int getResult(int *a, int n, int s, int e, int key)
{
    if (s == e)
        return s;
    if (s > e)
        return -1;
    int mid = (s + e) / 2;
    if (a[mid] == key)
        return mid;
    else if (a[s] <= a[mid])
    {
        if (key >= a[s] and key <= a[mid])
            return getResult(a, n, s, mid - 1, key);
        else
            return getResult(a, n, mid + 1, e, key);
    }
    else
    {
        if (key > a[mid] and key <= a[e])
            return getResult(a, n, mid + 1, e, key);
        else
            return getResult(a, n, s, mid - 1, key);
    }
}
int main()
{
    int a[] = {4, 5, 6, 1, 2, 3};
    int n = sizeof(a) / sizeof(a[0]);
    int key = 4;
    int index = getResult(a, n, 0, n - 1, key);
    cout << index << '\n';
    return 0;
}