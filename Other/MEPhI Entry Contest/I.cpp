/* I. Пакетный менеджер */
// Date: 1 Sep 2022, 11:15:27 (+01:15)
// Run time: 191ms
// Memory: 2.87Mb
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> mapper;
unordered_map<int, string> unmapper;
vector<vector<int>> AL;
vector<int> sorted;
vector<int> used;
vector<int> needs;

void toposort(int v) {
    if (used[v] == 1) return;
    used[v] = 1;

    for (int i = 0; i < AL[v].size(); i++) {
        toposort(AL[v][i]);
    }

    sorted.push_back(v);
}

void mark_children(int v) {
    if (needs[v] == 1) return;
    needs[v] = 1;

    for (int i = 0; i < AL[v].size(); i++)
        mark_children(AL[v][i]);
} 

int main() {
    int n;
    cin >> n;

    used.assign(n, 0);
    needs.assign(n, 0);
    AL.assign(n, vector<int>());
    sorted.clear(); 

    for (int i = 0; i < n; i++) {
        string s; int k, p, c;
        cin >> s >> k;
        if (mapper.find(s) == mapper.end()) {
            p = mapper.size();
            mapper[s] = p;
            unmapper[p] = s;
        } else {
            p = mapper[s];
        }

        while (k--) {
            cin >> s;
            if (mapper.find(s) == mapper.end()) {
                c = mapper.size();
                mapper[s] = c;
                unmapper[c] = s;
            } else {
                c = mapper[s];
            }

            AL[p].push_back(c);
        }
    }

    for (int v = 0; v < n; v++) {
        toposort(v);
    }

    string s;
    cin >> s;
    int req = mapper[s];

    mark_children(req);

    for (int i = 0; i < n; i++)
        if (needs[sorted[i]]) cout << unmapper[sorted[i]] << ' ';
    cout << endl;
}