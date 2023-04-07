/* 909E. Coprocessor */
// https://codeforces.com/problemset/problem/909/E
// Date: 2023-04-02 23:03:53
// Run time: 327 ms
// Memory: 6800 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pr;

vector<vector<int>> AL;
vector<int> indegree;
vector<int> visited, runs_on_sub;

int main() {
#ifdef LOCALENV
    freopen("/home/leksus/Data/Competitive-Programming/IO/input.txt", "r", stdin);
#endif

    int n, m;
    cin >> n >> m;

    AL.resize(n);
    indegree.assign(n, 0);
    runs_on_sub.assign(n, false);
    for (auto&& i : runs_on_sub) {
        cin >> i;
    }

    while (m--) {
        int u, v;
        cin >> u >> v;
        AL[v].push_back(u);
        ++indegree[u];
    }

    bool using_sub = false, incremented = false;
    priority_queue<pr, vector<pr>, less<pr>> sub_first;
    priority_queue<pr, vector<pr>, greater<pr>> main_first;

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            main_first.push({runs_on_sub[i], i});
        }
    }

    int c = 0;
    while (!(main_first.empty() && sub_first.empty())) {
        if (using_sub) {
            if (!incremented) {
                incremented = true;
                ++c;
            }

            auto [type, u] = sub_first.top();
            if (type == 0) {
                using_sub = !using_sub;
                while (!sub_first.empty()) {
                    auto p = sub_first.top();
                    sub_first.pop();
                    main_first.push(p);
                }
                continue;
            }
            sub_first.pop();

            for (auto&& v : AL[u]) {
                --indegree[v];
                if (indegree[v] == 0) {
                    sub_first.push({runs_on_sub[v], v});
                }
            }
        } else {
            auto [type, u] = main_first.top();
            if (type == 1) {
                incremented = false;
                using_sub = !using_sub;
                while (!main_first.empty()) {
                    auto p = main_first.top();
                    main_first.pop();
                    sub_first.push(p);
                }
                continue;
            }
            main_first.pop();

            for (auto&& v : AL[u]) {
                --indegree[v];
                if (indegree[v] == 0) {
                    main_first.push({runs_on_sub[v], v});
                }
            }
        }
    }

    cout << c << endl;
}