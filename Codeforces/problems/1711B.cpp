/* 1711B. Party */
// https://codeforces.com/contest/1711/problem/B
// Date: Jul/25/2022 10:31
// Run time: 358 ms
// Memory: 1600 KB
// Verdict: AC

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

typedef pair<int, int> ii;

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        int n, m;
        cin >> n >> m;
        vector<int> indegree(n), a(n);
        for (auto&& ai : a) 
            cin >> ai;

        vector<ii> p(m);
        for (auto&& pi : p) {
            cin >> pi.first >> pi.second;
            indegree[--pi.first]++, indegree[--pi.second]++;
        }

        if (m % 2 == 0) {
            cout << 0 << endl;
            continue;
        }

        long long mini = 1LL << 60;
        for (int i = 0; i < n; i++) {
            if (indegree[i] % 2 == 1)
                mini = min(mini, (long long) a[i]);
        }
        for (int i = 0; i < m; i++) {
            if ((indegree[p[i].first] + indegree[p[i].second]) % 2 == 0)
                mini = min(mini, (long long) a[p[i].first] + a[p[i].second]);
        }

        cout << mini << endl;
    }
}
