#include <bits/stdc++.h>
using namespace std;
class Graph
{
    map<int, list<int>> g;

public:
    void addEdge(int *moves)
    {
        for (int i = 0; i < 30; i++)
        {
            for (int j = i + 1; j < 30 and j <= i + 6; j++)
            {
                if (moves[j] == -1)
                {
                    g[i].push_back(j);
                }
                else
                {
                    g[i].push_back(moves[j]);
                }
            }
        }
        g[29].push_front(29);
    }
    void displayGraph()
    {
        for (auto node_pair : g)
        {
            int node = node_pair.first;
            cout << "Node " << node << " = ";
            for (auto every_list : g[node])
            {
                cout << every_list << " ";
            }
            cout << '\n';
        }
    }
    int shortestPath()
    {
        int src = 0;
        map<int, int> visited;
        for (auto node_pair : g)
        {
            int node = node_pair.first;
            visited[node] = INT_MAX;
        }
        int start = 0;
        queue<int> q;
        visited[start] = 0;
        q.push(start);
        while (!q.empty())
        {
            int curr_node = q.front();
            if (curr_node == 29)
            {
                break;
            }
            q.pop();
            int dis = visited[curr_node] + 1;
            for (auto x : g[curr_node])
            {
                if (visited[x] != INT_MAX)
                {
                    visited[x] = dis + 1;
                    q.push(x);
                }
            }
        }
        for (auto curr_node : visited)
        {
            int node = curr_node.first;
            cout << "Node " << node << " " << curr_node.second << endl;
        }
        return visited[q.front()];
    }
};

int main()
{
    int moves[30];
    for (int i = 0; i < 30; i++)
    {
        moves[i] = -1;
    }
    moves[2] = 21;
    moves[4] = 7;
    moves[10] = 25;
    moves[19] = 28;

    // Snakes
    moves[26] = 0;
    moves[20] = 8;
    moves[16] = 3;
    moves[18] = 6;
    Graph g;
    g.addEdge(moves);
    // g.displayGraph();
    cout << g.shortestPath() << endl;

    return 0;
}