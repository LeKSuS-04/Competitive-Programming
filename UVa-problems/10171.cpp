/* UVa 10171 - Meeting Prof. Miguel... */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=682&page=show_problem&problem=1112
// Date: 2021-09-01 16:19:20
// Runtime: 0.000
// Verdict: AC

#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;
const int SIZE = 26;

int main() {
    int n;
    while (cin >> n, n) {
        int w;
        char a, d, u, v, s, e;

        vector<vector<int>> AMY(SIZE, vector<int>(SIZE, INF));
        vector<vector<int>> AMM(SIZE, vector<int>(SIZE, INF));

        while (n--) {
            cin >> a >> d >> u >> v >> w;
            if (a == 'Y') {
                AMY[u - 'A'][v - 'A'] = w;
                if (d == 'B') AMY[v - 'A'][u - 'A'] = w;
            } else {
                AMM[u - 'A'][v - 'A'] = w;
                if (d == 'B') AMM[v - 'A'][u - 'A'] = w;
            }
        }

        cin >> s >> e;
        for (int i = 0; i < SIZE; i++) AMM[i][i] = AMY[i][i] = 0;    
        for (int k = 0; k < SIZE; k++)
            for (int i = 0; i < SIZE; i++)
                for (int j = 0; j < SIZE; j++) {
                    AMY[i][j] = min(AMY[i][j], AMY[i][k] + AMY[k][j]);
                    AMM[i][j] = min(AMM[i][j], AMM[i][k] + AMM[k][j]);
                }
        
        string points;
        int min = INF;
        for (int i = 0; i < SIZE; i++) {
            if (min > AMY[s - 'A'][i] + AMM[e - 'A'][i]) {
                min = AMY[s - 'A'][i] + AMM[e - 'A'][i];
                points = 'A' + i;
            } else if (min == AMY[s - 'A'][i] + AMM[e - 'A'][i]) {
                points = points + " " + char('A' + i);
            }
        }

        if (min == INF) cout << "You will never meet.\n";
        else cout << min << " " << points << endl;
    }
}