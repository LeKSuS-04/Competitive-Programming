// Verdict: AC
// #ifndef LOCALENV
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #endif

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// #define int ll
typedef pair<int, int> ii;
typedef vector<int> vi;

void solve() {
    int w, h;
    cin >> h >> w;
    vector<string> field(h);
    for (auto&& s : field) {
        cin >> s;
    }

    vector<vector<char>> visited(h, vector<char>(w, 0));
    int counter = 0;

    vector<ii> d = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
    auto go = [&](int sy, int sx) {
        queue<ii> q;
        q.push({sy, sx});
        visited[sy][sx] = 1;

        while (!q.empty()) {
            auto[y, x] = q.front();
            q.pop();

            for (const auto[dx, dy] : d) {
                int ny = dy + y;
                int nx = dx + x;

                if (ny < 0 || ny >= h || nx < 0 || nx >= w) {
                    continue;
                }

                if (visited[ny][nx] || field[ny][nx] != '#') {
                    continue;
                }

                visited[ny][nx] = 1;
                q.push({ny, nx});
            }
        }
    };

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (field[i][j] == '#' && !visited[i][j]) {
                go(i, j);
                counter += 1;
            }
        }
    }

    cout << counter << endl;
}

signed main() {
#ifdef LOCALENV
    freopen("/home/leksus/competitive-programming/IO/input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int TC = 1;
    // cin >> TC;
    while (TC--) {
        solve();
    }
    cout.flush();
}