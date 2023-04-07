/* 1037D. Valid BFS? */
// https://codeforces.com/problemset/problem/1037/D
// Date: 2023-03-15 12:08:23
// Run time: 919 ms
// Memory: 40900 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> AL;
vector<unordered_set<int>> direct_children;
deque<int> order;
vector<bool> visited;

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto&& v : AL[u]) {
            if (!visited[v]) {
                visited[v] = true;
                direct_children[u].insert(v);
                q.push(v);
            }
        }
    }
}

bool check_bfs(int start) {
    if (start != order.front()) {
        return false;
    }
    order.pop_front();

    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        unordered_set<int> level;
        for (int i = 0; i < direct_children[u].size(); i++) {
            level.insert(order.front());
            q.push(order.front());
            order.pop_front();
        }

        for (auto&& v : level) {
            if (direct_children[u].find(v) == direct_children[u].end()) {
                return false;
            }
        }
    }
    return true;
}

int main() {
#ifdef LOCALENV
    freopen("/home/leksus/Data/Competitive-Programming/IO/input.txt", "r", stdin);
#endif

    int n;
    cin >> n;

    AL.resize(n);
    direct_children.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        AL[x].push_back(y);
        AL[y].push_back(x);
    }

    order.resize(n);
    for (auto&& oi : order) {
        cin >> oi;
        --oi;
    }

    visited.assign(n, false);
    bfs(0);
    visited.assign(n, false);
    fill(visited.begin(), visited.end(), false);
    bool result = check_bfs(0);

    cout << (result ? "Yes" : "No") << endl;
}
