#include <iostream>
#include <climits>
int get_change(int m) {
  //write your code here
	int change[m+1];
	change[0] = -1;
	change[1] = 1;
	change[2] = 2;
	change[3] = 1;
	change[4] = 1;
	if (m <= 4)
		return change[m];
	int coins[3] = {1,3,4};
	int min_change;
	for(int i=5;i<=m;i++)
	{
		min_change = INT_MAX;
		for(int j=0;j<3;j++)
		{
			if (change[i-coins[j]]!=-1)
				if(1+change[i-coins[j]] < min_change)
					min_change = 1+change[i-coins[j]];
		}

		if (min_change == INT_MAX)
			change[i] = -1;
		else
			change[i] = min_change;
	}

	return change[m];
  
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
