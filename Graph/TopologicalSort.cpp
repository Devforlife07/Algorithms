#include <bits/stdc++.h>
using namespace std;
class Graph
{
    map<int, list<int>> g;

private:
    bool helper(int node, int parent, map<int, pair<int, int>> &visited, int color)
    {
        visited[node].first = 1;
        visited[node].second = color;
        // cout << node << " " << visited[node].first << " " << visited[node].second << endl;
        for (auto nbrs : g[node])
        {
            if (!visited[nbrs].first)
                return helper(nbrs, node, visited, 3 - color);
            else if (nbrs != parent and visited[nbrs].second == color)
                return false;
        }
        return true;
    }

public:
    void addEdge(int x, int y)
    {
        g[x].push_back(y);
        // g[y].push_back(x);
    }
    void dfs_helper(int node, map<int, bool> &visited, list<int> &ordering)
    {
        visited[node] = true;
        for (auto nbrs : g[node])
        {
            if (!visited[nbrs])
                dfs_helper(nbrs, visited, ordering);
        }
        ordering.push_front(node);
    }
    void dfs()
    {
        map<int, bool> visited;
        list<int> ordering;
        for (auto node_pair : g)
        {
            int node = node_pair.first;
            if (!visited[node])
                dfs_helper(node, visited, ordering);
        }
        for (auto x : ordering)
        {
            cout << x << " ";
        }
        cout << endl;
    }
};
int main()
{
    Graph g;
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.dfs();

    return 0;
}