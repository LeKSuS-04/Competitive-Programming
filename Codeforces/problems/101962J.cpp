#ifndef LOCALENV
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#endif

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

class UFDS {
   private:
    int n;
    unordered_map<int, int> p, rank;

    int get_rank(int i) {
        if (rank.find(i) == rank.end()) {
            return 0;
        }
        return rank.at(i);
    }

    void inc_rank(int i) {
        if (rank.find(i) == rank.end()) {
            rank[i] = 1;
        } else {
            ++rank[i];
        }
    }

   public:
    UFDS(int n) : n(n) {}

    int find_set(int i) { return p.find(i) == p.end() ? i : p[i] = find_set(p[i]); }
    bool are_same_set(int i, int j) { return find_set(i) == find_set(j); }
    void union_sets(int i, int j) {
        if (!are_same_set(i, j)) {
            int x = find_set(i);
            int y = find_set(j);
            if (get_rank(x) > get_rank(y)) swap(x, y);
            if (get_rank(x) == get_rank(y)) inc_rank(y);
            p[x] = y;
            --n;
        }
    }
    int count_sets() { return n; }

    void unify(UFDS& other) {
        if (other.count_sets() > this->count_sets()) {
            swap(other.p, p);
            swap(other.rank, rank);
            swap(other.n, n);
        }

        for (auto&& [i, j] : other.p) {
            union_sets(i, j);
        }
        other.nuke();
    }

    void nuke() {
        p.clear();
        rank.clear();
    }
};

int n, k;
vector<vector<int>> AL_workers;
vector<int> boss;
vector<char> visited;
vector<pair<int, int>> streets;
vector<UFDS> unions;
vector<int> answer;

void dfs(int u, UFDS& ufds) {
    visited[u] = true;
    if (streets[u].first + streets[u].second != 0) {
        unions[u].union_sets(streets[u].first, streets[u].second);
    }
    for (auto&& v : AL_workers[u]) {
        dfs(v, ufds);
        unions[u].unify(unions[v]);
    }
    answer[u] = unions[u].count_sets();
}

void solve() {
    cin >> n >> k;

    AL_workers.resize(n);
    boss.resize(n);
    visited.assign(n, false);
    for (int i = 1; i < n; i++) {
        int u;
        cin >> u;
        --u;
        AL_workers[u].push_back(i);
        boss[i] = u;
    }

    streets.resize(n);
    for (auto&& street : streets) {
        cin >> street.first >> street.second;
        --street.first;
        --street.second;
    }

    answer.resize(n);
    UFDS ufds(k);
    dfs(0, ufds);

    for (auto&& a : answer) {
        cout << a << '\n';
    }
}

signed main() {
#ifdef LOCALENV
    freopen("/home/leksus/Data/Competitive-Programming/IO/input.txt", "r", stdin);
    freopen("/home/leksus/Data/Competitive-Programming/IO/output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int TC = 1;
    // cin >> TC;
    while (TC--) {
        solve();
    }
    cout.flush();
}