/* UVa 872 - Ordering */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=813
// Date: 2021-08-22 06:57:22
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
const int EXPLORED = 1;
const int VISITED = 2;

int TC, n;
bool has_cycle;
vector<int> used;
unordered_map<char, vector<char>> AL;
vector<char> alpha;
vector<char> sorted;
vector<int> indegree;

void find_cycle(char v) {
    if (used[v] == EXPLORED) {
        has_cycle = true;
        return;
    }

    used[v] = EXPLORED;
    for (int i = 0; i < AL[v].size(); i++) {
        find_cycle(AL[v][i]);
    }
    used[v] = VISITED;
}

void find_toposorts() {
    if (sorted.size() == AL.size()) {
        for (auto it = sorted.begin(); it != sorted.end(); it++) {
            if (it != sorted.begin()) cout << " ";
            cout << *it;
        }
        cout << endl;
    } else {
        char key;
        for (int i = 0; i < alpha.size(); i++) {
            key = alpha[i];
            if (indegree[key] == 0 && used[key] == UNVISITED) {
                for (int j = 0; j < AL[key].size(); j++) {
                    --indegree[AL[key][j]];
                }
                sorted.push_back(key);
                used[key] = VISITED;

                find_toposorts();

                for (int j = 0; j < AL[key].size(); j++) {
                    ++indegree[AL[key][j]];
                }
                sorted.pop_back();
                used[key] = UNVISITED;
            }
        }
    }
}

int main() {
    cin >> TC;

    char c;
    string in, s;
    while (TC--) {
        has_cycle = false;
        AL.clear();
        sorted.clear();
        alpha.clear();
        indegree.assign(256, -1);
        used.assign(256, UNVISITED);

        in = "";
        while (in.length() == 0) getline(cin, in);
        istringstream iss(in);
        while (iss >> c) {
            AL[c] = vector<char>();
            alpha.push_back(c);
            indegree[c] = 0;
        }

        in = "";
        while (in.length() == 0) getline(cin, in);
        iss = istringstream(in);
        while (iss >> s) {
            AL[s[0]].push_back(s[2]);
            ++indegree[s[2]];
        }

        for (int i = 0; i < alpha.size() && !has_cycle; i++) {
            if (used[alpha[i]] == false) find_cycle(alpha[i]);
        }
        if (has_cycle) {
            cout << "NO" << endl;
        } else {
            used.assign(256, UNVISITED);
            find_toposorts();
        }
        if (TC) cout << endl;
    }
}