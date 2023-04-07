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
    vector<int> p, rank;

   public:
    UFDS(int n = 0) {
        rank.assign(n, 1);
        p.resize(n);
        for (int i = 0; i < n; i++) {
            p[i] = i;
        }
    }

    int find_set(int i) { return p[i] == i ? i : p[i] = find_set(p[i]); }
    bool same_set(int i, int j) { return i == -1 || j == -1 ? false : find_set(i) == find_set(j); }
    void merge(int i, int j) {
        if (!same_set(i, j)) {
            int x = find_set(i);
            int y = find_set(j);
            if (rank[x] > rank[y]) swap(x, y);
            if (rank[x] == rank[y]) ++rank[y];
            p[x] = y;
        }
    }
};

vector<int> ant;
vector<char> explored;
UFDS syn;

bool are_synonyms(int x, int y) { return syn.same_set(x, y); }

bool are_antonyms(int x, int y) {
    return ant[syn.find_set(x)] != -1 && syn.same_set(ant[syn.find_set(x)], y);
}

bool synonymize(int x, int y) {
    if (are_synonyms(x, y)) {
        return true;
    } else if (are_antonyms(x, y)) {
        return false;
    }

    bool success = true;
    int old_x = syn.find_set(x), old_y = syn.find_set(y);
    explored[old_x] = explored[old_y] = true;
    if (ant[syn.find_set(x)] != -1 && ant[syn.find_set(y)] != -1 &&
        !explored[ant[syn.find_set(x)]] && !explored[ant[syn.find_set(y)]]) {
        success &= synonymize(ant[syn.find_set(x)], ant[syn.find_set(y)]);
    }

    if (success) {
        int antonym = ant[syn.find_set(x)];
        syn.merge(x, y);
        if (antonym != -1 && !explored[antonym]) {
            ant[syn.find_set(x)] = syn.find_set(antonym);
            ant[syn.find_set(antonym)] = syn.find_set(x);
        }
    }

    explored[old_x] = explored[old_y] = false;
    return success;
}

bool antonymize(int x, int y) {
    if (are_antonyms(x, y)) {
        return true;
    } else if (are_synonyms(x, y)) {
        return false;
    }

    bool success = true;
    if (ant[syn.find_set(x)] != -1 && ant[syn.find_set(y)] == -1) {
        success &= synonymize(ant[syn.find_set(x)], y);
    } else if (ant[syn.find_set(x)] == -1 && ant[syn.find_set(y)] != -1) {
        success &= synonymize(ant[syn.find_set(y)], x);
    } else if (ant[syn.find_set(y)] != -1 && ant[syn.find_set(x)] != -1) {
        success &= synonymize(ant[syn.find_set(x)], y) && synonymize(ant[syn.find_set(y)], x);
    }

    if (success) {
        ant[syn.find_set(x)] = syn.find_set(y);
        ant[syn.find_set(y)] = syn.find_set(x);
    }
    return success;
}

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    unordered_map<string, int> mapper;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        mapper[s] = i;
    }

    ant.assign(n, -1);
    explored.assign(n, false);
    syn = UFDS(n);

    while (m--) {
        int t;
        string a, b;
        cin >> t >> a >> b;
        int x = mapper[a];
        int y = mapper[b];

        bool success = t == 1 ? synonymize(x, y) : antonymize(x, y);
        if (success) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    while (q--) {
        string a, b;
        cin >> a >> b;
        int x = mapper[a];
        int y = mapper[b];
        if (are_synonyms(x, y)) {
            cout << "1\n";
        } else if (are_antonyms(x, y)) {
            cout << "2\n";
        } else {
            cout << "3\n";
        }
    }
}

signed main() {
#ifdef LOCALENV
    freopen("/home/leksus/Data/Competitive-Programming/IO/input.txt", "r", stdin);
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