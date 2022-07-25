/* 1706C. Qpwoeirut And The City */
// https://codeforces.com/contest/1706/problem/C
// Date: Jul/25/2022 13:08 	
// Run time: 343 ms
// Memory: 2400 KB
// Verdict: AC

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        int n;
        cin >> n;
        vector<int> h(n), r(n, -1);
        for (auto&& hi : h)
            cin >> hi;

        for (int i = 1; i < n - 1; i++)
            r[i] = max(0, max(h[i-1] - h[i] + 1, h[i+1] - h[i] + 1));

        
        if (n % 2 == 1) {
            long long sum = 0;
            for (int i = 1; i < n - 1; i += 2)
                sum += r[i];
            cout << sum << endl;
        } else {
            vector<long long> prefix(n, 0), suffix(n, 0);
            prefix[1] = prefix[2] = r[1];
            for (int i = 3; i < n - 1; i += 2)
                prefix[i] = prefix[i + 1] = prefix[i - 1] + r[i];

            suffix[n - 2] = suffix[n - 3] = r[n - 2];
            for (int i = n - 4; i > 0; i -= 2)
                suffix[i] = suffix[i - 1] = suffix[i + 1] + r[i];

            long long answ = prefix[n - 2];
            for (int i = 1; i < n - 1; i += 2)
                answ = min(answ, prefix[i] - r[i] + suffix[i + 1]);

            cout << answ << endl;
        }
    }
}
