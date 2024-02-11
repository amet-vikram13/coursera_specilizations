#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::vector;

struct Node
{
	int idx;
	int tables;
};

class WQUFPC
{
	private:
		Node* id;
		int count;
		int max_t;

		int root(int i)
		{
			while(i!=id[i].idx)
			{
				// id[i] = id[id[i]]
				id[i].idx = id[id[i].idx].idx;
				i = id[i].idx;
			}
			return i;
		}

	public:
		WQUFPC(Node arr[],int n)
		{
			count = n;
			id = arr;
			max_t = id[0].tables;
			for(int i=1;i<n;i++)
				max_t = (id[i].tables>max_t)?id[i].tables:max_t;

		}

		int connect(int p,int q)
		{	
			int p_root = root(p);
			int q_root = root(q);
			if (id[p_root].idx == id[q_root].idx) return max_t;

			id[p_root].tables += id[q_root].tables;
			id[q_root].tables = 0;
			max_t = (id[p_root].tables>max_t)?id[p_root].tables:max_t;

			id[q_root].idx = p_root;

			return max_t;
		}
};


int main()
{
	std::ios_base::sync_with_stdio(false);
	int n,m,u,v; cin >> n >> m;
	Node arr[n];
	for(int i=0;i<n;i++)
	{
		arr[i].idx = i;
		cin >> arr[i].tables;
	}
	WQUFPC uf(arr,n);
	while(m--)
	{
		cin >> v >> u;
		cout << uf.connect(v-1,u-1) << endl;
	}
	return 0;
}