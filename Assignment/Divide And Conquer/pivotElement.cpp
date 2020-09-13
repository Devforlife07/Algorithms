#include <iostream>
using namespace std;
int getResult(int *a, int n, int s, int e)
{
    if (s > e)
        return -1;
    if (s == e)
        return s;
    int mid = (s + e) / 2;
    if (mid < e and a[mid] > a[mid + 1])
        return mid;
    if (mid > s and a[mid - 1] > a[mid])
        return mid - 1;
    if (a[s] >= a[mid])
        return getResult(a, n, s, mid - 1);
    else
        return getResult(a, n, mid + 1, e);
}
int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    int i = 0;
    while (i < n)
    {
        cin >> a[i];
        i++;
    }
    int output = getResult(a, n, 0, n - 1);
    cout << output << endl;
    return 0;
}