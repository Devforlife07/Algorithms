#include <bits/stdc++.h>
using namespace std;
int find(int x, int *parent)
{
    if (parent[x] == -1)
        return x;
    return parent[x] = find(parent[x], parent);
}
void union_optimized(int x, int y, int *parent, int *rank)
{
    int s1 = find(x, parent);
    int s2 = find(y, parent);
    if (s1 != s2)
    {
        if (rank[s1] > rank[s2])
        {
            parent[s2] = s1;
            rank[s2] += rank[s1];
        }
        else
        {
            parent[s1] = s2;
            rank[s1] += rank[s2];
        }
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    int *parent = new int[n];
    int *rank = new int[n];
    for (int i = 0; i < n; i++)
    {
        parent[i] = -1;
        rank[i] = 1;
    }
    int i = 1;
    int x, y;
    while (i <= m)
    {
        cin >> x >> y;
        union_optimized(x, y, parent, rank);
        i++;
    }
    for (int i = 0; i < n; i++)
    {
        cout << "Parent " << i << " " << parent[i] << endl;
    }
    for (int i = 0; i < n; i++)
    {
        cout << "Rank " << i << " " << rank[i] << endl;
    }
    return 0;
}