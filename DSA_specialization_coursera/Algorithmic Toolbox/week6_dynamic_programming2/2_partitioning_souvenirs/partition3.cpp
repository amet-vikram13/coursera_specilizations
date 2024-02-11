#include <iostream>
#include <vector>

using std::vector;

bool _partitionK(vector<int> A,int* subsetSum,bool* taken,int subset,int K,int N,int currIdx,int limitIdx)
{
	if (subsetSum[currIdx] == subset)
	{
		if (currIdx == K-2) return true;
		return _partitionK(A,subsetSum,taken,subset,K,N,currIdx+1,N-1);
	}

	for(int i=limitIdx;i>=0;i--)
	{
		if (taken[i]) continue;

		int tmp = subsetSum[currIdx] + A[i];

		if (tmp <= subset)
		{
			taken[i] = true;
			subsetSum[currIdx] += A[i];
			bool nxt = _partitionK(A,subsetSum,taken,subset,K,N,currIdx,i-1);

			taken[i] = false;
			subsetSum[currIdx] -= A[i];
			if (nxt) return true;
		}
	}
	return false;
}

int partitionK(vector<int> A,int K) {
  //write your code here
  if (K == 1) return 1;

  int N = A.size();

  if (N < K) return 0;

  int summ = 0;
  for(int i=0;i<N;i++)
  	summ += A[i];

  if (summ%K !=0) return 0;

  int subset = summ/K;
  int* subsetSum = new int[K];
  bool* taken = new bool[N];

  for(int i=0;i<K;i++)
  	subsetSum[i] = 0;

  for(int i=0;i<N;i++)
  	taken[i] = false;

  subsetSum[0] = A[N-1];
  taken[N-1] = true;

  bool ans = _partitionK(A,subsetSum,taken,subset,K,N,0,N-1);

  delete [] subsetSum;
  delete [] taken;

  return ans;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  std::cout << partitionK(A,3) << '\n';
}
