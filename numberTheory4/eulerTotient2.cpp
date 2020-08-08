#include <bits/stdc++.h>
#define ll long long
using namespace std;
void cal(int a[], int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (a[i] == i)
        {
            a[i] = i - 1;

            for (int j = 2 * i; j <= n; j += i)
            {
                a[j] = a[j] * (i - 1);
                a[j] /= i;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << *(a + i) << " ";
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int a[1000009];
    int i = 1;
    while (i <= n)
    {
        a[i] = i;
        i++;
    }
    cout << '\n';
    cal(a, n);

    return 0;
}