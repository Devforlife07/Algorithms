#include <bits/stdc++.h>
using namespace std;
int getResult(int n)
{
    int mask = 0;
    int low = 0;
    int times = 0;
    while (n)
    {

        int curr = n % 10;
        low = (low << 1) + 1;
        if (curr == 7)
        {

            mask += (1 << times);
        }
        times++;
        n /= 10;
    }
    // cout << mask << '\n';
    return low + mask;
}
int main()
{
    int n;
    cin >> n;
    int rank = getResult(n);
    cout << rank << "\n";
}