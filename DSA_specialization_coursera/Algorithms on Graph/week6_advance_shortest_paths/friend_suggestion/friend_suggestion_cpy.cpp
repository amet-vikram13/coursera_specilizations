#include <iostream>
#include <list>
#include <unordered_set>
using namespace std;

struct Edge
{
	int from;
	int to;
	int weight;
};

class Graph
{
	private:
		int Ver;
		int Edg;
		list<Edge>* adjList;
		list<Edge>* rev_adjList;

	public:
		Graph(int numV)
		{
			Ver = numV;
			Edg = 0;
			adjList = new list<Edge>[numV];
			rev_adjList = new list<Edge>[numV];
		}

		void addEdge(int v,int w,int weight)
		{
			adjList[v].push_back({v,w,weight});
			rev_adjList[w].push_back({w,v,weight});
			Edg++;
		}

		list<Edge> adj(int v)
		{	return adjList[v]; }

		list<Edge> rev_adj(int v)
		{	return rev_adjList[v]; }

		int V()
		{	return Ver; }

		int E()
		{	return Edg; }
};

class IndexMinPQ
{
	private:
		int* keys;
		int* pq;
		int* qp;
		int N;

		bool lessFirst(int i,int j)
		{	keys[pq[i]] < keys[pq[j]]; }

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
			keys = new int[1+cap];
			pq = new int[1+cap];
			qp = new int[1+cap];

			for(int i=0;i<=cap;i++)
				qp[i] = -1;

			N = 0;
		}

		void insert(int vertex,int weight)
		{
			pq[++N] = vertex;
			keys[vertex] = weight;
			qp[vertex] = N;
			swim(N);
		}

		bool contains(int vertex)
		{	return qp[vertex]!=-1; }

		bool empty()
		{	return N==0; }

		int delMin()
		{
			int min_vertex = pq[1];
			exch(1,N--);
			qp[min_vertex] = -1;
			sink(1);
			return min_vertex;
		}

		void changeKey(int vertex,int weight)
		{
			keys[vertex] = weight;
			swim(qp[vertex]);
			sink(qp[vertex]);
		}
};

class BidirectionalDijkstra
{
	private:
		int* distTo;
		int* rev_distTo;
		int distStoT;

	public:
		BidirectionalDijkstra(Graph G,int src,int dest)
		{
			distStoT = -1;

			if (src == dest)
			{
				distStoT = 0;
				return;
			}

			distTo = new int[G.V()];
			rev_distTo = new int[G.V()];
			for(int i=0;i<G.V();i++)
			{
				distTo[i] = INT_MAX;
				rev_distTo[i] = INT_MAX;
			}
			IndexMinPQ pq(G.V());
			IndexMinPQ rev_pq(G.V());

			distTo[src] = 0;
			rev_distTo[dest] = 0;
			pq.insert(src,0);
			rev_pq.insert(dest,0);

			unordered_set<int> processed;
			unordered_set<int> rev_processed;

			int v
			while(!pq.empty() && !rev_pq.empty())
			{
				v = pq.delMin();
				relax(v,pq,distTo,processed);

				if(rev_processed.find(v)!=rev_processed.end())
				{
					distStoT = distTo[v] + rev_distTo[v];
					break;
				}

				v = rev_pq.delMin();
				relax(v,rev_pq,rev_distTo,rev_processed);

				if(processed.find(v)!=processed.end())
				{
					distStoT = distTo[v] + rev_distTo[v];
					break;
				}
			}

			

		}
};