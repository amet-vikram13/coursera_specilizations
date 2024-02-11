#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  int m = partition2(a, l, r);

  randomized_quick_sort(a, l, m - 1);
  randomized_quick_sort(a, m + 1, r);
}

void three_way_quick_sort(vector<int> &a,int lo,int hi,int n)
{
  if (lo >= hi)
    return;

  int pivot = lo + rand() % (hi-lo+1);
  swap(a[lo],a[pivot]);
  pivot = a[lo];

  int lt = lo, gt = hi, i = lo+1;

  // [0,lt)  -> elements less than a[pivot]
  // [lt,i)  -> elements equal to a[pivot]
  // [i,gt]  -> elements unprocessed
  // (gt,hi] -> elements greater than a[pivot]
  while(i <= gt)
  {
    if      (a[i] < pivot) { swap(a[lt++],a[i++]); }
    else if (a[i] > pivot) { swap(a[i],a[gt--]); }
    else                      { i++; }
  }
  
  three_way_quick_sort(a,lo,lt-1,n);
  three_way_quick_sort(a,gt+1,hi,n);

}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  //randomized_quick_sort(a, 0, a.size() - 1);
  three_way_quick_sort(a,0,a.size()-1,a.size());
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
