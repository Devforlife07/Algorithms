#include <iostream>
using namespace std;
const string alpha[] = {"", ".+@$", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
void getResult(string n, char *out, int i, int j)
{
    if (n[i] == '\0')
    {
        out[j] = '\0';
        cout << out << '\n';
        return;
    }
    int cc = n[i] - '0';
    if (cc == 0)
    {
        getResult(n, out, i + 1, j);
    }
    for (int t = 0; alpha[cc][t] != '\0'; t++)
    {
        out[j] = alpha[cc][t];
        getResult(n, out, i + 1, j + 1);
    }
}
int main()
{
    string n;
    cin >> n;
    char out[100];
    getResult(n, out, 0, 0);
}