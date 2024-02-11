#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <cfloat>

using std::vector;

struct Point
{
	int x;
	int y;
};

double eucd(Point p1,Point p2)
{
	return std::sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}

class IndexMinPQ
{
	private:
		double* KeyVal;
		int* pq;
		int* qp;
		int N;

		bool lessFirst(int i,int j)
		{	return KeyVal[pq[i]] < KeyVal[pq[j]]; }

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
			while(2*i<=N)
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
			KeyVal = new double[1+cap];
			pq = new int[1+cap];
			qp = new int[1+cap];

			for(int i=0;i<=cap;i++)
				qp[i] = -1;

			N = 0;
		}

		void insert(int vertex,double weight)
		{
			pq[++N] = vertex;
			KeyVal[vertex] = weight;
			qp[vertex] = N;
			swim(N);
		}

		int delMin()
		{
			int min_vertex = pq[1];
			exch(1,N--);
			qp[min_vertex] = -1;
			sink(1);
			return min_vertex;
		}

		bool empty()
		{	return N==0; }

		bool contains(int vertex)
		{	return qp[vertex]!=-1; }

		void changeKey(int vertex,double weight)
		{
			KeyVal[vertex] = weight;
			swim(qp[vertex]);
			sink(qp[vertex]);
		}
};

void visit(int i,vector<double>& distTo,vector<bool>& marked,IndexMinPQ& pq,vector<double>& mst,vector<Point>& p)
{
	marked[i] = true;
	for(int j=0;j<p.size();j++)
	{
		if(marked[j]) continue;

		if ( eucd(p[i],p[j]) < distTo[j] )
		{
			distTo[j] = eucd(p[i],p[j]);
			mst[j] = eucd(p[i],p[j]);
			if (pq.contains(j)) pq.changeKey(j,distTo[j]);
			else                pq.insert(j,distTo[j]);
		}
	}
}



double minimum_distance(vector<Point> p) {
  //write your code here
  double result = 0.0;
  int V = p.size();
  vector<double> distTo(V,DBL_MAX);
  vector<bool> marked(V,false);
  vector<double> mst(V,0.0);
  IndexMinPQ pq(V);

  distTo[0] = 0.0;
  pq.insert(0,0.0);

  while(!pq.empty())
  	visit(pq.delMin(),distTo,marked,pq,mst,p);

  for(int i=0;i<mst.size();i++)
  	result += mst[i];

  return result;
} 

int main() {
  size_t n;
  std::cin >> n;
  vector<Point> p(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> p[i].x >> p[i].y;
  }
  std::cout << std::fixed << std::setprecision(10) << minimum_distance(p) << std::endl;
}
