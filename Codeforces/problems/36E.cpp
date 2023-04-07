/* 36E.Two Paths */
// https://codeforces.com/problemset/problem/36/E
// Date: 2023-03-15 18:52:21
// Run time: 342 ms
// Memory: 6900 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto h1 = hash<T1>{}(p.first);
        auto h2 = hash<T2>{}(p.second);

        if (h1 == h2) return h1;
        return h1 ^ h2;
    }
};

int n = 0;
unordered_map<int, int> city_to_index;
unordered_map<pair<int, int>, unordered_set<int>, hash_pair> edge_to_indexes;
unordered_map<pair<int, int>, int, hash_pair> count_edges;
vector<unordered_set<int>> AL;
vector<bool> visited;
vector<int> SCC;
vector<int> indegree;
int scc_amount = 0;

void sort(int& u, int& v) {
    if (v < u) swap(u, v);
}

int get_city_index(int city) {
    auto it = city_to_index.find(city);
    if (it == city_to_index.end()) {
        city_to_index[city] = city_to_index.size();
    }
    return city_to_index[city];
}

void add_edge(int u, int v) {
    sort(u, v);
    while (u >= n || v >= n) {
        AL.push_back(unordered_set<int>());
        indegree.push_back(0);
        ++n;
    }
    AL[u].insert(v);
    AL[v].insert(u);
    ++indegree[u], ++indegree[v];
    auto it = count_edges.find({u, v});
    if (it == count_edges.end()) {
        count_edges[{u, v}] = 1;
    } else {
        ++count_edges[{u, v}];
    }
}

void remove_edge(int u, int v) {
    sort(u, v);
    --indegree[u], --indegree[v];
    --count_edges[{u, v}];
}

int edge_count(int u, int v) {
    sort(u, v);
    auto it = count_edges.find({u, v});
    if (it == count_edges.end()) return 0;
    return count_edges[{u, v}] > 0;
}

void dfs(int u, int scc_id) {
    SCC[u] = scc_id;
    for (auto&& v : AL[u]) {
        if (SCC[v] == -1) {
            dfs(v, scc_id);
        }
    }
}

void euler_path(list<int>& cycle, list<int>::iterator it, int u) {
    for (auto&& v : AL[u]) {
        if (edge_count(u, v) > 0) {
            remove_edge(u, v);
            euler_path(cycle, cycle.insert(it, u), v);
        }
    }
}

void euler_path_to_index_vector(const list<int>& euler, vector<int>& indexes) {
    indexes.clear();
    for (auto it = next(euler.begin()); it != euler.end(); it++) {
        int u = *prev(it);
        int v = *it;
        sort(u, v);
        auto idx_it = edge_to_indexes[{u, v}].begin();
        indexes.push_back(*idx_it);
        edge_to_indexes[{u, v}].erase(idx_it);
    }
}

