#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>
#define lli long long int
using namespace std;

/*
OPTIMAL GREEDY SOLUTION BY USING DEQUE
*/

lli max_dot_product(vector<int> a, vector<int> b) 
{
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());

  lli summ = 0ll;

  for(int i=0;i<a.size();i++)
  {
    summ += ((lli)a[i]*(lli)b[i]);
  }

  return summ;	
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(a, b) << std::endl;
}
