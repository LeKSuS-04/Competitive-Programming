/* UVa 11094 - Continents */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2035
// Date: 2021-08-21 16:07:56
// Runtime: 0.000
// Verdict: AC

#include <iostream>
#include <string>
#include <vector>
using namespace std;

const char CURRENT = 0;
const char CHECKEDLAND = 1;

char land, sea;
int n, m, x, y, mx;
vector<string> the_map;

int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1,  0, -1};
int floodfill(char from, char to, int r, int c) {
    if (r < 0 || r >= n) return 0;
    if (c < 0) c = m - 1;
    if (c >= m) c = 0;

    if (the_map[r][c] != from) return 0;
    the_map[r][c] = to;

    int ans = 1;
    for (int i = 0; i < 4; i++) {
        ans += floodfill(from, to, r + dr[i], c + dc[i]);
    }
    return ans;
}

int main() {
    while (cin >> n >> m) {
        the_map = vector<string>(n);
        for (int i = 0; i < n; i++) cin >> the_map[i];
        cin >> x >> y;

        land = the_map[x][y];
        floodfill(land, CURRENT, x, y);
        
        mx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (the_map[i][j] == land) {
                    mx = max(mx, floodfill(land, CHECKEDLAND, i, j));
                }
            }
        }
        cout << mx << endl;
    }
}