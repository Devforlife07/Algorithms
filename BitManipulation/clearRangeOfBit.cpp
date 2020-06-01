#include <iostream>
using namespace std;

void clearbit(int &n, int i, int j)
{
    int mask1 = (-1 << (i + 1));
    int mask2 = (1 << j) - 1;
    int mask = mask1 + mask2;
    n &= mask;
}
int main()
{
    // your code goes here
    int n;
    cin >> n;
    int i;
    cin >> i;
    int j;
    cin >> j;
    clearbit(n, i, j);
    cout << n;

    return 0;
}
