#include <iostream>
using namespace std;
char a[27];
void getResult(char *ch, int i, int j, char *out)
{
    if (ch[i] == '\0')
    {
        out[j] = '\0';
        cout << out << '\n';
        return;
    }
    int curr = ch[i] - '0';
    if (curr == 0)
    {
        getResult(ch, i + 1, j, out);
        return;
    }
    out[j] = a[curr];
    getResult(ch, i + 1, j + 1, out);
    if (ch[i + 1] != '\0')
    {
        int curr2 = ch[i + 1] - '0';
        if ((curr * 10 + curr2) <= 26)
        {
            out[j] = a[curr * 10 + curr2];
            getResult(ch, i + 2, j + 1, out);
        }
    }
}
int main()
{
    int index = 1;
    for (char i = 'a'; i <= 'z'; i++)
    {
        a[index++] = i;
    }
    char ch[100];
    cin >> ch;
    char out[1000];
    getResult(ch, 0, 0, out);
}