/* Problem No. 983 */
// https://informatics.msk.ru/mod/statements/view.php?chapterid=983#1
// Date: 2021-10-17 18:09:53
// Max proccessor time: 0.048
// Max memory usage: 2039808
// Verdict: AC

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;

int n, k, sh, sc;
vector<vector<int>> AL;
vector<pair<int, pair<int, int>>> E;
unordered_map<ll, int> on_utov;
vector<int> indegree;
vector<pair<ll, int>> paths;

void utov_set(int u, int v, int value) { on_utov[u * 1e5 + v] = value; }
int utov_get(int u, int v) { 
    if (on_utov.find(u * 1e5 + v) != on_utov.end())
        return on_utov[u * 1e5 + v]; 
    else return 0;
}

void traverse(int u) {
    --indegree[u];

    int prev = 1;
    for (auto&& v : AL[u]) 
        if (indegree[v] == 0) 
            prev += utov_get(u, v);

    for (auto&& v : AL[u]) {
        if (indegree[v] != 0) {
            utov_set(u, v, n - prev);
            utov_set(v, u, prev);
            --indegree[v];

            if (indegree[v] == 1) traverse(v);
        }
    }
}

int main() {
    cin >> n >> k >> sh >> sc;
    AL.resize(n);
    indegree.assign(n, 0);

    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w; --u; --v;

        AL[u].push_back(v); ++indegree[u];
        AL[v].push_back(u); ++indegree[v];
        E.push_back({w, {u, v}});
    }

    for (int u = 0; u < n; u++) 
        if (indegree[u] == 1) 
            traverse(u);

    for (int i = 0; i < E.size(); i++) {
        ll w = E[i].first,
           u = E[i].second.first,
           v = E[i].second.second;

        paths.push_back({
            w * utov_get(u, v) * utov_get(v, u),
            i + 1
        });
    }
    stable_sort(paths.begin(), paths.end());

    for (int i = 0; i < k; i++)
        cout << paths[sh < sc ? paths.size() - i - 1 : i].second << endl;
}