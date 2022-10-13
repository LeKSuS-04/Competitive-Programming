/* 534B. Covered Path */
// https://codeforces.com/problemset/problem/534/B
// Date: ?
// Run time: 15 ms
// Memory: 700 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAX_T = 110;
const int MAX_D = 15;
const int MAX_START_V = 110;
const int MAX_V = MAX_START_V + MAX_D * MAX_T;
int memo[MAX_T][MAX_V];
int v1, v2, t, d;


int find_answer(int t, int v) {
    if (memo[t][v] != -1) return memo[t][v];
    if (t == 1) return (v == v1 ? v1 : -INF);

    int max_speed = -INF;
    for (int i = max(0, v - d); i <= v + d; i++) {
        max_speed = max(max_speed, find_answer(t - 1, i));
    }
    return (memo[t][v] = max_speed + v);
}


int main() {
    cin >> v1 >> v2 >> t >> d;

    memset(memo, -1, sizeof memo);
    cout << find_answer(t, v2) << endl;
}