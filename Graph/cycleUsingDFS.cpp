#include <bits/stdc++.h>
using namespace std;
template <typename T>
class Graph
{
    map<T, list<T>> g;

private:
    bool cycleHelper(T node, T parent, map<T, bool> &visited)
    {
        visited[node] = true;
        for (auto nbrs : g[node])
        {
            if (!visited[nbrs])
            {
                return cycleHelper(nbrs, node, visited);
            }
            else if (nbrs != parent)
            {
                return true;
            }
        }
        return false;
    }

public:
    void addEdge(T x, T y, bool isDirected = false)
    {
        g[x].push_back(y);
        if (!isDirected)
            g[y].push_back(x);
    }

    bool isCyclePresent()
    {
        int src = 0;
        map<T, bool> visited;
        for (auto node_pair : g)
        {
            T node = node_pair.first;
            visited[node] = false;
        }
        return cycleHelper(0, 0, visited);
    }
};
int main()
{
    Graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    cout << g.isCyclePresent() << endl;

    return 0;
}