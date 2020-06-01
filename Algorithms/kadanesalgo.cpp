#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int i = 0;
    int a[100];
    while (i < n)
    {
        cin >> a[i];
        i++;
    }
    int maximum = a[0];
    int curr = a[0];
    i = 1;
    while (i < n)
    {
        curr = max(a[i], curr + a[i]);
        // cout << curr << '\n';
        if (curr > maximum)
            maximum = curr;
        i++;
    }
    cout << maximum << '\n';

    /* code */
    return 0;
}
