/* 1433E. Two Round Dances */
// https://codeforces.com/problemset/problem/1433/E
// Date: 2022-10-28 10:36:03
// Run time: 15 ms
// Memory: 0 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

const int MAX = 25;
ull C[MAX][MAX];
ull P[MAX];

void init() {
    memset(C, 0, sizeof C);
    for (int i = 0; i < MAX; i++) C[0][i] = 1;
    for (int i = 1; i < MAX; i++)
        for (int j = 1; j < MAX; j++)
            C[i][j] = C[i][j-1] + C[i-1][j-1];

    P[0] = P[1] = 1;
    for (int i = 2; i < MAX; i++)
        P[i] = P[i-1] * i;
}

int main() {
    init();
    int n;
    cin >> n;
    cout << C[n/2][n] * P[n/2-1] * P[n/2-1] / 2 << endl;
}