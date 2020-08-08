#include <iostream>
using namespace std;
int getAns(int n, int i, int k)
{
    if (i == n)
        return 1;
    if (i > n)
        return 0;
    int ans = 0;
    for (int j = 1; j <= k; j++)
    {
        ans += getAns(n, j + i, k);
    }
    return ans;
}
int main()
{
    int n;
    int k;
    cin >> n >> k;
    cout << getAns(n, 0, k) << '\n';
    return 0;
}