#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::string;
using std::vector;

// FAILING AT AAACAC$

struct Node
{
	int left;
	int right;
	Node* next[5];
	Node()
	{
		left  = -1;
		right = -1;
		for(int i=0;i<5;i++)
			next[i] = NULL;
	}
};

class CompressedSuffixTrie
{
	private:
		Node* root;
		string txt;
		vector<string> v;

		int charAtd(int d)
		{
			if (txt[d]=='$') return 0;
			if (txt[d]=='A') return 1;
			if (txt[d]=='C') return 2;
			if (txt[d]=='G') return 3;
			return 4;
		}

		Node* _push(Node* x,int l,int r)
		{
			if (x == NULL) 
			{
				x = new Node();
				x->left = l-1;
				x->right = r;
				return x;
			}
			else if (x->left != x->right)
			{
				x->next[charAtd(x->left+1)] = new Node();
				x->next[charAtd(x->left+1)]->left = x->left+1;
				x->next[charAtd(x->left+1)]->right = x->right;
				x->left = l-1;
				x->right = x->left;
			}
			int c = charAtd(l);
			x->next[c] = _push(x->next[c],l+1,r);
			int tmp = -1;
			int count = 0;
			for(int i=0;i<5;i++)
			{
				if(x->next[i]!=NULL)
				{
					tmp = i;
					count += 1;
				}
			}
			if (x!=root && count == 1)
			{
				Node* node = x->next[tmp];
				node->left = x->left;
				delete x;
				x = NULL;
				return node;
			}
			return x;
		}

		void traverseAllNodes(Node* x)
		{
			if (x!=root) v.push_back(txt.substr(x->left,x->right-x->left+1));
			for(int i=0;i<5;i++)
				if(x->next[i]!=NULL)
					traverseAllNodes(x->next[i]);
			return;
		}

	public:
		CompressedSuffixTrie(string inp)
		{
			txt = inp;
			root = new Node();
			int r = txt.size()-1;
			for(int l=r;l>-1;l--)
			{
				root = _push(root,l,r);
				/*
				v.clear();
				traverseAllNodes(root);
				cout << l << " ";
				for(int i=0;i<v.size();i++)
					cout << v[i] << " ";
				cout << endl;
				*/
			} 
			traverseAllNodes(root);
		}

		vector<string> giveEdges()
		{	return v; }
};


// Build a suffix tree of the string text and return a vector
// with all of the labels of its edges (the corresponding 
// substrings of the text) in any order.
vector<string> ComputeSuffixTreeEdges(const string& text) {
  // Implement this function yourself
  vector<string> result;
  CompressedSuffixTrie tr(text);
  result = tr.giveEdges();
  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  string text;
  cin >> text;
  vector<string> edges = ComputeSuffixTreeEdges(text);
  for (int i = 0; i < edges.size(); ++i) {
    cout << edges[i] << endl;
  }
  return 0;
}
