#include <iostream>
#include <vector>

using std::vector;
using std::pair;

void dfs(int v,vector<vector<int> > &adj,bool* marked,bool* onStack,bool* hasCycle)
{
	marked[v] = true;
	onStack[v] = true;
	for(int w : adj[v])
	{
		if      ((*hasCycle)) return;
		else if (!marked[w])  dfs(w,adj,marked,onStack,hasCycle);
		else if (onStack[w])  (*hasCycle) = true;
	}
	onStack[v] = false;
}

int acyclic(vector<vector<int> > &adj) {
  //write your code here
  bool* hasCycle = new bool;
  (*hasCycle) = false;
  bool* marked = new bool[adj.size()];
  bool* onStack = new bool[adj.size()];
  for(int i=0;i<adj.size();i++)
  {
  	marked[i] = false;
  	onStack[i] = false;
  }

  for(int s=0;s<adj.size();s++)
  	if(!marked[s])
  		dfs(s,adj,marked,onStack,hasCycle);

  delete [] marked;
  delete [] onStack;

  return (*hasCycle);
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
  std::cout << acyclic(adj);
}
