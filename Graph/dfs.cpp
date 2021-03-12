#include <bits/stdc++.h>
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
    void recursive_dfs(T node, map<T, bool> &visited)
    {
        visited[node] = true;
        cout << node << " ";
        for (auto nbrs : g[node])
        {
            if (!visited[nbrs])
            {
                recursive_dfs(nbrs, visited);
            }
        }
    }
    void dfs(T src)
    {
        map<T, bool> visited;
        for (auto p : g)
        {
            T node = p.first;
            visited[node] = false;
        }
        recursive_dfs(src, visited);
    }
};

int main()
{
    Graph<int> g;
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.dfs(1);
    return 0;
}