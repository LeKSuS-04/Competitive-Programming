/* A - Number of Different Substrings */
// https://codeforces.com/edu/course/2/lesson/2/5/practice/contest/269656/problem/A
// Date: 01.11.2021 13:07
// Runtime: 187 ms
// Memory: 13000 KB
// Verdict: AC

#include <iostream>
#include <vector>
using namespace std;

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
        SA.resize(n), RA.resize(n), tempSA.resize(n), tempRA.resize(n);

        for (int i = 0; i < n; i++) SA[i] = i, RA[i] = T[i];
        for (int k = 1, r = 0; k < n; k <<= 1) {
            counting_sort(k);
            counting_sort(0);

            tempRA[SA[0]] = r = 0;
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
    vector<int> LCP;
    SuffixArray(string s) { build(s); }

    int operator[](int idx) { return SA[idx]; }
    int size() { return n; }
};

int main() {
    string s;
    cin >> s;
    SuffixArray SA(s);

    unsigned long long ans = 0;
    for (int i = 1; i < SA.size(); i++)
        ans += (s.size() - SA[i] - SA.LCP[i]);

    cout << ans << endl;
}