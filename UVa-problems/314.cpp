/* UVa 314 - Robot */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=677&page=show_problem&problem=250
// Date: 2021-08-29 09:03:34
// Runtime: 0.020
// Verdict: AC

#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

const int INF = 1e9;
const int BLOCKED = -1;
const int DIRCOUNT = 5;
const int dmv[]  = {1, 2, 3, 0, 0};
const int dor[] = {0, 0, 0, 1, 3};

int main() {
    int r, c;
    while (cin >> r >> c, r | c) {
        vector<vector<vector<int>>> grid(r + 1, vector<vector<int>>(c + 1, vector<int>(4, INF)));
        for (int i = 0; i <= r; i++) 
            for (int o = 0; o < 4; o++)
                grid[i][0][o] = grid[i][c][o] = BLOCKED;
        for (int i = 0; i <= c; i++) 
            for (int o = 0; o < 4; o++)
                grid[0][i][o] = grid[r][i][o] = BLOCKED;

        bool is_blocked;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> is_blocked;

                if (is_blocked) {
                    for (int a = i; a <= i + 1; a++)
                        for (int b = j; b <= j + 1; b++)
                            for (int o = 0; o < 4; o++)
                                grid[a][b][o] = BLOCKED;
                }
            }
        }

        int b1, b2, e1, e2;
        string o;
        cin >> b1 >> b2 >> e1 >> e2 >> o;
        if (b1 == e1 && b2 == e2) {
            cout << 0 << endl;
            continue;
        }
        tuple<int, int, int> start = {b1, b2, -1};
        tuple<int, int>        end = {e1, e2};
        if (o == "north")      get<2>(start) = 0;
        else if (o == "east")  get<2>(start) = 1;
        else if (o == "south") get<2>(start) = 2;
        else if (o == "west")  get<2>(start) = 3;

        queue<tuple<int, int, int>> q;
        q.push(start);
        grid[get<0>(start)][get<1>(start)][get<2>(start)] = 0;
        int steps = -1; bool found_way = false;
        while (!q.empty() && !found_way) {
            int ur, uc, uo;
            tie(ur, uc, uo) = q.front();
            q.pop();

            for (int i = 0; i < DIRCOUNT; i++) {
                int vr = ur, vc = uc, vo = (uo + dor[i]) % 4;

                bool bad_move = false;
                int& plane = (vo % 2 == 0 ? vr : vc);
                for (int j = 0; j < dmv[i] && !bad_move; j++) {
                    plane += (vo == 1 || vo == 2 ? 1 : -1);
                    if (0 > vr || vr > r ||
                        0 > vc || vc > c ||
                        grid[vr][vc][vo] == BLOCKED) bad_move = true;
                }

                if (!bad_move && grid[vr][vc][vo] == INF) {
                    grid[vr][vc][vo] = grid[ur][uc][uo] + 1;
                    if (vr == get<0>(end) && vc == get<1>(end)) {
                        found_way = true;
                        steps = grid[vr][vc][vo];
                    }
                    q.push({vr, vc, vo});
                }
            }
        }
        cout << steps << endl;
    }
}