/* C - Book */
// https://codeforces.com/contest/1573/problem/C
// Date: Sep/18/2021 18:57 (01:22:56)
// Runtime: 248 ms
// Memory: 3800 KB
// Verdict: WA

#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

typedef pair<int, int> ii;

vector<vector<int>> AL;
vector<int> indegree;

int main() {    
    int TC;
    cin >> TC;
    while (TC--) {
        int n;
        cin >> n;

        AL.assign(n, vector<int>());
        indegree.assign(n, 0);

        for (int i = 0; i < n; i++) {
            int k, a;
            cin >> k;
            while (k--) {
                cin >> a;
                AL[a - 1].push_back(i);
                ++indegree[i];
            }
        }

        queue<ii> q;
        for (int i = 0; i < n; i++)
            if (indegree[i] == 0) {
                q.push({i, 0});
            }

        int times = 0;
        while (!q.empty()) {
            ii u = q.front(); q.pop();

            for (auto&& v : AL[u.first]) {
                if (--indegree[v] == 0) {
                    int w = (u.first < v ? 0 : 1);
                    times = max(times, u.second + w);
                    q.push({v, u.second + w});
                }
            }
        }
        bool has_unvisited  = false;
        for (int i = 0; i < n; i++)
            if (indegree[i] > 0) has_unvisited = true;

        cout << (has_unvisited ? -1 : 1 + times) << endl;
    }
}