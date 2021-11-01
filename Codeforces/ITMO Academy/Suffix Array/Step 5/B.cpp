/* B - Longest Common Substring */
// https://codeforces.com/edu/course/2/lesson/2/5/practice/contest/269656/problem/B
// Date: 01.11.2021 13:42
// Runtime: 124 ms
// Memory: 7300 KB
// Verdict: AC

#include <iostream>
#include <vector>
using namespace std;

class SuffixArray {
private:
    string T;
    int n;
    vector<int> SA, tempSA, RA, tempRA, c;

    void counting_sort(int k) {
        c.assign(max(n, 260), 0);
        for (int i = 0; i < n; i++)
            c[i + k < n ? RA[i + k] : 0]++;

        for (int i = 0, sum = 0; i < c.size(); i++) {
            int t = c[i];
            c[i] = sum;
            sum += t;
        }

        for (int i = 0; i < n; i++)
            tempSA[c[SA[i] + k < n ? RA[SA[i] + k] : 0]++] = SA[i];
        SA = tempSA;
    }

    void build(string s) {
        T = s + char(0);
        n = T.size();

        SA.resize(n);
        tempSA.resize(n);
        RA.resize(n);
        tempRA.resize(n);

        for (int i = 0; i < n; i++) SA[i] = i, RA[i] = T[i];
        for (int r = 0, k = 1; k < n; k <<= 1) {
            counting_sort(k);
            counting_sort(0);

            RA[SA[0]] = r = 0;
            for (int i = 1; i < n; i++)
                tempRA[SA[i]] = (RA[SA[i]] == RA[SA[i - 1]] && RA[SA[i] + k] == RA[SA[i - 1] + k]) ? r : ++r;
            RA = tempRA;
            if (RA[SA[n - 1]] == n - 1) break;
        }

        LCP.resize(n);
        for (int i = 0, k = 0; i < n - 2; i++) {
            while (T[i + k] == T[SA[RA[i] - 1] + k]) ++k;
            LCP[RA[i]] = k;
            k = max(0, k - 1);
        }
    }
public:
    SuffixArray(string s) { build(s); }

    vector<int> LCP;
    int operator[](int idx) { return SA[idx]; }
    int size() { return n; }
};

string LCS(const string& s, const string& t) {
    SuffixArray SA(s + '#' + t);

    int maxlen = -1, maxidx = -1;
    for (int i = 1; i < SA.size(); i++) {
        if (SA.LCP[i] > maxlen) {
            if ((SA[i] > s.size() && SA[i - 1] < s.size()) ||
                (SA[i - 1] > s.size() && SA[i] < s.size())) {
                maxlen = SA.LCP[i];
                maxidx = min(SA[i], SA[i - 1]);
            }
        }
    }
    return s.substr(maxidx, maxlen);
}

int main() {
    string s, t;
    cin >> s >> t;
    cout << LCS(s, t);
}