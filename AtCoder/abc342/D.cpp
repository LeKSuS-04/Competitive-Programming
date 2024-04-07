// #ifndef LOCALENV
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #endif

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define int ll
typedef pair<int, int> ii;
typedef vector<int> vi;

const int MAX = 2e5;

vector<int> primes;
bitset<MAX + 10> is_prime;

void sieve() {
    is_prime.set();
    is_prime[0] = is_prime[1] = false;
    primes.clear();

    for (ll i = 2; i < MAX; i++)
        if (is_prime[i]) {
            for (ll j = i * i; j < MAX; j += i) is_prime[j] = false;
            primes.push_back(i);
        }
}

struct Node {
    map<int, Node*> next;
    int count = 0;
};

int explore(Node* node) {
    int result = node->count * (node->count - 1) / 2;
    for (auto [k, v] : node->next) {
        if (v != nullptr) {
            result += explore(v);
        }
    }
    return result;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto&& ai : a) {
        cin >> ai;
    }

    int zeros = 0;
    Node root;
    for (int ai : a) {
        if (ai == 0) {
            zeros += 1;
            continue;
        }

        map<int, int> divs;
        int i = 0;
        while (ai > 1) {
            if (ai % primes[i] == 0) {
                divs[primes[i]] += 1;
                ai /= primes[i];
            } else {
                ++i;
            }
        }

        Node* local = &root;
        for (auto [d, count] : divs) {
            if (count % 2 == 1) {
                if (local->next[d] == nullptr) {
                    local->next[d] = new Node();
                }
                local = local->next[d];
            }
        }
        local->count += 1;
    }

    int result = zeros * (n - zeros) + zeros * (zeros - 1) / 2;
    result += explore(&root);
    cout << result << endl;
}

signed main() {
#ifdef LOCALENV
    freopen("/home/leksus/competitive-programming/IO/input.txt", "r", stdin);
#endif
    sieve();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int TC = 1;
    // cin >> TC;
    while (TC--) {
        solve();
    }
    cout.flush();
}