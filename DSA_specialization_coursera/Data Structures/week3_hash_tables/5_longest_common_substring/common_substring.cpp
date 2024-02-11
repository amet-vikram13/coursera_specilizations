#include <iostream>
#include <algorithm>
using namespace std;

struct Answer {
	size_t i, j, len;
};

Answer solve(const string &s, const string &t) {
	Answer ans = {0, 0, 0};
	int n = s.size();
	int m = t.size();
	int res = 0;

	int** dp = new int*[n+1];
	for(int i=0;i<=n;i++)
		dp[i] = new int[m+1];


	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if (i==0 || j==0) dp[i][j] = 0;
			else if (s[i-1]==t[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
			else					 dp[i][j] = 0;
			res = max(res,dp[i][j]);
		}
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	string s, t;
	while (cin >> s >> t) {
		auto ans = solve(s, t);
		cout << ans.i << " " << ans.j << " " << ans.len << "\n";
	}
}
