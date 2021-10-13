/* UVa 10653 - Bombs! NO they are Mines!! */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=676&page=show_problem&problem=1594
// Date: 2021-08-29 06:21:37
// Runtime: 0.160
// Verdict: AC

#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

const int INF = 1e9;
const int MINE = 1;
const int DIRCOUNT = 4;
const int dr[] = {-1, 0, 0, 1};
const int dc[] = {0, 1, -1, 0};

int main() {
    int r, c;
    while (cin >> r >> c, r | c) {
        vector<vector<int>> grid(r, vector<int>(c, INF));

        int rows, i, n, j;
        cin >> rows;
        while (rows--) {
            cin >> i >> n;
            while (n--) {
                cin >> j;
                grid[i][j] = MINE;
            }
        }

        pair<int, int> start, end;
        cin >> start.first >> start.second >> end.first >> end.second;

        queue<pair<int, int>> q;
        q.push(start);
        grid[start.first][start.second] = 0;
        bool found_end = false;
        while (!q.empty() && !found_end) {
            pair<int, int> u = q.front();
            q.pop();

            for (int i = 0; i < DIRCOUNT; i++) {
                pair<int, int> v = {u.first + dr[i], u.second + dc[i]};
                if (0 <= v.first && v.first < r &&
                    0 <= v.second && v.second < c) {
                    if (grid[v.first][v.second] == INF) {
                        grid[v.first][v.second] = grid[u.first][u.second] + 1;
                        if (v == end) found_end = true;
                        q.push(v);
                    }
                }
            }
        }
        cout << grid[end.first][end.second] << endl;
    }
}