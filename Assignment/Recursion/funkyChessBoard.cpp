#include <bits/stdc++.h>
using namespace std;
const int xMove[8] = {2, 1, -1, -2, -2, -1, 1, 2};
const int yMove[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int ans = 0;
void getResult(int a[10][10], int n, int i, int j, int count)
{

    if (a[i][j] == 0 || i < 0 || i >= n || j < 0 || j >= n)
        return;
    a[i][j] = 0;
    count++;
    ans = max(ans, count);
    for (int c = 0; c < 8; c++)
    {
        getResult(a, n, i + xMove[c], j + yMove[c], count);
    }
    a[i][j] = 1;
}
int main()
{
    int n;
    cin >> n;
    int a[10][10];
    int ones = 0;
    int temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> temp;
            a[i][j] = temp;
            if (temp)
                ones++;
        }
    }

    getResult(a, n, 0, 0, 0);
    cout << ones - ans << endl;
    return 0;
}