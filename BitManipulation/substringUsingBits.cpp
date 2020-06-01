#include <bits/stdc++.h>
using namespace std;
void display(string ch, int x)
{
    string a = "";
    int j = 0;
    while (x > 0)
    {
        if (x & 1)
        {
            a += ch[j];
        }
        j++;
        x = x >> 1;
    }

    cout << a << '\n';
}
void getAns(string ch, int n)
{
    for (int i = 0; i < (1 << n); i++)
    {
        display(ch, i);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    int n;
    cin >> n;
    string ch;
    cin.get();
    getline(cin, ch);

    getAns(ch, n);
    return 0;
}