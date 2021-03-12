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
        map<T, bool> visited;
        queue<T> q;
        q.push(src);
        visited[src] = true;
        while (!q.empty())
        {
            T node = q.front();
            q.pop();
            cout << node << " ";
            for (auto adj : g[node])
            {
                if (!visited[adj])
                {
                    q.push(adj);
                    visited[adj] = true;
                }
            }
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