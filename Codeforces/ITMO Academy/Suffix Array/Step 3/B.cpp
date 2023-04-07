/* B. Counting Substrings */
// https://codeforces.com/edu/course/2/lesson/2/3/practice/contest/269118/problem/B
// Date: 14.10.2021 22:32
// Runtime: 358 ms
// Memory: 6800 КБ
// Verdict: AC

#include <iostream>
#include <vector>
using namespace std;

const int ASCII_MAX = 260;
string T;
int n;
vector<int> SA, tempSA;
vector<int> RA, tempRA;
vector<int> c;

void counting_sort(int k) {
    int i, sum = 0, maxi = max(ASCII_MAX, n);
    c.assign(maxi, 0);

    for (i = 0; i < n; i++)
        c[i + k < n ? RA[i + k] : 0]++;

    for (i = 0; i < maxi; i++) {
        int t = c[i];
        c[i] = sum;
        sum += t;
    }

    for (i = 0; i < n; i++) 
        tempSA[c[SA[i] + k < n ? RA[SA[i] + k] : 0]++] = SA[i];
    SA = tempSA;
}

void construct_SA() {
    SA.resize(n), tempSA.resize(n);
    RA.resize(n), tempRA.resize(n);
    int i, k, r;

    for (i = 0; i < n; i++) RA[i] = T[i], SA[i] = i;
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

int bin_amount(const string& s) {
    int lbound, rbound, l, r, m;
    string sub;

    l = 0, r = n;
    while (l < r - 1) {
        m = (l + r)/2;
        sub = T.substr(SA[m], s.size());
        if (sub >= s) r = m;
        else l = m;
    }
    lbound = r;

    l = 0, r = n;
    while (l < r - 1) {
        m = (l + r)/2;
        sub = T.substr(SA[m], s.size());
        if (sub > s) r = m;
        else l = m;
    }
    rbound = l;

    return (rbound - lbound + 1);
}


int main() {
    cin >> T; T += char(0);
    n = T.size();
    construct_SA();

    int q;
    string s;
    cin >> q;
    while (q--) {
        cin >> s;
        cout << bin_amount(s) << endl;
    }
}