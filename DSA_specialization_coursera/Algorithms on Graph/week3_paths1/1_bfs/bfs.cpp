#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

int distance(vector<vector<int> > &adj, int s, int t) {
  //write your code here
  vector<bool> marked(adj.size(),false);
  vector<int> edgeTo(adj.size());
  queue<int> q; q.push(s);
  marked[s] = true;
  edgeTo[s] = s;
  while(!q.empty())
  {
    int v = q.front(); q.pop();
    for(int w : adj[v])
    {
      if(!marked[w])
      {
        marked[w] = true;
        q.push(w);
        edgeTo[w] = v;
      }
    }
  }
  
  if (!marked[t]) return -1;

  int count = 0;

  for(int x=t;x!=edgeTo[x];x=edgeTo[x])
    count++;

  return count;
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
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t);
}
