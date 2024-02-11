#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

using std::vector;

int optimal_weight(int W, const vector<int> &w) {
  //write your code here
  // dp[i][j] represents max weight 
  // of gold in knapsack j, with gold
  // bars from 1 to i. 
  int n = w.size();
  
  int** dp = new int*[n+1];
  for(int i=0;i<=n;i++)
  	dp[i] = new int[W+1];

  dp[0][0] = 0;

  for(int i=1;i<=n;i++)
  	dp[i][0] = 0;        // since knapsack is 0

  for(int j=1;j<=W;j++)
  	dp[0][j] = 0;	      // since no gold bar

  for(int i=1;i<=n;i++)
  {
  	for(int j=1;j<=W;j++)
  	{

  		dp[i][j] = dp[i-1][j];

  		if (j >= w[i-1])
  		{
  			
  			// this makes sure to include gold bar i at any cost
  			// this is wrong to check - dp[i-1][j]+w[i-1]<=j - X

  			dp[i][j] = max( dp[i-1][j-w[i-1]]+w[i-1], dp[i][j]);

  			// the key is without repeatitions - as you have to exclude gold bar i
  			// and j-w[i-1] without i's weight is dp[i-1][j-w[i-1]] and adding gold bar
  			// makes it dp[i][j].
  		}

  	}
  }

  int ans = dp[n][W];

  for(int i=0;i<=n;i++)
  {
  	int* tmp = dp[i];
  	dp[i] = NULL;
  	delete tmp;
  }

  int** tmp = dp;
  dp = NULL;
  delete tmp;

  return ans;

}


int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
