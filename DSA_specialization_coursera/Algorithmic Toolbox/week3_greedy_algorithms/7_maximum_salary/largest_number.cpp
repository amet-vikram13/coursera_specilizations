#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 78 + 788 = 78788  < 788 + 78 = 78878 
// 93 + 933 = 93933  > 933 + 93 = 93393
// 123 + 1233 = 1231233 < 1233 + 123 = 1233123
// 1324 + 13244 = 132413244 < 13244 + 1324 = 132441324

// 1231 + 12311 = 123112311 > 12311 + 1231 = 123111231
// 9879 + 98799 = 987998799 < 98799 + 9879 = 987999879
// 4456744 + 44567444 = 445674444567444 > 445674444456744
// 771277 + 7712777 = 7712777712777 < 7712777771277


bool greaterPosition(string n1, string n2)
{
	return stoi(n1+n2)>stoi(n2+n1);
}


string largest_number(vector<string> a) 
{
	//write your code here
    sort(a.begin(),a.end(),greaterPosition);
    string ans="";
    for(int i=0;i<a.size();i++)
    	ans += a[i];
    return ans;
}

int main() 
{
	int n;
    std::cin >> n;
    vector <string> a(n);
    for (size_t i = 0; i < a.size(); i++) 
    {
    	std::cin >> a[i];
    }
    std::cout << largest_number(a);
}
