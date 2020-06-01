#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
int getResult(int a, int n)
{
    int ans = 1;
    int curr = a;
    while (n)
    {
        if (n & 1)
        {
            ans *= curr;
        }
        curr = (curr * curr);
        n >>= 1;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    int a = 6;
    int b = 6;
    auto start = high_resolution_clock::now();
    cout << getResult(a, b) << '\n';
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << duration.count() << '\n';
    return 0;
}