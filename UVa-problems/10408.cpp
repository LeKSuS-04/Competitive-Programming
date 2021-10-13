/* UVa 10408 - Farey sequences */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=703&page=show_problem&problem=1349
// Date: 2021-09-11 14:06:51
// Runtime: 0.210
// Verdict: AC

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

typedef pair<int, int> ii;

bool cmp(ii a, ii b) {
    return a.first * b.second < b.first * a.second;
}
int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a % b)); }

int main() {
    int n, k;
    while (cin >> n >> k) {
        vector<ii> f = {{1, 1}};

        for (int i = 1; i <= n; i++) 
            for (int j = i + 1; j <= n; j++) 
                if (gcd(i, j) == 1)
                    f.push_back({i, j});

        sort(f.begin(), f.end(), cmp);
        cout << f[k - 1].first << "/" << f[k - 1].second << endl;
    }
}