#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

void dfs(int v,vector<vector<int> >& adj,vector<bool>& marked,vector<int>& color,bool* twoColor)
{
  marked[v] = true;
  for(int w : adj[v])
  {
    if (!(*twoColor)) return;
    else if(!marked[w])
    {
      color[w] = 1^color[v];
      dfs(w,adj,marked,color,twoColor);
    }
    else if (color[v]==color[w]) (*twoColor) = false;
  }
}

int bipartite(vector<vector<int> > &adj) {
  //write your code here
  vector<int> color(adj.size(),0);
  vector<bool> marked(adj.size(),false);
  bool* twoColor = new bool;
  (*twoColor) = true;

  for(int s=0;s<adj.size();s++)
    if(!marked[s])
      dfs(s,adj,marked,color,twoColor);

  return (*(twoColor));
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << bipartite(adj);
}
