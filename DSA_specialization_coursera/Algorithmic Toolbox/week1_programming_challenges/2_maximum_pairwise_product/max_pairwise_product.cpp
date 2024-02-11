#include <iostream>
#define llu unsigned long long int
using namespace std;

int main()
{
	int n; cin >> n;
	llu first_max = 0ull;
	llu second_max = 0ull;
	llu input = 0ull;

	cin >> input;
	first_max = input;

	cin >> input;
	if (input > first_max)
	{
		second_max = first_max;
		first_max = input;
	}
	else
	{
		second_max = input;
	}

	for(int i=2;i<n;i++)
	{
		cin >> input;
		if      (input > first_max)
		{
			second_max = first_max;
			first_max = input;
		}
		else if (input > second_max)
		{
			second_max = input;
		}
	}

	llu result = first_max*second_max;
	cout << result << endl;
	return 0;
}	