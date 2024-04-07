// Verdict: AC

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <string>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <random>
#include <chrono>
#include <memory>
#include <list>
#if __cplusplus >= 201703L
#include <variant>
#endif
#include <cassert>
#include <bitset>
#if __cplusplus > 201703L
#include <ranges>
#endif

using namespace std;

void fast_input() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

long long gcd(long long a, long long b) {
    while (b) {
        swap(a, b);
        b %= a;
    }
    return a;
}

long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }

bool is_prime(long long n) {
    if (n == 1) return false;
    for (long long i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

template<class K>
bool bmin(K& a, const K& b) { return b < a ? a = b, 1 : 0; }
template<class K>
bool bmax(K& a, const K& b) { return a < b ? a = b, 1 : 0; }

#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()

void solve() {
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    if (b<d) {
        swap(a, c);
        swap(b, d);
    }
    if (b<f) {
        swap(a, e);
        swap(b, f);
    }
    if (d<f) {
        swap(c, e);
        swap(f, d);
    }
    if (b==f) {
        cout << max(max(a, c), e) - min(min(a, c), e)+1;
        return;
    }
    if (b==d) {
        int t=abs(a-e);
        t=min(t, abs(c-e));
        if ((a<=e and e<=c) or (c<=e and e<=a)) t=0;
        cout << max(a, c)-min(a, c)+1+b-f+t;
        return;
    }
    if (f==d) {
        int t=abs(a-e);
        t=min(t, abs(c-a));
        if ((e<=a and a<=c) or (c<=a and a<=e)) t=0;
        cout << max(e, c)-min(e, c)+1+b-f+t;
        return;
    }
    int t=abs(a-c);
    t=min(t, abs(c-e));
    if ((a<=c and c<=e) or (e<=c and c<=a)) t=0;
    cout << abs(a-e)+1+b-f+t;
}

int32_t main() {
    //fast_input();
    long long te = 1;
    int k=1;
    //cin >> te;
    while (te--) {
        //cerr << "I AM TEST NUMBER " << k++ << endl;
        solve();
        cout << endl;
    }
}
