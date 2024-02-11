#include <iostream>
#include <vector>
#define llu unsigned long long int
using std::vector;

llu merge(vector<int> &a,vector<int> &b,int left,int mid,int right)
{
  llu inversions = 0ull;
  int n1 = mid;
  int n2 = right;
  int i=left,j=mid+1,k=0;
  
  while(i<=n1 && j<=n2)
  {
    if (a[i]<=a[j])
    {
      b[k++] = a[i++];
    }
    else
    {
      inversions += (llu)(mid-i+1);
      b[k++] = a[j++];
    }
  }

  while(i<=n1)
    b[k++] = a[i++];

  while(j<=n2)
    b[k++] = a[j++];

  for(int x=0;x<=right-left;x++)
    a[left+x] = b[x];

  return inversions;
}

llu get_number_of_inversions(vector<int> &a, vector<int> &b, int left, int right) {
  llu number_of_inversions = 0ull;
  if (left < right)
  {
    int mid = left + ((right-left)/2);
    number_of_inversions += get_number_of_inversions(a,b,left,mid);
    number_of_inversions += get_number_of_inversions(a,b,mid+1,right);
    number_of_inversions += merge(a,b,left,mid,right);

  }
  return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (int i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, b, 0, a.size()-1) << '\n';
}
