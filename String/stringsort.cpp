#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool comparator(string a, string b)
{
    if (a.length() == b.length())
        return a < b;
    return a.length() < b.length();
}
int main()
{
    string name[100];
    int n;
    cin >> n;
    cin.get();
    for (int i = 0; i < n; i++)
    {
        getline(cin, name[i]);
    }
    sort(name, name + n, comparator);
    for (int i = 0; i < n; i++)
    {
        cout << name[i] << endl;
    }
    // your code goes here
    return 0;
}