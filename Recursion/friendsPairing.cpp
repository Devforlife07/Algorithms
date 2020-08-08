//Friends Pairing Problem GeeksForGeeks
#include <iostream>
using namespace std;
int getResult(int n)
{
    if (n < 0)
        return 0;
    if (n == 0)
        return 1;
    int ans = getResult(n - 1);
    int i = 1;
    for (; i <= n - 1; i++)
    {
        ans += getResult(n - 2);
    }
    return ans;
}
int getResult2(int n)
{

    if (n < 0)
        return 0;
    if (n == 0)
        return 1;
    int ans = getResult2(n - 1);
    ans += (n - 1) * getResult2(n - 2);
    return ans;
}
int main()
{
    int n;
    cin >> n;
    cout << getResult(n) << '\n';
    cout << getResult2(n) << '\n';
}