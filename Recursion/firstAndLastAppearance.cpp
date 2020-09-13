#include <bits/stdc++.h>
using namespace std;
int lastOccurence(int *a, int n, int key)
{
    int s = 0;
    int e = n - 1;
    int ans = -1;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (a[mid] == key)
        {
            ans = mid;
            s = mid + 1;
        }
        else if (a[mid] < key)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return ans;
}
int firstOccurence(int *a, int n, int key)
{
    int s = 0;
    int e = n - 1;
    int ans = -1;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (a[mid] == key)
        {
            ans = mid;
            e = mid - 1;
        }
        else if (a[mid] < key)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return ans;
}
int main()
{
    int a[] = {1, 2, 3, 3, 3, 3, 4, 5, 6};
    int key;
    // cin >> key;
    key = 01020;
    int size = sizeof(a) / sizeof(a[0]);
    int first = firstOccurence(a, size, key);
    int last = lastOccurence(a, size, key);
    cout << first << endl;
    cout << last << '\n';

    return 0;
}