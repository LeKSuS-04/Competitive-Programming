/* UVa 10755 - Garbage Heap */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1696
// Date: 2021-07-29 12:20:15
// Run time: 0.370
// Verdict: AC

#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

vector<vector<vector<ll>>> heap;

int main() {
    int TC;
    cin >> TC;

    while(TC--) {
        int a, b, c;
        cin >> a >> b >> c;
        heap = vector<vector<vector<ll>>>(20, vector<vector<ll>>(20, vector<ll>(20, 0)));

        for (int i = 0; i < a; i++) for (int j = 0; j < b; j++) for (int k = 0; k < c; k++) {
            cin >> heap[i][j][k];

            if (i > 0) heap[i][j][k] += heap[i - 1][j][k];
            if (j > 0) heap[i][j][k] += heap[i][j - 1][k];
            if (k > 0) heap[i][j][k] += heap[i][j][k - 1];
            if (i > 0 && j > 0) heap[i][j][k] -= heap[i - 1][j - 1][k];
            if (i > 0 && k > 0) heap[i][j][k] -= heap[i - 1][j][k - 1];
            if (j > 0 && k > 0) heap[i][j][k] -= heap[i][j - 1][k - 1];
            if (i > 0 && j > 0 && k > 0) heap[i][j][k] += heap[i - 1][j - 1][k - 1];
        }

        ll s = 0, max_s = heap[a - 1][b - 1][c - 1];
        for (int i = 0; i < a; i++) for (int j = 0; j < b; j++) for (int k = 0; k < c; k++) 
            for (int d = i; d < a; d++) for (int e = j; e < b; e++) for (int f = k; f < c; f++) {
                s = heap[d][e][f];

                if (i > 0) s -= heap[i - 1][e][f];
                if (j > 0) s -= heap[d][j - 1][f];
                if (k > 0) s -= heap[d][e][k - 1];
                if (i > 0 && j > 0) s += heap[i - 1][j - 1][f];
                if (i > 0 && k > 0) s += heap[i - 1][e][k - 1];
                if (j > 0 && k > 0) s += heap[d][j - 1][k - 1];
                if (i > 0 && j > 0 && k > 0) s -= heap[i - 1][j - 1][k - 1];

                max_s = max(max_s, s);
            }
            
        cout << max_s << endl;
        if (TC != 0) cout << endl;
    }
}