#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> optimal_sequence(int n) {

  vector<vector<int> > v(n+1);
  v[1].push_back(1);
  if (n==1) { return v[1]; }
  v[2].push_back(1); v[2].push_back(2);
  if (n==2) { return v[2]; }
  v[3].push_back(1); v[3].push_back(3);
  if (n==3) { return v[3]; }

  for(int i=4;i<=n;i++)
  {
    if      (i%6==0)
    {
      if      (v[i/3].size()-1 <= v[i/2].size()-1 && v[i/3].size()-1 <= v[i-1].size()-1)
      {
        v[i] = v[i/3];
        v[i].push_back(i);
      }
      else if (v[i/2].size()-1 <= v[i/3].size()-1 && v[i/2].size()-1 <= v[i-1].size()-1)
      {
        v[i] = v[i/2];
        v[i].push_back(i);
      }
      else if (v[i-1].size()-1 <= v[i/3].size()-1 && v[i-1].size()-1 <= v[i/2].size()-1)
      {
        v[i] = v[i-1];
        v[i].push_back(i);
      }
    }
    else if (i%3==0)
    {
      if      (v[i/3].size()-1 <= v[i-1].size()-1)
      {
        v[i] = v[i/3];
        v[i].push_back(i);
      }
      else
      {
        v[i] = v[i-1];
        v[i].push_back(i);
      }
    }
    else if (i%2==0)
    {
      if      (v[i/2].size()-1 <= v[i-1].size()-1)
      {
        v[i] = v[i/2];
        v[i].push_back(i);
      }
      else
      {
        v[i] = v[i-1];
        v[i].push_back(i);
      }
    }
    else
    {
      v[i] = v[i-1];
      v[i].push_back(i);
    }
  }

  return v[n];
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
