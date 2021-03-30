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
        g[y].push_back(x);
    }
    bool checkBipartite()
    {
        map<int, pair<int, int>> visited;
        for (auto node_pair : g)
        {
            int node = node_pair.first;
            visited[node] = make_pair(0, INT_MIN);
        }

        for (auto node_pair : g)
        {
            int node = node_pair.first;
            if (!visited[node].first)
            {
                bool ans = helper(node, -1, visited, 1);
                if (!ans)
                {
                    cout << "YEMS " << node << endl;
                    return false;
                }
            }
        }
        //Print visited map
        for (auto node_pair : visited)
        {
            int node = node_pair.first;
            auto ipair = node_pair.second;
            cout << "Node = " << node << " " << ipair.first << " " << ipair.second << endl;
        }
        return true;
    }
};
int main()
{
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    cout << g.checkBipartite() << endl;

    return 0;
}