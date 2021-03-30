#include <bits/stdc++.h>
using namespace std;
class Graph
{
    map<int, list<int>> g;

private:
    bool dfs(int node, map<int, bool> &rec, map<int, bool> &vis)
    {
        vis[node] = true;
        rec[node] = true;
        for (auto nbrs : g[node])
        {
            if (!vis[node] and dfs(nbrs, rec, vis))
                return true;
            else if (rec[nbrs] == true)
                return true;
        }
        return false;
    }

public:
    void addEdge(int x, int y, bool isDirected = true)
    {
        g[x].push_back(y);
        if (!isDirected)
            g[y].push_back(x);
    }

    bool detectCycle()
    {
        map<int, bool> vis;
        map<int, bool> rec;
        for (auto node_pair : g)
        {
            int node = node_pair.first;
            vis[node] = false;
            rec[node] = false;
        }
        for (auto node_pair : g)
        {
            int node = node_pair.first;
            if (!vis[node] and dfs(node, rec, vis))
            {
                return true;
            }
        }
        return false;
    }
};
int main()
{

    Graph g;
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    g.addEdge(6, 7);
    g.addEdge(7, 4);
    cout << g.detectCycle() << endl;

    return 0;
}