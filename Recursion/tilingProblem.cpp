#include <iostream>
using namespace std;
int getResult(int n)
{
    if (n <= 3)
    {
        return 1;
    }
    return getResult(n - 1) + getResult(n - 4);
}
int main()
{
    int n;
    cin >> n;
    cout << getResult(n) << '\n';
    return 0;
}