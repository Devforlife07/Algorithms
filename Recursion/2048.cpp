#include <iostream>
using namespace std;
char names[][10] = {
    "Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
void printAns(int n)
{
    if (n == 0)
        return;
    int curr = n % 10;
    printAns(n / 10);
    cout << names[curr] << " ";
}
int main()
{
    int n;
    cin >> n;
    printAns(n);
    return 0;
}