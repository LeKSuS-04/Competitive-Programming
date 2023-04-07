/* C. Sorting Substrings */
// https://codeforces.com/edu/course/2/lesson/2/5/practice/contest/269656/problem/C
// Date: 01.11.2021 19:11
// Runtime: 2121 ms
// Memory: 45100 KB
// Verdict: AC

#include <algorithm>
#include <cmath>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
typedef pair<int, int> ii;

class SuffixArray {
private:
    string T;
    int n;
    vector<int> SA, RA, tempSA, tempRA, c;

    void counting_sort(int k) {
        c.assign(max(n, 260), 0);
        for (int i = 0; i < n; i++)
            ++c[i + k < n ? RA[i + k] : 0];

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
        SpT.assign(ceil(log2(n)) + 1, vector<int>(n));

        for (int i = 0; i < n; i++) SA[i] = i, RA[i] = SpT[0][i] = T[i];
        for (int r = 0, k = 0; (1 << k) < n; k++) {
            counting_sort(1 << k);
            counting_sort(0);

            tempRA[SA[0]] = r = 0;
            for (int i = 1; i < n; i++) 
                tempRA[SA[i]] = (RA[SA[i]] == RA[SA[i - 1]] && RA[SA[i] + (1 << k)] == RA[SA[i - 1] + (1 << k)]) ? r : ++r;
            
            RA = SpT[k + 1] = tempRA;
        }
    }
public:
    SuffixArray(string s = "") { build(s); }
    vector<vector<int>> SpT;
    int size() { return n; }
};

SuffixArray SA;
bool cmp(ii x, ii y) {
    int l = min(x.second - x.first + 1, y.second - y.first + 1);

    int k = floor(log2(l));
    ii a = {SA.SpT[k][x.first], SA.SpT[k][x.first + l - (1 << k)]};
    ii b = {SA.SpT[k][y.first], SA.SpT[k][y.first + l - (1 << k)]};

    if (a != b) return a < b; 
    if (x.second - x.first != y.second - y.first) return x.second - x.first < y.second - y.first;
    return x < y;
}

int main() {
    string s;
    getline(cin, s);
    SA = SuffixArray(s);

    int n;
    cin >> n;
    vector<ii> pairs(n);
    for (auto&& p : pairs) {
        cin >> p.first >> p.second;
        p.first--, p.second--;
    }

    sort(pairs.begin(), pairs.end(), cmp);
    for (auto&& p : pairs) cout << p.first + 1 << " " << p.second + 1 << "\n";
}