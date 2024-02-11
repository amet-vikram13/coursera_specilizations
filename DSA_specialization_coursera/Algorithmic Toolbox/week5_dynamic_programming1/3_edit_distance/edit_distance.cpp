#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int edit_distance(const string &str1, const string &str2) {
  int n = str1.size();
  int m = str2.size();
  int dp[n+1][m+1];

  dp[0][0] = 0;
  for(int i=1;i<=n;i++)
  	dp[i][0] = i;
  for(int j=1;j<=m;j++)
  	dp[0][j] = j;

  for(int i=1;i<=n;i++)
  {
  	for(int j=1;j<=m;j++)
  	{
  		if (str1[i-1]==str2[j-1])
  		{
  			dp[i][j] = dp[i-1][j-1];
  		}
  		else
  		{
  			dp[i][j] = 1+min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
  		}
  	}
  }
  return dp[n][m];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
