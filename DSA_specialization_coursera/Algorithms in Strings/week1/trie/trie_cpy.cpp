#include <iostream>
#include <string>
using namespace std;

struct Node
{
  int idx;
  // only A,C,G,T;
  Node* next[4];
  Node()
  {
    idx = 0;
    for(int i=0;i<4;i++)
      next[i] = NULL;
  }
};

class Trie
{
  private:
    Node* root;
    int count;

    int charAtd(string key,int d)
    { 
      if      ('A' == key[d]) return 0;
      else if ('T' == key[d]) return 1;
      else if ('G' == key[d]) return 2;
      return 3;
    }

    char getChar(int i)
    { 
      if      (i == 0) return 'A';
      else if (i == 1) return 'T';
      else if (i == 2) return 'G';
      return 'C';
    }

    Node* _push(Node* x,int d,string key)
    {
      if (x == NULL) 
      {
        x = new Node();
        count += 1;
        x->idx = count;
      }
      if (d == key.size()) return x;
      int c = charAtd(key,d);
      //cout << key[d] << endl;
      x->next[c] = _push(x->next[c],d+1,key);
      return x;
    }

    void _printTrie(Node* x)
    {
      for(int i=0;i<4;i++)
      {
        if (x->next[i]!=NULL)
        {
          cout<<x->idx<<"->"<<x->next[i]->idx<<":"<<getChar(i)<<endl;
          _printTrie(x->next[i]);
        }
      }
    }

  public:
    Trie()
    {
      root = new Node();
      count = 0;
    }

    void push(string key)
    { root = _push(root,0,key); }

    void printTrie()
    {
      _printTrie(root);
    }
};

int main()
{
  ios_base::sync_with_stdio(false);
  Trie tr;
  int t; string inp; cin >> t;
  while(t--)
  {
    cin >> inp;
    tr.push(inp);
  }
  tr.printTrie();
  return 0;
}