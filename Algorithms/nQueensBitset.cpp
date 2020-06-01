#include <bits/stdc++.h>
using namespace std;
bitset<30> col, d1, d2;
void getResult(int n, int i, int &ans)
{
    if (i == n)
    {
        ans++;

        return;
    }
    for (int j = 0; j < n && i < n; j++)
    {
        if (col[j] != 1 && d1[i - j + (n - 1)] != 1 && d2[i + j] != 1)
        {
            col[j] = 1;
            d1[i - j + (n - 1)] = 1;
            d2[i + j] = 1;
            getResult(n, i + 1, ans);
            col[j] = 0;
            d1[i - j + (n - 1)] = 0;
            d2[i + j] = 0;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int ans = 0;
    getResult(n, 0, ans);
    cout << ans << '\n';
    return 0;
}