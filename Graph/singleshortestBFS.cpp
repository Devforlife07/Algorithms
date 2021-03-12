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
    void bfs(T src)
    {
        map<T, int> distance;
        queue<T> q;
        for (auto node_pair : g)
        {
            T node = node_pair.first;
            distance[node] = INT_MAX;
        }
        distance[src] = 0;
        q.push(src);
        while (!q.empty())
        {
            T node = q.front();
            q.pop();
            for (auto adj : g[node])
            {
                if (distance[adj] == INT_MAX)
                {
                    q.push(adj);
                    distance[adj] = distance[node] + 1;
                }
            }
        }
        for (auto node_pair : distance)
        {
            T node = node_pair.first;
            int dist = distance[node];
            cout << "Node " << node << " is at distance " << dist << " From The Source" << endl;
        }
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
    g.bfs(1);
    return 0;
}