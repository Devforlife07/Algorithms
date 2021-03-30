#include <bits/stdc++.h>
using namespace std;
int count(int a[][1000], int sr, int sc, int er, int ec)
{
    int ans = 0;
    for (int i = sr; i <= er; i++)
    {
        for (int j = sc; j <= ec; j++)
        {
            if (a[i][j] == 1)
                ans += 1;
        }
    }
    return ans;
}
int getResult(int a[][1000], int n)
{
    int r, c;
    r = c = n;
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int ans1 = count(a, 0, 0, i, j);
            int ans2 = count(a, 0, j + 1, i, c);
            int ans3 = count(a, i + 1, 0, r, j);
            int ans4 = count(a, i + 1, j + 1, r, c);
            ans = max(ans, min(ans1, min(ans2, min(ans3, ans4))));
        }
    }
    return ans;
}
int main()
{
    int n, gold;
    cin >> n >> gold;
    int matrix[1000][1000];
    memset(matrix, 0, sizeof(matrix));
    int i = 1;
    int x, y;
    while (i <= gold)
    {
        cin >> x >> y;
        matrix[x - 1][y - 1] = 1;
        i++;
    }
    //    for(int i = 0;i<n;i++){
    //        for(int j = 0;j<n;j++){
    //            cout<<matrix[i][j]<<" ";
    //        }
    //        cout<<endl;
    //    }
    int ans = getResult(matrix, n);
    cout << ans << endl;
    return 0;
}
