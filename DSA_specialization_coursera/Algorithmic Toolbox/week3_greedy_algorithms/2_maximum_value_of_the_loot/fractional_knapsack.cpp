#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item
{
	int value;
	int weight;
};

bool lessItems(Item x,Item y)
{
	double vw1 = (double)x.value/(double)x.weight;
	double vw2 = (double)y.value/(double)y.weight;
	return vw1 < vw2; 
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) 
{
  double final_value;
  int N = weights.size();
  Item* arr = new Item[N];
  for(int i=0;i<N;i++)
  {
  	Item tmp = {values[i],weights[i]};
  	arr[i] = tmp;
  } 
  sort(arr,arr+N,lessItems);

  for(int i=N-1;i>-1;i--)
  {
     if (arr[i].weight <= capacity)
     {
     	final_value += (double)arr[i].value;
     	capacity -= arr[i].weight;
     }
     else
     {
     	final_value += (((double)arr[i].value/(double)arr[i].weight)*((double)capacity));
     	break;
     }
  }

  return final_value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);
  std::cout.setf(ios::fixed);
  std::cout << optimal_value << std::endl;
  return 0;
}
