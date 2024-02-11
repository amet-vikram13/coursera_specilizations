#include <iostream>
#include <vector>
#include <queue>

using std::cin;
using std::cout;
using std::vector;
using std::max;
using std::deque;

void max_sliding_window_naive(vector<int> const & A, int w) {
    deque<int> d;
    d.push_back(0);
    for(int i=1;i<w;i++)
    {
        while(!d.empty() && A[i]>=A[d.back()])
            d.pop_back();
        d.push_back(i);
    }

    for(int i=w;i<=A.size();i++)
    {
        cout << A[d.front()] << " ";

        if (i<A.size())
        {
            while(!d.empty() && A[i]>=A[d.back()])
                d.pop_back();
            d.push_back(i);

            
            while(i-d.front()+1 > w)
                d.pop_front();
        }
    }

    return;
}


int main() {
    int n = 0;
    cin >> n;

    vector<int> A(n);
    for (size_t i = 0; i < n; ++i)
        cin >> A.at(i);

    int w = 0;
    cin >> w;

    max_sliding_window_naive(A, w);

    return 0;
}
