#include <iostream>
#include <climits>
using namespace std;
int getResult(int n)
{
    int a[100000] = {0};
    for (int i = 2; i <= n; i++)
    {
        int op1, op2, op3 = INT_MAX;
        op1 = a[i - 1];
        if (i % 2 == 0)
            op2 = a[i / 2];
        if (i % 3 == 0)
            op3 = a[i / 3];
        a[i] = min(min(op1, op2), op3) + 1;
    }
    return a[n];
}
int main()
{
    int n;
    cin >> n;
    cout << getResult(n) << endl;
    return 0;
}