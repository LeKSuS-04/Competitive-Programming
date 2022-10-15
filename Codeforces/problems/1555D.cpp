#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

ull f(ull x) {
    return x * (x - 1) / 2;
}

int main() {
    int n; string s;
    cin >> n >> s;

    int a = 0, b = 0;
    for (int i = 0; i < n; i++) {
        (s[i] == 'A' ? ++a : ++b);
    }
    if (a == 0 || b == 0) {
        cout << f(n) << endl;
        return 0;
    }


    s += 'L';
    ull sum = f(n);
    int cnt = 1;
    for (int i = 1; i <= n; i++) {
        if (s[i] != s[i - 1]) {
            sum -= (i == cnt || i == n ? cnt : 2*cnt - 1);
            cnt = 0;
        }
        ++cnt;
    }

    cout << sum + 1 << endl;
}