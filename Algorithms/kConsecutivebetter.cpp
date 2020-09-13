#include <bits/stdc++.h>
using namespace std;
int getResult(int n, int k)
{
    int count = 0;
    int low = ceil(pow(10, n - 1));
    int high = ceil(pow(10, n)) - 1;
    for (int j = low; j <= high; j++)
    {
        int *a = new int[n];
        int num = j;
        int sum = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            a[i] = num % 10;
            num /= 10;
        }
        for (int i = 0; i < k; i++)
            sum += a[i];
        int flag = 0;
        for (int i = k; i < n; i++)
        {
            if ((sum - a[i - k] + a[i]) != sum)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            count++;
    }
    return count;
}
int main()
{
    int n, k;
    cin >> n >> k;
    int ans = getResult(n, k);
    cout << ans << '\n';

    return 0;
}