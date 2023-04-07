/* UVa 124 - Following Orders */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=3&page=show_problem&problem=60
// Date: 2021-08-22 07:52:38
// Runtime: 0.000
// Verdict: AC

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

const int UNVISITED = 0;
const int VISITED = 1;

vector<int> used;
unordered_map<char, vector<char>> AL;
vector<char> alpha;
vector<int> indegree;

vector<char> sorted;
void find_toposorts() {
    if (sorted.size() == alpha.size()) {
        for (int i = 0; i < sorted.size(); i++) {
            cout << sorted[i];
        }
        cout << endl;
    } else {
        char key;
        for (int i = 0; i < alpha.size(); i++) {
            key = alpha[i];
            if (indegree[key] == 0 && used[key] == UNVISITED) {
                for (int j = 0; j < AL[key].size(); j++) --indegree[AL[key][j]];
                used[key] = VISITED;
                sorted.push_back(key);

                find_toposorts();

                for (int j = 0; j < AL[key].size(); j++) ++indegree[AL[key][j]];
                used[key] = UNVISITED;
                sorted.pop_back();
            }
        }
    }
}

int main() {
    int c = 0;
    char u, v;
    string s;
    istringstream in;
    while (getline(cin, s)) {
        if (c++ != 0) cout << endl;

        AL.clear();
        alpha.clear();
        sorted.clear();
        indegree.assign(256, -1);
        used.assign(256, UNVISITED);

        in = istringstream(s);
        while (in >> v) {
            AL[v] = vector<char>();
            alpha.push_back(v);
            indegree[v] = 0;
        }

        sort(alpha.begin(), alpha.end());

        getline(cin, s);
        in = istringstream(s);
        while (in >> u >> v) {
            AL[u].push_back(v);
            ++indegree[v];
        }

        find_toposorts();
    }
}