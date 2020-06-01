#include <iostream>
using namespace std;
void clearBit(int &n, int i, int j)
{
    int mask1 = (-1 << i + 1);
    int mask2 = (1 << j) - 1;
    int mask = mask1 || mask2;
    n &= mask;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    int i;
    cin >> i;
    int j;
    cin >> j;
    clearBit(n, i, j);
    m <<= j;
    int ans = n | m;
    cout << ans << endl;
    return 0;
}
