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
    void printGraph()
    {
        for (auto node_pair : g)
        {
            T node = node_pair.first;
            cout << node << " ";
            for (auto ele : g[node])
            {
                cout << ele << " ";
            }
            cout << endl;
        }
    }
    bool isCyclePresent(T parent)
    {
        int src = 0;
        map<T, bool> visited;
        for (auto node_pair : g)
        {
            T node = node_pair.first;
            visited[node] = false;
        }
        //Map
        // for (auto x : visited)
        // {
        //     cout << x.first << " " << x.second << endl;
        // }
        for (auto node_pair : g)
        {
            T node = node_pair.first;
            if (!visited[node])
            {
                bool ans = cycleHelper(node, parent, visited);
                if (ans)
                    return true;
            }
        }
        // for (auto x : visited)
        // {
        //     cout << x.first << " " << x.second << endl;
        // }
        return false;
    }
};
int main()
{
    Graph<int> g;
    // g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);
    g.addEdge(3, 4);
    // g.addEdge(4, 1);
    g.printGraph();
    cout << endl;
    cout << g.isCyclePresent(-1) << endl;

    return 0;
}