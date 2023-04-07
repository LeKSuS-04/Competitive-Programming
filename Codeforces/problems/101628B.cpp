/* E - Battleship */
// https://codeforces.com/problemset/gymProblem/101628/B
// Date: 2023-02-28 20:08:47
// Run time: 685  ms
// Memory: 90052 KB
// Verdict: AC

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;

#define QUERY_PLACE '1'
#define QUERY_COUNT '2'
#define DIRECTION_LINE 'L'
#define DIRECTION_COLUMN 'C'

typedef long long ll;
typedef pair<int, int> ii;

struct Query {
    char query_type, direction;
    int x, y, size;
};

const hash<int> int_hasher;
namespace std {
template <>
struct hash<ii> {
    size_t operator()(const ii& p) const { return int_hasher(p.first) ^ int_hasher(p.second); }
};
};  // namespace std

template <class T1, class T2>
class Mapper {
   private:
    unordered_map<T1, T2> mapper;
    unordered_map<T2, T1> unmapper;

   public:
    void add(T1 value, T2 maps_to) {
        mapper[value] = maps_to;
        unmapper[maps_to] = value;
    }
    T2 map(T1 value) { return mapper[value]; }
    T1 unmap(T2 maps_to) { return unmapper[maps_to]; }
};

class FenwickTree {
   public:
    FenwickTree(int size) : ft(size + 1, 0) {}

    int count(int l, int r) { return count(r) - count(l - 1); }

    void set(int i) {
        for (; i < ft.size(); i += lsb(i)) {
            ft[i] += 1;
        }
    }

   private:
    vector<int> ft;

    int lsb(int n) { return n & -n; }

    int count(int r) {
        int res = 0;
        for (; r > 0; r -= lsb(r)) {
            res += ft[r];
        }
        return res;
    }
};

int main() {
#ifdef LOCALENV
    freopen("/home/leksus/competitive-programming/IO/input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q;
    cin >> n >> m >> q;
    vector<Query> queries(q);
    vector<ii> lines, columns;
    Mapper<ii, int> map_lines, map_columns;
    auto add_coordinate = [&](int x, int y) {
        lines.push_back({y, x});
        columns.push_back({x, y});
    };
    for (auto&& query : queries) {
        cin >> query.query_type >> query.direction >> query.x >> query.y >> query.size;
        if (query.query_type == QUERY_PLACE) {
            if (query.direction == DIRECTION_LINE) {
                for (int i = 0; i < query.size; i++) {
                    add_coordinate(query.x + i, query.y);
                }
            } else {
                for (int i = 0; i < query.size; i++) {
                    add_coordinate(query.x, query.y + i);
                }
            }
        } else {
            add_coordinate(query.x, query.y);
            if (query.direction == DIRECTION_LINE) {
                add_coordinate(query.x + query.size, query.y);
            } else {
                add_coordinate(query.x, query.y + query.size);
            }
        }
    }

    auto normalize = [](vector<ii>& vec, Mapper<ii, int>& mapper) {
        sort(vec.begin(), vec.end());
        auto vec_end = unique(vec.begin(), vec.end());
        vec.resize(distance(vec.begin(), vec_end));
        for (int i = 0; i < vec.size(); i++) {
            mapper.add(vec[i], i);
        }
    };
    normalize(lines, map_lines);
    normalize(columns, map_columns);

    FenwickTree xftree(lines.size()), yftree(columns.size());
    unordered_map<ii, bool> is_occupied;

    for (auto&& [qtype, direction, x, y, size] : queries) {
        if (qtype == QUERY_PLACE) {
            vector<ii> cells;
            if (direction == DIRECTION_LINE) {
                for (int i = 0; i < size; i++) {
                    cells.push_back({x + i, y});
                }
            } else {
                for (int i = 0; i < size; i++) {
                    cells.push_back({x, y + i});
                }
            }

            if (any_of(cells.begin(), cells.end(), [&is_occupied, n, m](ii cell) {
                    auto& [cx, cy] = cell;
                    return cx < 1 || cy < 1 || cx > m || cy > n ||
                           is_occupied.find(cell) != is_occupied.end();
                })) {
                cout << -1 << '\n';
            } else {
                for (auto&& [cx, cy] : cells) {
                    xftree.set(map_lines.map(make_pair(cy, cx)) + 1);
                    yftree.set(map_columns.map(make_pair(cx, cy)) + 1);
                    is_occupied[make_pair(cx, cy)] = true;
                }
            }
        } else {
            if (direction == DIRECTION_LINE) {
                auto begin = lower_bound(lines.begin(), lines.end(), make_pair(y, x));
                auto end =
                    prev(upper_bound(lines.begin(), lines.end(), make_pair(y, x + size - 1)));
                if (begin == lines.end() || begin->first != y) {
                    cout << 0 << '\n';
                } else {
                    cout << xftree.count(map_lines.map(*begin) + 1, map_lines.map(*end) + 1)
                         << '\n';
                }
            } else {
                auto begin = lower_bound(columns.begin(), columns.end(), make_pair(x, y));
                auto end =
                    prev(upper_bound(columns.begin(), columns.end(), make_pair(x, y + size - 1)));
                if (begin == columns.end() || begin->first != x) {
                    cout << 0 << '\n';
                } else {
                    cout << yftree.count(map_columns.map(*begin) + 1, map_columns.map(*end) + 1)
                         << '\n';
                }
            }
        }
    }
}