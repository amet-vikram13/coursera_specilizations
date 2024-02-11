#include <iostream>
#include <string>
#include <vector>
using namespace std;

int chartoint(char c)
{
	switch(c)
	{
		case '$':
			return 0;
		case 'A':
			return 1;
		case 'C':
			return 2;
		case 'G':
			return 3;
		case 'T':
			return 4;
		default:
			break;
	}
	cout << "ERROR\n";
	return -1;
}

int bwmatching(string bwt,string pat,vector<int> count,vector<vector<int> > count_matrix)
{
	int top = 0;
	int bottom = bwt.size()-1;
	int ans = 0;
	while(top <= bottom)
	{
		//cout << top << " " << bottom << " " << pat << endl;
		if(!pat.empty())
		{
			//cout << pat.back() << endl;
			int c = chartoint(pat.back());
			pat.pop_back();
			//cout << "count: " << count[c] << " " << count[4] << endl;
			//cout << "count matrix: " << count_matrix[top][1] << " " << count_matrix[bottom+1][1] << endl; 
			top    = count[c] + count_matrix[top][c];
			bottom = count[c] + count_matrix[bottom+1][c]-1;
			//cout << top << " " << bottom << " " << pat << endl;
		}
		else
		{
			ans = bottom-top+1;
			break;
		}
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	string bwt; cin >> bwt;
	// bwmatching preprocessing
	vector<int> count(6,0);
	vector<int> e(5,0);
	vector<vector<int> > count_matrix(bwt.size()+1,e);
	for(int i=0;i<bwt.size();i++)
	{
		for(int j=0;j<5;j++)
			count_matrix[i+1][j] = count_matrix[i][j];
		count[chartoint(bwt[i])+1]++;
		count_matrix[i+1][chartoint(bwt[i])]++;
	}
	for(int i=0;i<5;i++)
		count[i+1] += count[i];
	//

	/*
	for(int i=0;i<5;i++)
		cout << count[i] << " ";
	cout << endl << endl;

	for(int i=0;i<=bwt.size();i++)
	{
		for(int j=0;j<5;j++)
			cout << count_matrix[i][j] << " ";
		cout << endl;
	}
	cout << endl;
	*/
	

	int t; cin >> t;
	
	vector<string> pat(t);
	for(int i=0;i<t;i++)
		cin >> pat[i];

	vector<int> ans(t);
	for(int i=0;i<t;i++)
		ans[i] = bwmatching(bwt,pat[i],count,count_matrix);

	for(int i=0;i<t;i++)
		cout << ans[i] << " ";
	cout << endl;

	return 0;
}