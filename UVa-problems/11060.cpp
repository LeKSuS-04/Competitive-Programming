/* UVa 11060 - Beverages */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2001
// Date: 2021-08-22 10:10:00
// Runtime: 0.000
// Verdict: AC

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int n, m, case_n = 0;
    string u, v;
    while (cin >> n) {
        vector<vector<int>> AL(n, vector<int>());
        vector<int> in_degree(n, 0);

        unordered_map<string, int> mapper;
        unordered_map<int, string> rev_mapper;

        for (int i = 0; i < n; i++) {
            cin >> v;
            mapper[v] = i;
            rev_mapper[i] = v;
        }

        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            AL[mapper[u]].push_back(mapper[v]);
            ++in_degree[mapper[v]];
        }

        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++) {
            if (in_degree[i] == 0) pq.push(i);
        }

        cout << "Case #" << ++case_n << ": Dilbert should drink beverages in this order:";
        while (!pq.empty()) {
            int a = pq.top(); pq.pop();
            cout << " " << rev_mapper[a];

            for (auto&& i : AL[a]) {
                --in_degree[i];
                if (in_degree[i] == 0) pq.push(i);
            }
        }
        cout << ".\n\n";
    }
}