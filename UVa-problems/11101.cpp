/* UVa 11101 - Mall Mania */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=677&page=show_problem&problem=2042
// Date: 2021-08-29 10:57:51
// Runtime: 0.200
// Verdict: AC

#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

const int EMPTY = -1;
const int GOAL = -2;
const int MAXSIZE = 2010;
vector<vector<int>> grid;

vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main() {
    int p;
    while (cin >> p, p) {
        grid.assign(MAXSIZE, vector<int>(MAXSIZE, EMPTY));

        int a, s;
        queue<pair<int, int>> q;
        while (p--) {
            cin >> a >> s;
            grid[a][s] = 0;
            q.push({a, s});
        }
        cin >> p;
        while (p--) {
            cin >> a >> s;
            grid[a][s] = GOAL;
        }

        int distance;
        bool found_path = false;
        while (!q.empty() && !found_path) {
            pair<int, int> u = q.front();
            q.pop();

            for (auto&& d : dirs) {
                pair<int, int> v = {u.first + d.first, u.second + d.second};

                if (0 <= v.first && v.first < MAXSIZE &&
                    0 <= v.second && v.second < MAXSIZE) {
                        if (grid[v.first][v.second] == EMPTY) {
                            grid[v.first][v.second] = grid[u.first][u.second] + 1;
                            q.push(v);
                        } else if (grid[v.first][v.second] == GOAL) {
                            distance = grid[u.first][u.second] + 1;
                            found_path = true;
                        }
                    }
            }
        }

        cout << distance << endl;
    }
}