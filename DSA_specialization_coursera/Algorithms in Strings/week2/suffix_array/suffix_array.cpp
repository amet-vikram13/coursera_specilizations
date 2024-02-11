#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <cstdlib>
#include <chrono>

using std::cin;
using std::cout;
using std::endl;
using std::make_pair;
using std::pair;
using std::string;
using std::vector;
using std::rand;

// Build suffix array of the string text and
// return a vector result of the same length as the text
// such that the value result[i] is the index (0-based)
// in text where the i-th lexicographically smallest
// suffix of text starts.

int charAtd(string txt,int N,int d,int x)
{
  // gives the character at dth position
  // in suffix string with starting position
  // as x
  if (x+d < N) return int(txt[x+d]);
  return -1;
}

void exch(vector<int>& v,int i,int j)
{
	int tmp = v[i];
	v[i] = v[j];
	v[j] = tmp;
}

void three_way_quicksort(string txt,int N,int d,vector<int>& v,int lo,int hi)
{
	if (lo >= hi) return;

	int pivot = lo + rand()%(hi-lo);
	exch(v,pivot,lo);
	pivot = charAtd(txt,N,d,v[lo]);
	int lt=lo, gt=hi, i=lo+1, t;
	
	while(i <= gt)
	{
		t = charAtd(txt,N,d,v[i]);
		if      (pivot > t) exch(v,lt++,i++);
		else if (pivot < t) exch(v,i,gt--);
		else                i++;
	}

	three_way_quicksort(txt,N,d,v,lo,lt-1);
	if (pivot >=0 ) three_way_quicksort(txt,N,d+1,v,lt,gt);
	three_way_quicksort(txt,N,d,v,gt+1,hi);
}

vector<int> BuildSuffixArray(const string& text) {
  int N = text.size();
  vector<int> v(N);
  for(int i=0;i<N;i++)
    v[i] = N-i-1;

  // will sort the suffixes
  // by just storing the starting index
  // of each suffix string in vector v
  three_way_quicksort(text,N,0,v,0,N-1);
  return v;
}

int main() {
  std::ios_base::sync_with_stdio(false); 
  string text;
  cin >> text;
  vector<int> suffix_array = BuildSuffixArray(text);
  for (int i = 0; i < suffix_array.size(); ++i) {
    cout << suffix_array[i] << ' ';
  }
  return 0;
}
