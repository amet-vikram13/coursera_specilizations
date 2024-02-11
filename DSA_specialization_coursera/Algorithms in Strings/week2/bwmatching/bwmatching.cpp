#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using std::cin;
using std::istringstream;
using std::map;
using std::string;
using std::vector;

// Preprocess the Burrows-Wheeler Transform bwt of some text
// and compute as a result:
//   * starts - for each character C in bwt, starts[C] is the first position 
//       of this character in the sorted array of 
//       all characters of the text.
//   * occ_count_before - for each character C in bwt and each position P in bwt,
//       occ_count_before[C][P] is the number of occurrences of character C in bwt
//       from position 0 to position P inclusive.
int charToint(char c)
{
  if (c == '$') return 0;
  if (c == 'A') return 1;
  if (c == 'C') return 2;
  if (c == 'G') return 3;
  return 4;
}

char intTochar(int x)
{
  if (x == 0) return '$';
  if (x == 1) return 'A';
  if (x == 2) return 'C';
  if (x == 3) return 'G';
  if (x == 4) return 'T';
  return ' ';
}

void PreprocessBWT(const string bwt, map<char, int>& starts, map<char, vector<int> >& occ_count_before) 
{
  // Implement this function yourself
  vector<int> e(bwt.size()+1,0);
  occ_count_before['$'] = e;
  occ_count_before['A'] = e;
  occ_count_before['C'] = e;
  occ_count_before['G'] = e;
  occ_count_before['T'] = e;
  starts['$'] = 0;
  for(int i=0;i<bwt.size();i++)
  {
    starts[intTochar(charToint(bwt[i])+1)]++;
    occ_count_before['$'][i+1] = occ_count_before['$'][i];
    occ_count_before['A'][i+1] = occ_count_before['A'][i];
    occ_count_before['C'][i+1] = occ_count_before['C'][i];
    occ_count_before['G'][i+1] = occ_count_before['G'][i];
    occ_count_before['T'][i+1] = occ_count_before['T'][i];
    occ_count_before[bwt[i]][i+1]++;
  }
  for(int i=0;i<5;i++)
    starts[intTochar(i+1)] += starts[intTochar(i)];
}

// Compute the number of occurrences of string pattern in the text
// given only Burrows-Wheeler Transform bwt of the text and additional
// information we get from the preprocessing stage - starts and occ_count_before.
int CountOccurrences(string pattern, const string bwt,map<char, int> starts,map<char, vector<int> > occ_count_before) 
{
  // Implement this function yourself
  int top = 0;
  int bottom = bwt.size()-1;
  int ans = 0;
  while(top <= bottom)
  {
    if (!pattern.empty())
    {
      top = starts[pattern.back()] + occ_count_before[pattern.back()][top];
      bottom = starts[pattern.back()] + occ_count_before[pattern.back()][bottom+1] - 1;
      pattern.pop_back();
    }
    else
    {
      ans = bottom-top+1;
      break;
    }
  }
  return ans;
}
     

int main() {
  std::ios_base::sync_with_stdio(false);
  string bwt;
  cin >> bwt;
  int pattern_count;
  cin >> pattern_count;
  // Start of each character in the sorted list of characters of bwt,
  // see the description in the comment about function PreprocessBWT
  map<char, int> starts;
  // Occurrence counts for each character and each position in bwt,
  // see the description in the comment about function PreprocessBWT
  map<char, vector<int> > occ_count_before;
  // Preprocess the BWT once to get starts and occ_count_before.
  // For each pattern, we will then use these precomputed values and
  // spend only O(|pattern|) to find all occurrences of the pattern
  // in the text instead of O(|pattern| + |text|).
  PreprocessBWT(bwt, starts, occ_count_before);
  for (int pi = 0; pi < pattern_count; ++pi) {
    string pattern;
    cin >> pattern;
    int occ_count = CountOccurrences(pattern, bwt, starts, occ_count_before);
    printf("%d ", occ_count);
  }
  printf("\n");
  return 0;
}
