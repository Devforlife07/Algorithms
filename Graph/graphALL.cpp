#include <bits/stdc++.h>
using namespace std;
class Graph{
map<int,list<int>> g;
public:
 void addEdge(int x,int y,bool isDirected=false){
         g[x].push_back(y);
         g[y].push_back(x);
 }
 void printGraph(){
         for(auto node_pair:g){
                 int node = node_pair.first;
                 cout<<"NODE "<<node<<" ";
                 for(auto x:g[node]){
                         cout<<x<<" ";
                 }
                 cout<<endl;
         }
 }
 void bfs(int start=1){
    map<int,bool> visited;
    queue<int> q;
    visited[start] = 1;
    q.push(start);
    while(!q.empty()){
            int node = q.front();
            q.pop();
            cout<<node<<" ";
            for(auto x:g[node]){
                    if(!visited[x]){
                            q.push(x);
                            visited[x] = 1;
                    }
            }
    }
 }
 void bfsAllUtil(int start,map<int,bool> &visited){
    queue<int> q;
    visited[start]=true;
    q.push(start);
    while(!q.empty()){
     int node = q.front();
     cout<<node<<" ";
     q.pop();
     for(auto nbrs: g[node]){
             if(!visited[nbrs]){
                     q.push(nbrs);
                     visited[nbrs] = 1;
             }
     }

    }
 }
 void bfsALL(){
    map<int,bool> visited;
  for(auto node_pair:g){   
     int node = node_pair.first;
     if(!visited[node]){
             bfsAllUtil(node,visited);
     }
   }
  }
  void dfs_util(int node,map<int,bool> &visited){
visited[node] = true;
cout<<node<<" ";
for(auto nodes:g[node]){
        if(!visited[nodes])
        dfs_util(nodes,visited);
}
  }
  void dfs(int start){
          map<int,bool> visited;
          dfs_util(start,visited);
  }
  bool detectCycleUtil(int node,int parent,map<int,bool> &visited){
  visited[node] = true;
  for(auto nodes:g[node]){
          if(!visited[nodes]){
                 return detectCycleUtil(nodes,node,visited);
          }
         else if(nodes!=parent)
         return true;
  }
  return false;
  }
  void detectCycle(){
  map<int,bool> visited;
  for(auto node_pair:g){
          int node = node_pair.first;
          if(!visited[node]){
                  bool ans = detectCycleUtil(node,-1,visited);
                  if(ans){
                          cout<<"YES CYCLE IS PRESENT"<<endl;
                          return;
                  }
          }
  }
  cout<<"CYCLE IS NOT PRESENT"<<endl;
  }
};
int main() {
        Graph g;
        g.addEdge(0,1);
        g.addEdge(1,2);
        g.addEdge(2,3);
        g.addEdge(3,4);
        // g.addEdge(4,0);
        g.addEdge(69,70);
        g.addEdge(70,80);
        g.addEdge(80,69);
        // g.printGraph();
        g.bfs(0);
        cout<<'\n';
        g.dfs(69);
        cout<<endl;
        g.bfsALL();
        cout<<'\n';
        g.detectCycle();
        return 0;
}
