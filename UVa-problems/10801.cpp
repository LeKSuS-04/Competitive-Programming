/* UVa 10801 - Lift Hopping */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=679&page=show_problem&problem=1742
// Date: 2021-08-30 15:13:00
// Runtime: 0.000
// Verdict: AC

#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

typedef pair<int, int> ii;

const int MAXFLOORS = 100;
const int INF = 1e9;
const int MINUTE = 60;

int main() {
    int n, k;
    while (cin >> n >> k) {
        vector<int> t(n);
        for (auto&& ti : t) cin >> ti;

        string line;
        getline(cin, line);
        vector<vector<ii>> AL(MAXFLOORS);
        for (int i = 0; i < n; i++) {
            vector<int> floors;
            int f;

            getline(cin, line);
            istringstream sin(line);
            while (sin >> f) floors.push_back(f);

            for (int j = 0; j < floors.size(); j++)
                for (int k = j + 1; k < floors.size(); k++) {
                    int d = abs(floors[k] - floors[j]);
                    AL[floors[j]].push_back({floors[k], t[i] * d});
                    AL[floors[k]].push_back({floors[j], t[i] * d});
                }
        }

        if (k == 0) {
            cout << 0 << endl;
            continue;
        }

        priority_queue<ii, vector<ii>, greater<ii>> pq;
        pq.push({0, 0});
        vector<int> dist(MAXFLOORS, INF);
        dist[0] = 0;

        while (!pq.empty()) {
            ii u = pq.top();
            pq.pop();

            if (dist[u.second] == u.first) {
                for (auto&& v : AL[u.second]) {
                    if (u.first + v.second + MINUTE < dist[v.first]) {
                        dist[v.first] = u.first + v.second + MINUTE;
                        pq.push({dist[v.first], v.first});
                    }
                }
            }
        }

        if (dist[k] == INF) cout << "IMPOSSIBLE\n";
        else cout << dist[k] - MINUTE << endl;
    }
}