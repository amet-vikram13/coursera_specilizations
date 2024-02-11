#include <iostream>
#include <vector>

using std::vector;
using std::pair;

void dfs(int v,vector<vector<int> > &adj,bool* marked,int* id,int count)
{
  marked[v] = true;
  id[v] = count;
  for(int w : adj[v])
    if(!marked[w])
      dfs(w,adj,marked,id,count);
}

int number_of_components(vector<vector<int> > &adj) {
  //write your code here
  int* id = new int[adj.size()];
  bool* marked = new bool[adj.size()];
  for(int i=0;i<adj.size();i++)
  {
    marked[i] = false;
    id[i] = -1;
  }
  int count = 0;

  for(int s=0;s<adj.size();s++)
  {
    if(!marked[s])
    {
      dfs(s,adj,marked,id,count);
      count++;
    }
  }

  delete [] marked;
  delete [] id;

  return count;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << number_of_components(adj);
}
