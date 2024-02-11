#include <iostream>
#include <string>
#include <vector>

using std::string;
typedef unsigned long long ull;

struct Data {
    string pattern, text;
};

class KMP
{
	private:
		string pat;
		std::vector<int> ans;
		int** dfa;
		int M;
		int R;

		int charAt(char c)
		{
			if (int(c) > 90) return (int(c)-6-int('A'));
			else             return (int(c)-int('A'));
		}

		void buildDFA()
		{
			dfa[charAt(pat[0])][0] = 1;
			for (int X=0,j=1; j<M; j++)
			{
				for(int c=0; c<R; c++)
					dfa[c][j] = dfa[c][X];

				dfa[charAt(pat[j])][j] = j+1;
				X = dfa[charAt(pat[j])][X];
			}
		}
	public:
		KMP(string pattern)
		{
			pat = pattern;
			M = pat.size();
			R = 52;
			dfa = new int*[R];
			
			for (int i=0;i<R;i++)
				dfa[i] = new int[M];

			for (int i=0;i<R;i++)
				for(int j=0;j<M;j++)
					dfa[i][j] = 0;

			buildDFA();
		}

		std::vector<int> search(string txt)
		{
			int i,j,N = txt.size();
			j = 0;
			for(int i=0;i<N;i++)
			{
				j = dfa[charAt(txt[i])][j];
				if (j == M)
				{
					ans.push_back(i-M+1);
					i = i-M+1;
					j = 0;
				}
			}
			return ans;
		}
};

Data read_input() {
    Data data;
    std::cin >> data.pattern >> data.text;
    return data;
}

void print_occurrences(const std::vector<int>& output) {
    for (size_t i = 0; i < output.size(); ++i)
        std::cout << output[i] << " ";
    std::cout << "\n";
}

std::vector<int> get_occurrences(const Data& input) {
    const string& s = input.pattern, t = input.text;
    KMP kmp(s);
    std::vector<int> ans = kmp.search(t);
    return ans;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    print_occurrences(get_occurrences(read_input()));
    return 0;
}
