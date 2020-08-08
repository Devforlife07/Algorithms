//Replace pi by 3.14 in a character array
#include <iostream>
using namespace std;
void replace(char *a, int i)
{
    if (a[i] == '\0')
    {
        return;
    }
    if (a[i] == 'p' && a[i + 1] == 'i')
    {
        int j = i + 2;
        while (a[j] != '\0')
        {
            j++;
        }
        while (j >= i + 2)
        {
            a[j + 2] = a[j];
            j--;
        }
        a[i] = '3';
        a[i + 1] = '.';
        a[i + 2] = '1';
        a[i + 3] = '4';
        replace(a, i + 4);
    }
    else
    {
        replace(a, i + 1);
    }
}
int main()
{
    char a[10000];
    cin >> a;
    replace(a, 0);
    int i = 0;
    while (a[i] != '\0')
    {
        cout << a[i] << " ";
        i++;
    }
}