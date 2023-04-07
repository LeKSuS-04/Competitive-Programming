/* A. Substring Search */
// https://codeforces.com/edu/course/2/lesson/2/3/practice/contest/269118/problem/A
// Date: 14.10.2021 21:29
// Runtime: 311 ms
// Memory: 6800 KB
// Verdict: AC

#include <iostream>
#include <vector>
using namespace std;

const int ASCII_MAX = 260;
string T;
int n;
vector<int> RA, tempRA;
vector<int> SA, tempSA;
vector<int> c;

void counting_sort(int k) {
    int i, sum = 0, maxi = max(n, ASCII_MAX);
    c.assign(maxi, 0);

    for (i = 0; i < n; i++)
        c[i + k < n ? RA[i + k] : 0]++;

    for (i = 0; i < maxi; i++) {
        int t = c[i];
        c[i] = sum;
        sum += t;
    }

    for (int i = 0; i < n; i++) {
        tempSA[c[SA[i] + k < n ? RA[SA[i] + k] : 0]++] = SA[i];
    }
    SA = tempSA;
}

void construct_SA() {
    SA.resize(n), tempSA.resize(n);
    RA.resize(n), tempRA.resize(n);

    int i, k, r;
    for (i = 0; i < n; i++) SA[i] = i, RA[i] = T[i];
    for (k = 1; k < n; k <<= 1) {
        counting_sort(k);
        counting_sort(0);

        tempRA[SA[0]] = r = 0;
        for (i = 1; i < n; i++)
            tempRA[SA[i]] = (RA[SA[i]] == RA[SA[i - 1]] && RA[SA[i] + k] == RA[SA[i - 1] + k]) ? r : ++r;
        RA = tempRA;
        if (RA[SA[n - 1]] == n - 1) break;
    }
}

bool bin_search(const string& s) {
    int l = -1, r = n, m;
    string sub;

    while (l < r - 1) {
        m = (l + r) / 2;
        sub = T.substr(SA[m], s.size());

        if (sub <= s) l = m;
        else r = m;
    }

    return T.substr(SA[l], s.size()) == s;
}

int main() {
    cin >> T; T += '$';
    n = T.size();
    construct_SA();

    int q;
    string s;
    cin >> q;
    while (q--) {
        cin >> s;
        if (bin_search(s)) cout << "Yes\n";
        else cout << "No\n";
    }
}