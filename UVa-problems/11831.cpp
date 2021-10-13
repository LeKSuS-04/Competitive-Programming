/* UVa 11831 - Sticker Collector Robot */ 
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2931
// Date: 2021-08-13 17:42:40
// Run time: 0.020
// Verdict: AC

#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int main() {
    int n, m, s, c, dir;
    vector<vector<char>> arena;
    pair<int, int> pos;
    string actions;

    while (cin >> n >> m >> s, n | m | s) {
        arena.assign(n, vector<char>(m));

        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
            cin >> arena[i][j];
            if (arena[i][j] == 'N' ||
                arena[i][j] == 'S' ||
                arena[i][j] == 'L' || 
                arena[i][j] == 'O') pos = { i, j };

            if (arena[i][j] == 'N') dir = 0;
            else if (arena[i][j] == 'S') dir = 2;
            else if (arena[i][j] == 'L') dir = 1;
            else if (arena[i][j] == 'O') dir = 3;
        }

        cin >> actions;
        for (int i = c = 0; i < s; i++) {
            if (actions[i] == 'D') dir = (dir + 1) % 4;
            else if (actions[i] == 'E') dir = (dir + 3) % 4;
            else if (actions[i] == 'F') {
                arena[pos.first][pos.second] = '.';
                if (dir == 0 && pos.first > 0 && arena[pos.first - 1][pos.second] != '#') pos.first -= 1;
                else if (dir == 1 && pos.second < m - 1 && arena[pos.first][pos.second + 1] != '#') pos.second += 1;
                else if (dir == 2 && pos.first < n - 1 && arena[pos.first + 1][pos.second] != '#') pos.first += 1;
                else if (dir == 3 && pos.second > 0 && arena[pos.first][pos.second - 1] != '#') pos.second -= 1;

                if (arena[pos.first][pos.second] == '*') c++;
            }
        }

        cout << c << endl;
    }
}