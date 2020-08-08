#include <iostream>
using namespace std;
int ans(char *a, int n)
{
    if (n == 0)
        return 0;
    int curr = a[n - 1] - '0';
    int small = ans(a, n - 1);
    return small * 10 + curr;
}
int main()
{
    int n;
    char a[] = "6789";
    cout << ans(a, 4) << '\n';
}