#include <bits/stdc++.h>
#define ll long long
using namespace std;
template <typename T>
class Graph
{
    map<T, list<T>> g;

public:
    void addEdge(T x, T y)
    {
        g[x].push_back(y);
        g[y].push_back(x);
    }
    void dfs_recursive(T node, map<T, bool> &visited)
    {
        visited[node] = true;
        cout << " " << node << " ";
        for (auto nbr : g[node])
        {
            if (!visited[nbr])
            {
                dfs_recursive(nbr, visited);
            }
        }
    }
    void dfs()
    {
        map<T, bool> visited;
        for (auto node_pair : g)
        {
            T node = node_pair.first;
            visited[node] = false;
        }
        int cnt = 0;
        for (auto node_pair : visited)
        {
            T node = node_pair.first;
            if (!visited[node])
            {
                cout << "Component " << cnt << "  -->";
                dfs_recursive(node, visited);
                cnt++;
                cout << endl;
            }
        }
    }
};
int main()
{
    Graph<int> G;
    G.addEdge(1, 2);
    G.addEdge(1, 4);
    G.addEdge(2, 3);
    G.addEdge(3, 4);
    G.addEdge(5, 6);
    G.dfs();

    return 0;
}