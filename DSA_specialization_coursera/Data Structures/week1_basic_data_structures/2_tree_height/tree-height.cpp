#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#include <chrono>
#endif

class Node;

class Node {
public:
    int key;
    Node *parent;
    std::vector<Node *> children;

    Node() {
      this->parent = NULL;
    }

    void setParent(Node *theParent) {
      parent = theParent;
      parent->children.push_back(this);
    }
};


int main_with_large_stack_space() {
  std::ios_base::sync_with_stdio(0);
  int n;
  std::cin >> n;

  Node* curr;
  std::vector<Node> nodes;
  nodes.resize(n);
  for (int child_index = 0; child_index < n; child_index++) {
    int parent_index;
    std::cin >> parent_index;
    if (parent_index == -1)
      parent_index = child_index;
    if (parent_index != child_index)
      nodes[child_index].setParent(&nodes[parent_index]);
    nodes[child_index].key = child_index;
    if (parent_index == child_index)
      curr = &nodes[child_index];
  }
  //
  
  // Replace this code with a faster implementation
  std::queue<Node* > q;
  int max_ht = 0,sz;
  q.push(curr);
  while(!q.empty())
  {
    max_ht++;
    sz = q.size();
    for(int i=0;i<sz;i++)
    {
      curr = q.front();
      for(int j=0;j<curr->children.size();j++)
        q.push(curr->children[j]);
      q.pop();
    }
  }
  std::cout << max_ht << std::endl;
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
