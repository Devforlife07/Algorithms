#include <bits/stdc++.h>
using namespace std;
using namespace ::chrono;
int getResult(int a, int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return a;
    else
    {
        int R = getResult(a, n / 2);
        if (n & 1)
        {
            return R * a * R;
        }
        else
        {
            return R * R;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    int a = 6;
    int n = 6;
    auto start = high_resolution_clock::now();
    cout << getResult(a, n) << '\n';
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << duration.count() << '\n';

    return 0;
}