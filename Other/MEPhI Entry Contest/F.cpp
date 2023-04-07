/* F. Шахматы */
// Date: 1 Sep 2022, 11:57:40 (+01:57)
// Run time: 247ms
// Memory: 25.97Mb
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

int dohash(ii p) { return p.first * 10000 + p.second; }
ii unhash(int x) { return {x / 10000, x % 10000}; }

int n, k;
unordered_map<int, int> dist;
vector<ii> directions = {
    {2, 1}, {1, 2}, {-1, 2}, {2, -1},
    {-2, 1}, {1, -2}, {-1, -2}, {-2, -1},
};

int go(int from, ii d) {
    ii from_cell = unhash(from);
    int x = from_cell.first + d.first;
    int y = from_cell.second + d.second;
    return dohash({x, y});
}

bool is_valid(int from, ii d) {
    ii next = unhash(go(from, d));
    int x = next.first, y = next.second;
    return (
        dist.find(dohash({x, y})) == dist.end()
        && x >= 0 && x < n && y >= 0 && y < n
    );
}

int main() {
    cin >> n >> k;

    for (int i = 0; i < k; i++) {
        int x, y; cin >> x >> y;
        dist[dohash({x - 1, y - 1})] = 42;
    }

    ii s, f;
    cin >> s.first >> s.second >> f.first >> f.second;
    s.first -= 1; s.second -= 1; f.first -= 1; f.second -=1;
    int g = dohash(f);

    queue<int> q;
    q.push(dohash(s));
    dist[dohash(s)] = 0;
    while (q.size() != 0) {
        int u = q.front(); q.pop();
        if (u == g) {
            cout << dist[u] << endl;
            return 0;
        } else {
            for (auto d : directions) {
                if (is_valid(u, d)) {
                    int next = go(u, d);
                    dist[next] = dist[u] + 1;
                    q.push(next);
                }
            }
        }
    }
    cout << -1 << endl;
}