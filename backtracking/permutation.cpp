#include <iostream>
using namespace std;
void getResult(char *in, char *out, int i, int j)
{
    if (in[i] == '\0')
    {
        out[j] = '\0';
        cout << in << '\n';
        return;
    }
    for (int x = i; in[x] != '\0'; x++)
    {
        swap(in[i], in[x]);
        out[j] = in[i];
        getResult(in, out, i + 1, j + 1);
        swap(in[i], in[x]);
    }
}
int main()
{
    char ch[100];
    cin >> ch;
    char out[10000];
    getResult(ch, out, 0, 0);

    return 0;
}