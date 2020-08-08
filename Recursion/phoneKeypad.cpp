#include <iostream>
using namespace std;
char dial[][9] = {"", "abc", "def", "ghi", "jkl", "mno", "pqr", "stu", "vwx", "yz."};
void getResult(char *ch, int i, int j, char *out)
{
    if (ch[i] == '\0')
    {
        out[j] = '\0';
        cout << out << '\n';
        return;
    }
    int digit = (ch[i] - '0');
    if (digit == 0)
    {
        getResult(ch, i + 1, j, out);
    }
    for (int x = 0; dial[digit][x] != 0; x++)
    {
        out[j] = dial[digit][x];
        getResult(ch, i + 1, j + 1, out);
    }
}
int main()
{
    char ch[100];
    cin >> ch;
    char output[1000];
    getResult(ch, 0, 0, output);
}