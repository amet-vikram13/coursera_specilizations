#include <iostream>
#include <vector>
using namespace std;

int compute_min_refills(int dist, int tank, vector<int> & stops) 
{
  // write your code here
  int current_refill=0,last_refill,number_refills=0;
  int* stations = new int[stops.size()+2];
  stations[0] = 0;
  for(int i=1;i<=stops.size();i++)
  	stations[i] = stops[i-1];
  stations[stops.size()+1] = dist;
  int N = stops.size()+1;
 
  while(current_refill < N)
  {
  	last_refill = current_refill;
	while(current_refill<N && stations[current_refill+1]-stations[last_refill]<=tank)
	{
		current_refill += 1;
	}

	if (current_refill == last_refill)
		return -1;

	if (current_refill < N)
		number_refills += 1;

	
  }
  return number_refills;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
