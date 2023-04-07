/* 309C. Memory for Arrays */
// https://codeforces.com/problemset/problem/309/C
// Date: 2022-10-19 21:33:08
// Run time: 498 ms
// Memory: 3928 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

const int MAXPOW = 30;  // 2**30 > 10**9
vector<int> bits_left(MAXPOW, 0);

void count_bits(int n) {
    int bit = 0;
    while (n != 0) {
        bits_left[bit] += n & 1;
        n >>= 1;
        ++bit;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifdef LOCALENV
    freopen("/home/leksus/Data/Competitive-Programming/IO/input.txt", "r",
            stdin);
#endif

    int n, m;
    cin >> n >> m;
    vector<int> b(m);
    for (int i = 0; i < n; i++) {
        int ai;
        cin >> ai;
        count_bits(ai);
    }
    for (auto&& bi : b) cin >> bi;

    sort(b.begin(), b.end());

    int arrays = 0;
    for (auto bit : b) {
        for (int i = bit; i < MAXPOW; i++) {
            if (bits_left[i]) {
                ++arrays;
                --bits_left[i];
                for (int j = bit; j < i; j++) {
                    ++bits_left[j];
                }
                break;
            }
        }
    }

    cout << arrays << endl;
}