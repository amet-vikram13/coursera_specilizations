#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {
  //write your code here
  int x = a.size();
  int y = b.size();
  int z = c.size();
  int dp[x+1][y+1][z+1];
  
  for(int i=0;i<x+1;i++)
    for(int j=0;j<y+1;j++)
      dp[i][j][0] = 0;

  for(int j=0;j<y+1;j++)
    for(int k=0;k<z+1;k++)
      dp[0][j][k] = 0;

  for(int i=0;i<x+1;i++)
    for(int k=0;k<z+1;k++)
      dp[i][0][k] = 0;

  for(int i=1;i<x+1;i++)
  {
    for(int j=1;j<y+1;j++)
    {
      for(int k=1;k<z+1;k++)
      {
        if (a[i-1]==b[j-1] && b[j-1]==c[k-1])
        {
          dp[i][j][k] = dp[i-1][j-1][k-1]+1;
        }
        else
        {
          dp[i][j][k] = max(dp[i][j-1][k-1],dp[i][j][k]);
          dp[i][j][k] = max(dp[i][j-1][k],dp[i][j][k]);
          dp[i][j][k] = max(dp[i][j][k-1],dp[i][j][k]);
          
          dp[i][j][k] = max(dp[i-1][j][k-1],dp[i][j][k]);
          dp[i][j][k] = max(dp[i][j][k-1],dp[i][j][k]);
          dp[i][j][k] = max(dp[i-1][j][k],dp[i][j][k]);
          
          dp[i][j][k] = max(dp[i-1][j-1][k],dp[i][j][k]);
          dp[i][j][k] = max(dp[i][j-1][k],dp[i][j][k]);
          dp[i][j][k] = max(dp[i-1][j][k],dp[i][j][k]);
        }
      }
    }
  }
  return dp[x][y][z];
}

int main() {
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c) << std::endl;
}
