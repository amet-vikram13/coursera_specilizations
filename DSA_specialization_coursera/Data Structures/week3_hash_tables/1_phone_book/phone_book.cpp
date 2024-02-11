#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using std::string;
using std::vector;
using std::cin;
using std::unordered_map;

enum QueryType { add, del, find};

struct Query {
    string name;
    int number;
    QueryType type;
};

vector<Query> read_queries() {
    int n; string inp;
    cin >> n;
    vector<Query> queries(n);
    for (int i = 0; i < n; ++i) {
        cin >> inp;
        if      (inp == "add")
        {
            queries[i].type = add;
            cin >> queries[i].number >> queries[i].name;
        }
        else if (inp == "del")
        {
            queries[i].type = del;
            cin >> queries[i].number;
        }
        else
        {
            queries[i].type = find;
            cin >> queries[i].number;
        }
    }
    return queries;
}

void write_responses(const vector<string>& result) {
    for (size_t i = 0; i < result.size(); ++i)
        std::cout << result[i] << "\n";
}

vector<string> process_queries(const vector<Query>& queries) {
    vector<string> result;
    unordered_map<int,string> pb;

    for(int i=0;i<queries.size();i++)
    {
        switch (queries[i].type)
        {
            case add :
                pb[queries[i].number] = queries[i].name;
                break;
            case del :
                if (pb.find(queries[i].number)!=pb.end()) pb.erase(queries[i].number);
                break;
            case find :
                if (pb.find(queries[i].number)==pb.end()) result.push_back("not found");
                else                                      result.push_back(pb[queries[i].number]);
                break;
        }
    }
    return result;
    
}

int main() {
    write_responses(process_queries(read_queries()));
    return 0;
}
