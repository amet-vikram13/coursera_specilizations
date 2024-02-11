#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#define lli long long int
using std::vector;
using std::string;
using std::max;
using std::min;

// for numbers
// 0 - 0
// 1 - 2
// 2 - 4
// 3 - 6
// 2*i

// for numbers
// 0,1 - 1
// 1,2 - 3
// 2,3 - 5
// 2*i + 1

// i > -1
int idx_n(int i)
{	return 2*i; }

// i > -1 && i < n
int idx_o(int i,int j)
{	return 2*i + 1;  }

lli to_number(char c)
{	return (lli)(c-'0'); }

lli eval(lli a,lli b,char op)
{
	if      (op == '+') return a+b;
	else if (op == '-') return a-b;
	return  a*b;
}

void print_matrix(lli** dp,int n)
{
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
			std::cout << dp[i][j] << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

lli get_maximum_value(const string &exp) 
{
  //write your code here
 
  int n = exp.size()/2;
  
  lli** dp = new lli*[n+1];
  for(int i=0;i<=n;i++)
  	dp[i] = new lli[n+1];

  for(int i=0;i<=n;i++)
  	dp[i][i] = to_number(exp[idx_n(i)]);

  for(int l=2;l<=n+1;l++)
  {
  	for(int i=0;i<=n-l+1;i++)
  	{
  		int j = i+l-1;
  		 	
  	}
  }
  

  return 0;
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
