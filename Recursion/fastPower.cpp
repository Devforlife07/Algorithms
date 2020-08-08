#include <iostream>
using namespace std;
int fast(int a, int n)
{
    if (n == 0)
        return 1;
    int ans = fast(a, n / 2);
    ans *= ans;
    if (n & 1)
        return a * ans;
    return ans;
}
int main()
{
    int a, n;
    cin >> a >> n;
    int ans = fast(a, n);
    cout << ans << '\n';
}