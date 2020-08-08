#include <iostream>
using namespace std;
int getAns(int *p, int *wt, int n, int c)
{
    if (c == 0 || n < 0)
    {
        return 0;
    }
    int ans = 0;
    int inc, exc;
    inc = exc = INT32_MIN;
    if (wt[n] <= c)
    {
        inc = p[n] + getAns(p, wt, n - 1, c - wt[n]);
    }
    exc = getAns(p, wt, n - 1, c);
    ans = max(inc, exc);
    return ans;
}
int main()
{
    int p[] = {10, 5, 20, 40, 45};
    int wt[] = {2, 1, 5, 7, 9};
    int capacity = 11;
    int n = sizeof(p) / sizeof(int);
    cout << getAns(p, wt, n - 1, capacity);
    return 0;
}