int main() {
#ifdef LOCALENV
    freopen("/home/leksus/Data/Competitive-Programming/IO/input.txt", "r", stdin);
#else
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        int u = get_city_index(a);
        int v = get_city_index(b);
        sort(u, v);
        add_edge(u, v);
        edge_to_indexes[{u, v}].insert(i + 1);
    }

    vector<int> odd_indegrees;
    for (int i = 0; i < n; i++) {
        if (indegree[i] % 2 == 1) {
            odd_indegrees.push_back(i);
        }
    }

    SCC.assign(n, -1);
    for (int i = 0; i < n; i++) {
        if (SCC[i] == -1) dfs(i, scc_amount++);
    }

    if (scc_amount > 2) {
        cout << -1 << endl;
        return 0;
    }

    vector<int> indexes_first, indexes_second;
    if (odd_indegrees.size() == 4) {
        if (scc_amount == 2) {
            vector<vector<int>> odd_indegree_scc(2);
            for (auto&& v : odd_indegrees) {
                odd_indegree_scc[SCC[v]].push_back(v);
            }
            if (odd_indegree_scc[0].size() != 2 && odd_indegree_scc[1].size() != 2) {
                cout << -1 << endl;
                return 0;
            }
            odd_indegrees[0] = odd_indegree_scc[0][0];
            odd_indegrees[1] = odd_indegree_scc[1][0];
            odd_indegrees[2] = odd_indegree_scc[0][1];
            odd_indegrees[3] = odd_indegree_scc[1][1];
        }

        sort(odd_indegrees[0], odd_indegrees[1]);
        add_edge(odd_indegrees[0], odd_indegrees[1]);

        list<int> euler_united;
        euler_path(euler_united, euler_united.begin(), odd_indegrees[2]);
        euler_united.insert(euler_united.begin(), odd_indegrees[3]);

        list<int> euler_first, euler_second;
        euler_first.insert(euler_first.end(), *euler_united.begin());
        bool found_excess_pair = false;
        for (auto it = next(euler_united.begin()); it != euler_united.end(); it++) {
            int u = *prev(it);
            int v = *it;
            sort(u, v);
            if (u == odd_indegrees[0] && v == odd_indegrees[1] && !found_excess_pair) {
                found_excess_pair = true;
                euler_second.insert(euler_second.end(), *it);
            } else if (!found_excess_pair) {
                euler_first.insert(euler_first.end(), *it);
            } else {
                euler_second.insert(euler_second.end(), *it);
            }
        }

        euler_path_to_index_vector(euler_first, indexes_first);
        euler_path_to_index_vector(euler_second, indexes_second);
    } else if (odd_indegrees.size() == 2) {
        if (scc_amount == 1) {
            list<int> euler;
            euler_path(euler, euler.begin(), odd_indegrees[0]);
            euler.insert(euler.begin(), odd_indegrees[1]);

            euler_path_to_index_vector(euler, indexes_first);
            indexes_second.push_back(indexes_first.back());
            indexes_first.pop_back();
        } else {
            list<int> euler_from_odd_scc;
            euler_path(euler_from_odd_scc, euler_from_odd_scc.begin(), odd_indegrees[0]);
            euler_from_odd_scc.insert(euler_from_odd_scc.begin(), odd_indegrees[1]);

            euler_path_to_index_vector(euler_from_odd_scc, indexes_first);

            int odd_scc_id = SCC[odd_indegrees[0]];
            int first_from_even_scc;
            for (int i = 0; i < n; i++) {
                if (SCC[i] != odd_scc_id) {
                    first_from_even_scc = i;
                    break;
                }
            }

            list<int> euler_from_even_scc;
            euler_path(euler_from_even_scc, euler_from_even_scc.begin(), first_from_even_scc);
            euler_from_even_scc.insert(euler_from_even_scc.begin(), first_from_even_scc);

            euler_path_to_index_vector(euler_from_even_scc, indexes_second);
        }
    } else if (odd_indegrees.size() == 0) {
        if (scc_amount == 1) {
            list<int> euler;
            euler_path(euler, euler.begin(), 0);
            euler.insert(euler.begin(), 0);

            euler_path_to_index_vector(euler, indexes_first);
            indexes_second.push_back(indexes_first.back());
            indexes_first.pop_back();
        } else {
            int from_scc_0 = -1, from_scc_1 = -1;
            for (int i = 0; i < n; i++) {
                if (SCC[i] == 0) from_scc_0 = i;
                if (SCC[i] == 1) from_scc_1 = i;
                if (from_scc_0 != -1 && from_scc_1 != -1) break;
            }

            list<int> euler_from_0;
            euler_path(euler_from_0, euler_from_0.begin(), from_scc_0);
            euler_from_0.insert(euler_from_0.begin(), from_scc_0);
            euler_path_to_index_vector(euler_from_0, indexes_first);

            list<int> euler_from_1;
            euler_path(euler_from_1, euler_from_1.begin(), from_scc_1);
            euler_from_1.insert(euler_from_1.begin(), from_scc_1);
            euler_path_to_index_vector(euler_from_1, indexes_second);
        }
    }

    if (indexes_first.size() + indexes_second.size() == m && indexes_first.size() > 0 &&
        indexes_second.size() > 0) {
        cout << indexes_first.size() << endl;
        for (auto&& i : indexes_first) {
            cout << i << ' ';
        }
        cout << endl << indexes_second.size() << endl;
        for (auto&& i : indexes_second) {
            cout << i << ' ';
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }
}
