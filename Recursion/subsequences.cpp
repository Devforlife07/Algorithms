#include <iostream>
using namespace std;
void getSubsequences(char *a, char *output, int i, int j)
{
    if (a[i] == '\0')
    {
        output[j] = '\0';
        cout << output << '\n';
        // for (int x = 0; x < j; x++)
        // {
        //     cout << output[x];
        // }
        // cout << " ";
        return;
    }
    output[j] = a[i];
    getSubsequences(a, output, i + 1, j + 1);
    getSubsequences(a, output, i + 1, j);
}
int main()
{
    char a[] = "abc";
    char output[100];
    getSubsequences(a, output, 0, 0);
    return 0;
}