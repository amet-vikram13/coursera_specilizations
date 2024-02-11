#include <iostream>
#define llu unsigned long long int

llu lcm_fast(llu a,llu b) {

	llu x = (a>b)?a:b;
	llu y = (a<b)?a:b;
	llu tmp;
	while(y!=0)
	{
		tmp = y;
		y = x%y;
		x = tmp;
	}
	llu gcd = x;
	llu lcm = (a*b)/gcd;
	return lcm;

}

int main() {
  llu a, b;
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
