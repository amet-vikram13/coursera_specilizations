#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <queue>

using std::vector;
using std::queue;

struct Edge
{
	int from;
	int to;
	int weight;
};


void findNegativeCycle(vector<vector<Edge> > &adj,vector<int>& distTo,bool& hasNegativeCycle)
{
	int w;
	for(int v=0;v<adj.size()&&(!hasNegativeCycle);v++)
	{
		for(Edge e : adj[v])
		{
			w = e.to;
			if (distTo[v]!=INT_MAX && distTo[w]>distTo[v]+e.weight)
			{
				hasNegativeCycle = true;
				break;
			}
		}
	}
}

void relax(int v,vector<vector<Edge> > &adj,vector<int>& distTo,vector<bool>& onQ,queue<int>& q,bool& hasNegativeCycle,int& count,vector<bool>& marked)
{
	marked[v] = true; int w;
	for(Edge e : adj[v])
	{
		w = e.to;
		if (distTo[v]!=INT_MAX && distTo[w]>distTo[v]+e.weight)
			distTo[w]=distTo[v]+e.weight;

		if(!onQ[w])
		{
			onQ[w] = true;
			q.push(w);
		}
	}

	count++;

	if((count % adj.size()) == 0)
		findNegativeCycle(adj,distTo,hasNegativeCycle);
}

bool negative_cycle(vector<vector<Edge> > &adj)
{
	int V = adj.size();
	vector<int> distTo(V,INT_MAX);
	vector<bool> marked(V,false);
	vector<bool> onQ(V,false);
	queue<int> q;
	int count;
	bool hasNegativeCycle = false;

	for(int s=0;s<V&&(!hasNegativeCycle);s++)
	{
		if(!marked[s])
		{
			distTo[s] = 0;
			onQ[s] = true;
			q.push(s);
			count = 0;

			while(!q.empty() && !hasNegativeCycle)
			{
				relax(q.front(),adj,distTo,onQ,q,hasNegativeCycle,count,marked);
				onQ[q.front()] = false;
				q.pop();
			}
		}
	}

	return hasNegativeCycle;

}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<Edge> > adj(n, vector<Edge>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back({x-1,y-1,w});
  }
  std::cout << negative_cycle(adj);
}
