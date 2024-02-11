#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using std::vector;

struct Edge
{
	int v;
	int w;
	int weight;
};

class IndexMinPQ
{
	private:
		int* keyVal;
		int* pq;
		int* qp;
		int N;

		bool lessFirst(int i,int j)
		{	return keyVal[pq[i]] < keyVal[pq[j]]; }

		void exch(int i,int j)
		{
			int tmp = pq[i];
			pq[i] = pq[j];
			pq[j] = tmp;

			qp[pq[i]] = i;
			qp[pq[j]] = j;
		}

		void swim(int i)
		{
			while(i>1 && lessFirst(i,i/2))
			{
				exch(i,i/2);
				i = i/2;
			}
		}

		void sink(int i)
		{
			int j;
			while(2*i <= N)
			{
				j = 2*i;
				if(j<N)
					if(lessFirst(j+1,j))
						j++;

				if(lessFirst(i,j))
					break;

				exch(i,j);

				i = j;
			}
		}

	public:
		IndexMinPQ(int cap)
		{
			keyVal = new int[1+cap];
			pq = new int[1+cap];
			qp = new int[1+cap];

			for(int i=0;i<=cap;i++)
			{
				keyVal[i] = -1;
				pq[i] = -1;
				qp[i] = -1;
			}

			N = 0;
		}

		void insert(int vertex,int weight)
		{
			pq[++N] = vertex;
			keyVal[vertex] = weight;
			qp[vertex] = N;
			swim(N);
		}

		int delMin()
		{
			int min_vertex = pq[1];
			exch(1,N--);
			pq[N+1] = -1;
			keyVal[min_vertex] = -1;
			qp[min_vertex] = -1;
			sink(1);
			return min_vertex;
		}

		bool empty()
		{	return N==0; }

		bool contains(int vertex)
		{	return qp[vertex]!=-1; }

		void changeKey(int vertex,int weight)
		{
			keyVal[vertex] = weight;
			swim(qp[vertex]);
			sink(qp[vertex]);
		}
};

void relax(int v,IndexMinPQ& pq,vector<vector<Edge> >& adj,vector<int>& distTo,vector<Edge>& edgeTo)
{
	int w;
	for(Edge e : adj[v])
	{
		w = e.w;
		if (dist[v]!=INT_MAX && distTo[w]>distTo[v]+e.weight)
		{
			distTo[w] = distTo[v] + e.weight;
			edgeTo[w] = {v,w,e.weight};
			if (pq.contains(w)) pq.changeKey(w,distTo[w]);
			else                pq.insert(w,distTo[w]);
		}
	}
}

int distance(vector<vector<Edge> > &adj, int s, int t) 
{
  //write your code her
  vector<Edge> edgeTo(adj.size(),{-1,-1,-1});
  vector<int> distTo(adj.size(),INT_MAX);
  IndexMinPQ pq(adj.size());

  distTo[s] = 0;
  edgeTo[s] = {s,s,0};
  pq.insert(s,0);

  while(!pq.empty())
  	relax(pq.delMin(),pq,adj,distTo,edgeTo);

  int count = 0;

  for(int x=t;edgeTo[x].v!=-1&&x!=edgeTo[x].v;x=edgeTo[x].v)
  	count += edgeTo[x].weight;

  if (count == 0) return -1;

  return count;
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
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t);
}
