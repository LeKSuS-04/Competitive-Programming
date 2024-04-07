// Verdict: TL(25)

// #ifndef LOCALENV
#pragma GCC optimize("O3")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #endif

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define int ll
typedef pair<int, int> ii;
typedef vector<int> vi;

struct Point {
    int x, y;

    int hor() const {
        return x;
    }
    int ver() const {
        return y;
    }
    int down_top_diag() const {
        return x - y;
    }
    int top_down_diag() const {
        return y + x;
    }
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
    bool operator!=(const Point& other) const {
        return !(operator==(other));
    }
};

struct hash_pair {
    size_t operator()(const Point& p) const {
        uintmax_t hash = std::hash<int>{}(p.x);
        hash <<= sizeof(uintmax_t) * 4;
        hash ^= std::hash<int>{}(p.y);
        return std::hash<uintmax_t>{}(hash);
    }
};

template<typename K>
using pset = unordered_set<K, hash_pair>;
template<typename K, typename V>
using pmap = unordered_map<K, V, hash_pair>; 

unordered_map<int, pset<Point>> hors, vers, down_tops, top_downs;
pset<Point> points;

bool remove_excess() {
    pset<Point> to_remove;
    for (auto p : points) {
        bool has_hors = hors[p.hor()].size() > 1;
        bool has_vers = vers[p.ver()].size() > 1;
        bool has_diag = down_tops[p.down_top_diag()].size() > 1 || top_downs[p.top_down_diag()].size() > 1;
        bool has_all = has_hors && has_vers && has_diag;
        if (!has_all) {
            to_remove.insert(p);
        }
    }

    for (auto p : to_remove) {
        hors[p.hor()].erase(p);
        vers[p.ver()].erase(p);
        top_downs[p.top_down_diag()].erase(p);
        down_tops[p.down_top_diag()].erase(p);
        points.erase(p);
    }

    return !to_remove.empty();
}

unordered_map<int, vector<Point>> s_hors, s_vers, s_down_tops;

void sort_all() {
    for (auto& [_, column] : s_hors) {
        sort(column.begin(), column.end(), [](const Point& a, const Point& b) {
            return a.y < b.y;
        });
    }
    for (auto& [_, line] : s_vers) {
        sort(line.begin(), line.end(), [](const Point& a, const Point& b) {
            return a.x < b.x;
        });
    }
    for (auto& [_, diag] : s_down_tops) {
        sort(diag.begin(), diag.end(), [](const Point& a, const Point& b) {
            return a.x < b.x;
        });
    }
}

template<typename T>
bool is_trimin(T a, T b, T c) {
    return a <= b && a <= c;
}

bool point_exists(int x, int y) {
    return points.find(Point{.x = x, .y = y}) != points.end();
}

int squares(const Point& p) {
    const auto& line = s_vers[p.ver()];
    const auto& column = s_hors[p.hor()];
    const auto& diag = s_down_tops[p.down_top_diag()];

    int l = lower_bound(line.begin(), line.end(), p, [](const auto& a, const auto& b) {
            return a.x < b.x;
    }) - line.begin();
    int c = lower_bound(column.begin(), column.end(), p, [](const auto& a, const auto& b) {
        return a.y < b.y;
    }) - column.begin();
    int d = lower_bound(diag.begin(), diag.end(), p, [](const auto& a, const auto& b) {
        return a.x < b.x;
    }) - diag.begin();

    int answ = 0;
    if (is_trimin(line.size() - l, column.size() - c, diag.size() - d)) {
        for (int i = l + 1; i < line.size(); i++) {
            const auto& q = line[i];
            int d = abs(p.x - q.x);
            if (point_exists(p.x, p.y + d) && point_exists(q.x, q.y + d)) {
                answ += 1;
            }
        }
    } else if (is_trimin(column.size() - c, line.size() - l, diag.size() - d)) {
        for (int i = c + 1; i < column.size(); i++) {
            const auto& q = column[i];
            int d = abs(p.y - q.y);
            if (point_exists(p.x + d, p.y) && point_exists(q.x + d, q.y)) {
                answ += 1;
            }
        }
    } else /* diag */ {
        for (int i = d + 1; i < diag.size(); i++) {
            const auto& q = diag[i];
            int d = abs(p.y - q.y);
            if (point_exists(p.x + d, p.y) && point_exists(p.x, p.y + d)) {
                answ += 1;
            }
        }
    }
    return answ;
}

void solve() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        Point p;
        cin >> p.x >> p.y;
        hors[p.hor()].insert(p);
        vers[p.ver()].insert(p);
        down_tops[p.down_top_diag()].insert(p);
        top_downs[p.top_down_diag()].insert(p);
        points.insert(p);
    }

    for (int i = 0; i < 5; i++)
        remove_excess();

    for (const auto& p : points) {
        s_hors[p.hor()].push_back(p);
        s_vers[p.ver()].push_back(p);
        s_down_tops[p.down_top_diag()].push_back(p);
    }
    sort_all();
    
    int answ = 0;
    for (const auto& p : points) {
        answ += squares(p);
    }
    cout << answ;
}

signed main() {
#ifdef LOCALENV
    freopen("/home/leksus/competitive-programming/IO/input.txt", "r", stdin);
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