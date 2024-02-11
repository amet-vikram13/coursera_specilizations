#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

using std::vector;
using std::stack;
using std::ios_base;
using std::cin;
using std::cout;

struct TreeNode
{
	int key;
	int left_idx;
	int right_idx;
};

class TreeOrders {
  int n;
  vector<TreeNode> nodes;

public:
  void read() {
    cin >> n;
    nodes.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> nodes[i].key >> nodes[i].left_idx >> nodes[i].right_idx;
    }
  }


  vector <int> pre_order() {
    vector<int> result;
    // Finish the implementation
    // You may need to add a new recursive method to do that
    stack<TreeNode> st;
    int root = 0;
   	bool done = false;
   	while(!done)
   	{
   		if (root != -1)
   		{
   			result.push_back(nodes[root].key);
   			st.push(nodes[root]);
   			root = nodes[root].left_idx;
   		}
   		else
   		{
   			if (!st.empty())
   			{
   				root = st.top().right_idx;
   				st.pop();
   			}
   			else
   				done = true;
   		}
   	}
    return result;
  }

  vector <int> in_order() {
    vector<int> result;    
    // Finish the implementation
    // You may need to add a new recursive method to do that
    stack<TreeNode> st;
    int root = 0;
    bool done = false;
    while(!done)
    {
    	if (root != -1)
    	{
    		st.push(nodes[root]);
    		root = nodes[root].left_idx;
    	}
    	else
    	{
    		if (!st.empty())
    		{
    			result.push_back(st.top().key);
    			root = st.top().right_idx;
    			st.pop();
    		}
    		else
    			done = true;
    	}
    }
    return result;
  }

  vector <int> post_order() {
    vector<int> result;
    // Finish the implementation
    // You may need to add a new recursive method to do that
    stack<TreeNode> st;
    int root = 0;
    bool done = false;
    while(!done)
    {
    	if (root != -1)
    	{
    		result.push_back(nodes[root].key);
    		st.push(nodes[root]);
    		root = nodes[root].right_idx;
    	}
    	else
    	{
    		if (!st.empty())
    		{
    			root = st.top().left_idx;
    			st.pop();
    		}
    		else
    			done = true;
    	}
    }
    reverse(result.begin(),result.end());
    return result;
  }
};

void print(vector <int> a) {
  for (size_t i = 0; i < a.size(); i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << a[i];
  }
  cout << '\n';
}

int main_with_large_stack_space() {
  ios_base::sync_with_stdio(0);
  TreeOrders t;
  t.read();
  print(t.in_order());
  print(t.pre_order());
  print(t.post_order());
  return 0;
}

int main (int argc, char **argv)
{
#if defined(__unix__) || defined(__APPLE__)
  // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
      if (rl.rlim_cur < kStackSize)
      {
          rl.rlim_cur = kStackSize;
          result = setrlimit(RLIMIT_STACK, &rl);
          if (result != 0)
          {
              std::cerr << "setrlimit returned result = " << result << std::endl;
          }
      }
  }
#endif

  return main_with_large_stack_space();
}

