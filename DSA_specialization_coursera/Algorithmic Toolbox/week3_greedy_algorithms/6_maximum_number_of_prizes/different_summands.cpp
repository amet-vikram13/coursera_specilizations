#include <iostream>
#include <vector>
using namespace std;

vector<int> optimal_summands(int n) {
  
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}

// 6
// 1 , 2 , 3 , 4 , 5
// 1 + 5
// 2 + 4
// 1 + 2 + 3

// 8
// 1 , 2 , 3 , 4 , 5 , 6 , 7
// 1 + 7
// 1 + 2 + 5
// 2 + 6
// 3 + 5
// 1 + 3 + 4

// 11
// 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10
// 6 + 4 + 1
// 6 + 3 + 2
// 7 + 3 + 1
// 8 + 2 + 1
// 5 + 3 + 2 + 1