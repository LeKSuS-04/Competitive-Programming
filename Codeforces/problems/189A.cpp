/* 189A. Cut Ribbon */
// https://codeforces.com/problemset/problem/189/A
// Date: ?
// Run time: 15 ms
// Memory: 0 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

int trmax(int a, int b, int c) {
    return max(a, max(b, c));
}

int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    vector<int> v(n + 100, 0);
    if (a < v.size()) v[a] = 1;
    if (b < v.size()) v[b] = 1;
    if (c < v.size()) v[c] = 1;

    for (int i = 0; i < v.size(); i++) {
        if (i >= a && v[i-a] != 0 && i >= b && v[i-b] != 0 && i >= c && v[i-c] != 0) {
            v[i] = max(trmax(v[i-a], v[i-b], v[i-c]) + 1, v[i]);
        } else if (i >= a && v[i-a] != 0 && i >= b && v[i-b] != 0) {
            v[i] = max(max(v[i-a], v[i-b]) + 1, v[i]);
        } else if (i >= b && v[i-b] != 0 && i >= c && v[i-c] != 0) {
            v[i] = max(max(v[i-b], v[i-c]) + 1, v[i]);
        } else if (i >= a && v[i-a] != 0 && i >= c && v[i-c] != 0) {
            v[i] = max(max(v[i-a], v[i-c]) + 1, v[i]);
        } else if (i >= a && v[i-a] != 0) {
            v[i] = max(v[i-a] + 1, v[i]);
        } else if (i >= b && v[i-b] != 0) {
            v[i] = max(v[i-b] + 1, v[i]);
        } else if (i >= c && v[i-c] != 0) {
            v[i] = max(v[i-c] + 1, v[i]);
        }
    }

    cout << v[n] << endl;
}