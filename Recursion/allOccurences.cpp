#include <iostream>
using namespace std;
void allOccurences(int *a, int i, int n, int item)
{
    if (i == n + 1)
        return;
    if (a[i] == item)
        cout << i + 1 << " ";
    allOccurences(a, i + 1, n, item);
}
int main()
{
    int a[] = {1, 2, 3, 3, 3, 4, 4, 3, 3, 3};
    int n = sizeof(a) / sizeof(int);
    allOccurences(a, 0, n, 3);
    return 0;
}