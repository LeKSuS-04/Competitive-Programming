/* 4A. Watermelon */
// https://codeforces.com/problemset/problem/4/A
// Date: Jul/15/2022 19:23
// Run time:  30 ms
// Memory: 0 KB
// Verdict: AC

#include <iostream>
using namespace std;

int main() {
    int w;
    cin >> w;

    if (w % 2 == 0 && w > 2) cout << "YES\n";
    else cout << "NO\n"; 
}