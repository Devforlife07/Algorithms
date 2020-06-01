#include <iostream>
using namespace std;
int getbits(int n)
{
    int count = 0;
    while (n > 0)
    {
        // cout>>n >> endl;
        if (n & 1)
        {
            count++;
        }
        n >>= 1;
    }
    return count;
}
int main()
{
    int t;
    cin >> t;
    // cin.get();
    while (t-- > 0)
    {
        int count = 0;
        int p;
        int q;
        cin >> p;
        cin >> q;
        // cout << p;
        for (int i = p; i <= q; i++)
        {
            count += getbits(i);
        }
        cout << count << endl;
    }
    return 0;
}
