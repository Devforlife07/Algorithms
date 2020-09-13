#include <bits/stdc++.h>
using namespace std;
int getResult(int *a, int n, int i, int j)
{
    // if (i == j)
    //     return a[i];
    if (i + 1 == j)
        return max(a[i], a[j]);
    return max(a[i] + min(getResult(a, n, i + 1, j - 1), getResult(a, n, i + 2, j)), a[j] + min(getResult(a, n, i, j - 2), getResult(a, n, i + 1, j - 1)));
    // return max(a[i] + max(getResult(a, n, i + 1, j), a[j] + getResult(a, n, i, j - 1));
}
int main()
{
    int n;
    cin >> n;
    int a[100];
    int i = 0;
    while (i < n)
    {
        cin >> a[i];
        i++;
    }
    int ans = getResult(a, n, 0, n - 1);
    cout << ans << '\n';
    return 0;
}