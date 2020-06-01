#include <bits/stdc++.h>
using namespace std;
int getpos(int x)
{
    int flag = 0;
    int pos = 0;
    while (flag == 0)
    {
        if ((x & 1) == 1)
        {
            flag = 1;
            return pos;
        }
        pos++;
        x >>= 1;
    }
    return pos;
}
int main()
{
    int n;
    cin >> n;
    int a[100005];
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        int curr;
        cin >> curr;
        a[i] = curr;
        x ^= curr;
    }
    int pos = getpos(x);
    int mask = 1 << pos;
    vector<int> one;
    int temp = x;
    for (int i = 0; i < n; i++)
    {
        if ((a[i] & mask) == 1)
        {
            one.push_back(a[i]);
        }
    }
    int x2 = 0;
    for (int i : one)
    {
        x2 ^= i;
    }
    vector<int> ans;
    ans.push_back(x2);
    ans.push_back((x ^ x2));
    sort(ans.begin(), ans.end());
    for (int t : ans)
    {
        cout << t << " ";
    }
    return 0;
}