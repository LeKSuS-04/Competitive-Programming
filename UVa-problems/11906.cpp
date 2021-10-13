/* UVa 11906 - Knight in War Grid */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3057
// Date: 2021-08-21 11:52:24
// Runtime: 0.020
// Verdict: AC

#include <stdio.h>

#include <iostream>
#include <utility>
#include <vector>
using namespace std;

const int WATER = -1;
const int UNVISITED = 0;
const int VISITED = 1;

int TC, r, c, m, n, w, x, y, even, odd, cntr = 0;
vector<vector<int>> field;
vector<pair<int, int>> moves;

void dfs(int x, int y) {
    field[x][y] = VISITED;
    int x2, y2, a = 0;
    for (int i = 0; i < moves.size(); i++) {
        x2 = x + moves[i].first, y2 = y + moves[i].second;
        if (0 <= x2 && x2 < r && 0 <= y2 && y2 < c) {
            if (field[x2][y2] == UNVISITED) dfs(x2, y2);
            if (field[x2][y2] != WATER) ++a;
        }
    }
    if (a % 2 == 0) ++even;
    else ++odd;
}

int main() {
    cin >> TC;
    while (TC--) {
        even = odd = 0;
        cin >> r >> c >> m >> n >> w;
        field.assign(r, vector<int>(c, UNVISITED));

        if (m == n && m == 0)
            moves = {};
        else if (m == n)
            moves = {{m, m}, {-m, m}, {m, -m}, {-m, -m}};
        else if (m == 0)
            moves = {{m, n},  {n, m}, {m, -n}, {-n, m}};
        else if (n == 0)
            moves = {{m, n},  {n, m},  {-m, n},  {n, -m}};
        else 
            moves = {{m, n},  {n, m},  {-m, n},  {n, -m},
                     {m, -n}, {-n, m}, {-m, -n}, {-n, -m}};

        while (w--) {
            cin >> x >> y;
            field[x][y] = WATER;
        }

        dfs(0, 0);
        printf("Case %d: %d %d\n", ++cntr, even, odd);
    }
}