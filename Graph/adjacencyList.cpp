#include <bits/stdc++.h>
using namespace std;
class Graph
{
    int V;
    list<int> *l;

public:
    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V];
    }
    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void printGraph()
    {
        for (int i = 0; i < this->V; i++)
        {
            cout << i << " ";
            for (auto x : l[i])
            {
                cout << x << " ";
            }
            cout << endl;
        }
    }
};
int main()
{
    Graph g(6);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(2, 4);
    g.printGraph();
}