#include <iostream>
using namespace std;
void getResult(char *ch, int i, int open, int close, int n)
{
    if (i == 2 * n)
    {
        ch[i] = '\0';
        cout << ch << '\n';
        return;
    }

    if (open < n)
    {
        ch[i] = '(';
        getResult(ch, i + 1, open + 1, close, n);
    }
    if (close < open)
    {
        ch[i] = ')';
        getResult(ch, i + 1, open, close + 1, n);
    }
    return;
}
int main()
{
    int n;
    cin >> n;
    char ch[2000];
    getResult(ch, 0, 0, 0, n);
    return 0;
}