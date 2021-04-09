#include <bits/stdc++.h>
using namespace std;
void dfs2(vector<int> *g, int node, int n, stack<int> &nodes, map<int, bool> &visited)
{
    visited[node] = true;
    cout << " " << node << " ";
    for (auto nbrs : g[node])
    {
        if (!visited[nbrs])
            dfs2(g, nbrs, n, nodes, visited);
    }
}
void dfs1(vector<int> *g, int node, int n, stack<int> &nodes, map<int, bool> &visited)
{
    visited[node] = true;
    for (auto nbrs : g[node])
    {
        if (!visited[nbrs])
            dfs1(g, nbrs, n, nodes, visited);
    }
    nodes.push(node);
}
void kosaraju(vector<int> *g, int n, vector<int> *rev)
{
    stack<int> nodes;
    map<int, bool> visited;
    // cout << "Size Of Map " << visited.size() << endl;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs1(g, i, n, nodes, visited);
        }
    }
    visited.clear();
    while (!nodes.empty())
    {
        int start = nodes.top();
        // cout << "Stack Element Popped" << start << endl;
        nodes.pop();
        if (!visited[start])
        {
            // cout << "Component ";
            dfs2(rev, start, n, nodes, visited);
            cout << endl;
        }
    }
    return;
}
int main()
{
    int n;
    int m;
    cin >> n >> m;
    vector<int> g[n];
    vector<int> rev[n];
    int x, y;
    cout << "N " << n << " M " << m << endl;
    int j = 1;
    while (j <= m)
    {
        cin >> x >> y;
        g[x].push_back(y);
        rev[y].push_back(x);
        j++;
    }
    //Print Graphs
    // for (int i = 0; i < n; i++)
    // {
    //     cout << " Node " << i << "--> ";
    //     for (auto nbrs : g[i])
    //     {
    //         cout << nbrs << " ";
    //     }
    //     cout << endl;
    // }
    // cout << '\n'
    //      << " Reverse Graph " << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cout << " Node " << i << "--> ";
    //     for (auto nbrs : rev[i])
    //     {
    //         cout << nbrs << " ";
    //     }
    //     cout << endl;
    // }
    kosaraju(g, n, rev);
    return 0;
}