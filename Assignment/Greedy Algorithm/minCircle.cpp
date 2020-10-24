#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool comparator(pair<ll, ll> one, pair<ll, ll> two)
{
    if (one.second == two.second)
    {
        return one.first < two.first;
    }
    return one.second < two.second;
}
int main()
{
    int n;
    cin >> n;
    vector<pair<ll, ll>> input;
    int i = 1;
    ll c, r;
    while (i <= n)
    {
        cin >> c >> r;
        ll start = c - r;
        ll end = c + r;
        input.push_back(make_pair(start, end));
        i++;
    }
    sort(input.begin(), input.end(), comparator);
    pair<ll, ll> start = input[0];
    int ans = 0;
    i = 1;
    while (i < n)
    {
        if (input[i].first < start.second)
        {
            ans++;
        }
        else
        {
            start = input[i];
        }
        i++;
    }
    cout << ans << '\n';
}
