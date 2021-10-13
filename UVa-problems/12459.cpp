/* UVa 12459 - Bees' ancestors */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3890
// Date: 2021-09-11 14:27:21
// Runtime: 0.000
// Verdict: AC

#include <iostream>
#include <utility>
#include <vector>
using namespace std;

const int MAXGEN = 90;

int main() {
    int n;

    vector<pair<long long, long long>> g = {{1, 0}};
    for (int i = 0; i < MAXGEN; i++) 
        g.push_back({g[i].second, g[i].first + g[i].second});

    while (cin >> n, n) 
        cout << g[n].first + g[n].second << endl;
}