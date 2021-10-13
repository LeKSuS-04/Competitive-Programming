/* D. Up the Strip  */
// https://codeforces.com/contest/1561/problem/D1
// Date: Aug/24/2021 18:29 (00:54:05)
// Runtime: 6000 ms
// Memory: 29160 KB
// Verdict: TLE
 
#include <iostream>
#include <string.h>
using namespace std;
 
int n, m;
int memo[4000010];
 
int count(int x) {
    if (memo[x] != -1) return memo[x];
    if (x == 1) return 1;
 
    long long ans = 0;
    for (int y = 1; y <= x - 1; y++) ans = (ans + count(x - y)) % m;
    for (int z = 2; z <= x; z++) ans = (ans + count(x / z)) % m;
    return memo[x] = ans;
}
 
int main() {
    cin >> n >> m;
    memset(memo, -1, sizeof memo);
    cout << count(n);
}