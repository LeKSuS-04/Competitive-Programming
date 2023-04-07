/* E - Swap Places */
// https://atcoder.jp/contests/abc289/tasks/abc289_e
// Date: 2023-02-11 15:54:56
// Run time: 1090 ms
// Memory: 82560 KB	
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;

int n, m;
vector<char> color;
vector<vector<int>> AL;

ll dohash(ii p) { return p.first * 10'000 + p.second; }
ii unhash(ll n) { return { n / 10'000, n % 10'000 }; }

int main() {
#ifdef LOCALENV
    freopen("/home/leksus/competitive-programming/IO/input.txt", "r", stdin);
#endif

    int TC;
    cin >> TC;
    while (TC--) {
        cin >> n >> m;

        color.resize(n);
        for (auto&& ci : color) {
            cin >> ci;
        }

        AL.assign(n, vector<int>());
        while (m--) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            AL[u].push_back(v);
            AL[v].push_back(u);
        }

        queue<ii> q;
        unordered_map<ll, int> dist;
        q.push({0, n - 1});
        dist[dohash({0, n-1})] = 0;

        while (!q.empty()) {
            int au = q.front().first;
            int bu = q.front().second;
            q.pop();

            for (auto&& av : AL[au]) {
                for (auto&& bv : AL[bu]) {
                    if (color[av] == color[bv]) continue;
                    if (dist.find(dohash({av, bv})) != dist.end()) continue;

                    dist[dohash({av, bv})] = dist[dohash({au, bu})] + 1;
                    q.push({av, bv});
                }
            }
        }

        auto it = dist.find(dohash({n-1, 0}));
        if (it == dist.end()) {
            cout << -1;
        } else {
            cout << it->second;
        }
        cout << endl;
    }
}