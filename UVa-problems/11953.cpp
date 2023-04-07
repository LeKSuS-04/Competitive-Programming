/* UVa 11953 - Battleships */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3104
// Date: 2021-08-21 16:23:06
// Runtime: 0.000
// Verdict: AC

#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
using namespace std;

const char EMPTY = '.';
const char ALIVE = 'x';
const char DESTROYED = '@';
const char CHECKED = 'C';

int TC, n, cntr = 0, c;
vector<string> grid;

int dr[] = {1, 0, 0, -1};
int dc[] = {0, 1, -1, 0};
int floodfill(int r, int c) {
    if (r < 0 || r >= n || c < 0 || c >= n) return 0;
    if (grid[r][c] != ALIVE && grid[r][c] != DESTROYED) return 0;

    int ans = (grid[r][c] == ALIVE);
    grid[r][c] = CHECKED;
    for (int i = 0; i < 4; i++) {
        ans |= floodfill(r + dr[i], c + dc[i]);
    }
    return ans;
}

int main() {
    cin >> TC;

    while (TC--) {
        cin >> n;
        grid = vector<string>(n);
        for (int i = 0; i < n; i++) cin >> grid[i];

        c = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == ALIVE || grid[i][j] == DESTROYED) 
                    c += floodfill(i, j);
            }
        }

        printf("Case %d: %d\n", ++cntr, c);
    }
}