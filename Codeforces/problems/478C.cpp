/* 478C. Table Decorations */
// https://codeforces.com/problemset/problem/478/C
// Date: Sep/11/2022 12:37
// Run time: 15 ms 
// Memory: 0 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll r, g, b;
    cin >> r >> g >> b;

    ll x = min(r, min(g, b));
    ll z = max(r, max(g, b));
    ll y = r + g + b - x - z;

    ll l = y + z - 2*x;
    ll ly = min(l/2, y);
    ll lz = l - ly;
    
    ll m;
    if (ly * 2 <= lz) m = ly;
    else m = (ly + lz) / 3;

    cout << x + m << endl;
}