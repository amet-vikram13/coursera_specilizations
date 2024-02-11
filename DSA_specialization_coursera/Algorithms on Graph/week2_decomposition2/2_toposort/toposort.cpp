#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;
using std::pair;

void dfs(vector<vector<int> > &adj, vector<bool> &marked, vector<int> &order, int v) {
  //write your code here
  marked[v] = true;
  for(int w : adj[v])
    if(!marked[w])
      dfs(adj,marked,order,w);
  order.push_back(v);
}     

vector<int> toposort(vector<vector<int> > adj) {
  vector<bool> marked(adj.size(), false);
  vector<int> order;
  //write your code here
  for(int s=0;s<adj.size();s++)
    if(!marked[s])
      dfs(adj,marked,order,s);
  return order;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  vector<int> order = toposort(adj);
  for (int i = order.size()-1; i > -1; i--) {
    std::cout << order[i] + 1 << " ";
  }
}
