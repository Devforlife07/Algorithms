#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[100000];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans ^= a[i];
    }
    cout << ans << endl;
    return 0;
}