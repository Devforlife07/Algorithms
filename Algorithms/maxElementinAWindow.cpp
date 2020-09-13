#include <bits/stdc++.h>
using namespace std;
void getResult(int *a, int n, int k)
{
    deque<int> q;
    int i;
    for (i = 0; i < k; i++)
    {
        while (!q.empty() && a[q.back()] <= a[i])
        {
            q.pop_back();
        }
        q.push_back(i);
    }
    for (; i < n; i++)
    {
        cout << a[q.front()] << '\n';
        while (!q.empty() && q.front() <= i - k)
        {
            q.pop_front();
        }
        while (!q.empty() && a[q.back()] <= a[i])
        {
            q.pop_back();
        }
        q.push_back(i);
    }
    cout << a[q.front()] << '\n';
}
int main()
{
    int n;
    int k;
    cin >> n >> k;
    int *a = new int[n];
    int i = 0;
    int temp;
    while (i < n)
    {
        cin >> temp;
        a[i] = temp;
        i++;
    }
    getResult(a, n, k);
    return 0;
}