#include <bits/stdc++.h>
using namespace std;
int getResult(int n, int k)
{
    int count = 0;
    int low = pow(10, n - 1);
    int high = (int)(ceil(pow(10, n)) - 1);

    for (int i = low; i <= high; i++)
    {
        int *a = new int[n];
        int num = i;
        for (int j = n - 1; j >= 0; j--)
        {
            a[j] = num % 10;
            num /= 10;
        }
        //Take sum of first k consecutive digits of number
        int sum = 0;
        for (int j = 0; j < k; j++)
        {
            sum += a[j];
        }
        int flag = 0;
        //Now Check for rest of digits
        for (int j = 1; j <= n - k; j++)
        {
            flag = 0;
            int dsum = 0;
            for (int m = j; m < j + k; m++)
                dsum += a[m];
            if (dsum != sum)
            {
                flag = 1;
                break;
            }
        }
        if (!flag)
        {
            cout << i << '\n';
            count++;
        }
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