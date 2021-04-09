#include <bits/stdc++.h>
using namespace std;
int find(int i, int *parent)
{
    if (parent[i] == -1)
        return i;
    return find(parent[i], parent);
}
void union_set(int x, int y, int *parent)
{
    int s1 = find(x, parent);
    int s2 = find(y, parent);
    cout << "s1 and s2"
         << " " << s1 << " " << s2 << endl;
    parent[s1] = s2;
}
int main()
{
    int n, m;
    cin >> n >> m;
    int *parent = new int[n];
    for (int i = 0; i < n; i++)
    {
        parent[i] = -1;
    }
    // list<int,int> e;
    int i = 1;
    int x, y;
    while (i <= m)
    {
        cin >> x >> y;
        union_set(x, y, parent);
        i++;
    }
    cout << find(2, parent) << endl;
    for (i = 0; i < n; i++)
    {
        cout << i << " " << parent[i] << endl;
    }
}
