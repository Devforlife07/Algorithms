#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    cin.get();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        ans ^= t;
    }
    cout << ans;
    /* code */
    return 0;
}
