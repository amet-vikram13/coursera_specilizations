#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;

class HeapBuilder {
 private:
  vector<int> data_;
  int N;
  vector< pair<int, int> > swaps_;

  void WriteResponse() const {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i) {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }

  void ReadData() {
    int n;
    cin >> n;
    N = n;
    data_.resize(n+1);
    for(int i = 1; i <= n; ++i)
      cin >> data_[i];
  }

  bool lessFirst(int i,int j)
  {	return data_[i] < data_[j]; }

  void exch(int i,int j)
  {
  	swaps_.push_back(make_pair(i-1,j-1));
  	int tmp = data_[i];
  	data_[i] = data_[j];
  	data_[j] = tmp;
  }

  void sink(int i)
  {
  	while(2*i <= N)
  	{
  		int j = 2*i;
  		if (j < N)
  			if (lessFirst(j+1,j))
  				j++;
  		
  		if (lessFirst(i,j))
  			break;

  		exch(i,j);

  		i = j;
  	}
  }

  void GenerateSwaps() {
    swaps_.clear();
    // The following naive implementation just sorts 
    // the given sequence using selection sort algorithm
    // and saves the resulting sequence of swaps.
    // This turns the given array into a heap, 
    // but in the worst case gives a quadratic number of swaps.
    //
    // TODO: replace by a more efficient implementation

    for(int k=N/2;k>=1;k--)
    	sink(k);
    
  }

 public:
  void Solve() {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
