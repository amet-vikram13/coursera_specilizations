#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using std::stack;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::queue;

struct Node {
  int key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

bool searchTree(vector<Node> tree)
{
	int curr,sz,left,right;
	queue<int> q;
	q.push(0);
	while(!q.empty())
	{
		sz = q.size();
		while(sz--)
		{
			curr = q.front(); q.pop();
			left = tree[curr].left;
			right = tree[curr].right;
			if (left!=-1)
			{
				if(tree[left].key == tree[curr].key)
					return false;
				q.push(left);
			}
			if (right!=-1)
				q.push(right);
		}
	}
	return true;
}

bool IsBinarySearchTree(const vector<Node>& tree) {
  // Implement correct algorithm here
  if (tree.size()<2) return true;
  
  if (!searchTree(tree))
  	return false;

  vector<int> ino;
  stack<Node> st;
  int root = 0;
  bool done = false;
  while(!done)
  {
      if (root != -1)
      {
          st.push(tree[root]);
          root = tree[root].left;
      }
      else
      {
          if (!st.empty())
          {
              ino.push_back(st.top().key);
              root = st.top().right;
              st.pop();
          }
          else
            done = true;
      }
  }

  for(int i=1;i<ino.size();i++)
    if (ino[i] < ino[i-1])
      return false;

  return true;
}

int main() {
  std::ios_base::sync_with_stdio(false); 
  int nodes;
  cin >> nodes;
  vector<Node> tree;
  for (int i = 0; i < nodes; ++i) {
    int key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }
  if (IsBinarySearchTree(tree)) {
    cout << "CORRECT" << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}
