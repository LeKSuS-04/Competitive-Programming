/* C - RANDOM */
// https://atcoder.jp/contests/abc279/tasks/abc279_c
// Date: 2022-11-26 15:10:51
// Run time: 94 ms
// Memory: 29404 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    unordered_map<string, int> a, b;
    vector<string> s(h), t(h);
    for (auto&& si : s) cin >> si;
    for (auto&& ti : t) cin >> ti;

    for (int i = 0; i < w; i++) {
	string line;
	for (int j = 0; j < h; j++) {
	    line += s[j][i];
	}
	if (a.find(line) == a.end()) a[line] = 1;
	else a[line] += 1;
    }
    for (int i = 0; i < w; i++) {
	string line;
	for (int j = 0; j < h; j++) {
	    line += t[j][i];
	}
	if (b.find(line) == b.end()) b[line] = 1;
	else b[line] += 1;
    }

    for (auto&& ai : a) {
	auto v = ai.first;
	auto c = ai.second;
	if (b.find(v) == b.end() || b[v] != c) {
	    cout << "No" << endl;
	    return 0;
	}
    }
    cout << "Yes" << endl;
}
