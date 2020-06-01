#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int ans[32] = {0};
    cin >> n;
    int a[n];
    int i = 0;
    while (i < n)
    {
        cin >> a[i];
        i++;
    }
    i = 0;
    for (; i < n; i++)
    {

        int pos = 0;
        int curr = a[i];
        // cout << curr << endl;
        while (curr != 0)
        {
            int c = curr & 1;
            ans[pos] += c;
            pos++;
            curr >>= 1;
        }
    }
    i = 0;
    while (i < 7)
    {
        ans[i] %= 3;
        i++;
    }
    i = 0;
    int p = 1;
    int answer = 0;
    while (i < 7)
    {
        answer += ans[i] * p;
        p <<= 1;
        i++;
    }
    cout << answer << endl;
    return 0;
}
