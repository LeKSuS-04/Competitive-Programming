/* UVa 429 - Word Transformation */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=676&page=show_problem&problem=370
// Date: 2021-08-29 05:10:59
// Runtime: 0.000
// Verdict: AC

#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

const int INF = 1e9;

unordered_map<string, int> mapper;
unordered_map<int, string> rev_mapper;
vector<vector<int>> AL;

bool possible_step(string a, string b) {
    if (a.size() != b.size()) return false;
    int diff = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) diff++;
        if (diff > 1) return false;
    }
    return (diff == 1);
}

void add_word(string word) {
    mapper[word] = AL.size();
    rev_mapper[AL.size()] = word;

    AL.push_back(vector<int>());
    for (int i = 0; i < AL.size() - 1; i++) {
        if (possible_step(rev_mapper[i], word)) {
            AL[i].push_back(AL.size() - 1);
            AL[AL.size() - 1].push_back(i);
        }
    }
}

int count_steps(string from, string to) {
    int dest = mapper[to];

    queue<int> q;
    q.push(mapper[from]);
    vector<int> bfs_num(AL.size(), INF);
    bfs_num[mapper[from]] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto&& v : AL[u]) {
            if (bfs_num[v] == INF) {
                bfs_num[v] = bfs_num[u] + 1;
                if (v == dest) return bfs_num[v];
                q.push(v);
            }
        }
    }
    return -1;
}

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        mapper.clear();
        rev_mapper.clear();
        AL.clear();

        string in, u, v;

        while (cin >> u, u != "*") add_word(u);
        getline(cin, in);

        while (getline(cin, in), in != "") {
            istringstream sin(in);
            sin >> u >> v;
            cout << u << " " << v << " " << count_steps(u, v) << endl;
        }
        if (TC) cout << endl;
    }
}