#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
using std::pair;

void topo_dfs(int v,vector<vector<int> >& adj,bool* marked,vector<int>& topo)
{
  marked[v] = true;
  for(int w : adj[v])
  {
    if(!marked[w])
      topo_dfs(w,adj,marked,topo);
  }
  topo.push_back(v);
}

void dfs(int v,vector<vector<int> >& adj,bool* marked,int* id,int count)
{
  marked[v] = true;
  id[v] = count;
  for(int w : adj[v])
    if(!marked[w])
      dfs(w,adj,marked,id,count);
}

int number_of_strongly_connected_components(vector<vector<int> >& adj,vector<vector<int> >& rev_adj) {
  //write your code here
  bool* marked = new bool[rev_adj.size()];
  vector<int> topo;
  for(int i=0;i<rev_adj.size();i++)
    marked[i] = false;

  for(int s=0;s<rev_adj.size();s++)
    if(!marked[s])
      topo_dfs(s,rev_adj,marked,topo);

  delete [] marked;

  int* id = new int[adj.size()];
  marked = new bool[adj.size()];
  int count = 0;
  for(int i=0;i<adj.size();i++)
  {
    marked[i] = false;
    id[i] = -1;
  }

  while(!topo.empty())
  {
    if (!marked[topo.back()])
    {
      dfs(topo.back(),adj,marked,id,count);
      count++;
    }
    topo.pop_back();
  }

  delete [] marked;
  delete [] id;

  return count;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > rev_adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x-1].push_back(y-1);
    // Reversing graph here only
    rev_adj[y-1].push_back(x-1);
  }
  std::cout << number_of_strongly_connected_components(adj,rev_adj);
}
