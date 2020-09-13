#include <bits/stdc++.h>
using namespace std;
bool check(string s1, string s2)
{
    if (s1.compare(s2) == 0)
        return true;
    return false;
}
bool getResult(string a1, string a2)
{
    int mid = a1.length() / 2;
    if (a1.compare(a2) == 0)
        return true;
    if (a1.length() % 2)
        return false;
    return (getResult(a1.substr(0, mid), a2.substr(0, mid)) and getResult(a2.substr(mid), a2.substr(mid)) || getResult(a1.substr(0, mid), a2.substr(mid)) and getResult(a1.substr(mid), a2.substr(0, mid)));
}
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        string a1, a2;
        cin >> a1 >> a2;
        int ans = getResult(a1, a2);
        if (ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}