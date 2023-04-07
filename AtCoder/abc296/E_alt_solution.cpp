/* E - Transition Game */
// https://atcoder.jp/contests/abc296/tasks/abc296_e
// Date: 2023-04-01 20:28:11
// Run time: 106 ms
// Memory: 23764 KB
// Verdict: AC (After contest)

#include <bits/stdc++.h>
using namespace std;

const char UNVISITED = 0, VISITED = 1, EXPLORED = 2;

vector<vector<int>> AL;
vector<char> state;
vector<char> in_loop;

bool dfs(int u) {
    state[u] = VISITED;
    bool traversing_loop = false;
    for (auto&& v : AL[u]) {
        if (state[v] == UNVISITED) {
            traversing_loop |= dfs(v);
        } else if (state[v] == VISITED) {
            state[v] = EXPLORED;
            traversing_loop = true;
        }
    }

    in_loop[u] |= traversing_loop;
    traversing_loop &= (state[u] != EXPLORED);
    state[u] = EXPLORED;
    return traversing_loop;
}

int main() {
#ifdef LOCALENV
    freopen("/home/leksus/competitive-programming/IO/input.txt", "r", stdin);
#endif

    int n;
    cin >> n;

    AL.resize(n);
    state.assign(n, UNVISITED);
    in_loop.assign(n, false);

    for (int i = 0; i < n; i++) {
        int ai;
        cin >> ai;
        --ai;
        AL[i].push_back(ai);
    }

    for (int i = 0; i < n; i++) {
        if (state[i] == UNVISITED) {
            dfs(i);
        }
    }

    cout << count(in_loop.begin(), in_loop.end(), true) << endl;
}