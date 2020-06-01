#include <bits/stdc++.h>
using namespace std;
int moves[] = {1, 2, 3, 4};
void getResult(int n, int i, vector<char> ans)
{

    if (i == n)
    {
        for (char c : ans)
            cout << c;
        cout << '\n';
        return;
    }
    else if (i > n)
        return; //8527557374
    else
    {
        for (int j = 0; j < 4; j++)
        {
            if (i + moves[j] <= n)
            {
                ans.push_back((char)moves[j]);
                getResult(n, i + moves[j], ans);
                ans.pop_back();
            }
        }
    }
}
int main()
{
    int n;
    cin >> n;
    vector<char> ans;
    getResult(n, 0, ans);
    return 0;
}