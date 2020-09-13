#include <bits/stdc++.h>
using namespace std;
bitset<60> col, d1, d2;

void getResult(int n, int i, int &count)
{
    if (i >= n)
    {
        count += 1;
    }

    for (int l = 0; l < n; l++)
    {
        if (!col[l] and !d1[i - l + n - 1] and !d2[i + l])
        {

            col[l] = 1;
            d2[i + l] = 1;
            d1[i - l + (n - 1)] = 1;
            getResult(n, i + 1, count);
            col[l] = 0;
            d2[i + l] = 0;
            d1[i - l + (n - 1)] = 0;
        }
    }
}
int main()
{

    int n;
    cin >> n;
    int count = 0;
    getResult(n, 0, count);
    cout << count << endl;
    return 0;
}