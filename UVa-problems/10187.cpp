/* UVa 10187 - From Dusk Till Dawn */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1128
// Date: 2021-09-09 17:43:32
// Runtime: 0.010
// Verdict: AC

#include <iostream>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> Iii;
typedef pair<ii, int> iiI;
const int INF = 1e9;

int main() {
    int TC, case_n = 0;
    cin >> TC;
    while (TC--) {
        int n;
        cin >> n;

        unordered_map<string, int> mapper;
        vector<vector<Iii>> AL;

        while (n--) {
            string u, v;
            int d, t;
            cin >> u >> v >> d >> t;

            d = (d + 6) % 24;
            int a = d + t;
            if (a <= 12) {
                if (mapper.find(u) == mapper.end()) 
                    mapper[u] = mapper.size(), AL.push_back(vector<Iii>());
                if (mapper.find(v) == mapper.end()) 
                    mapper[v] = mapper.size(), AL.push_back(vector<Iii>());

                AL[mapper[u]].push_back({mapper[v], {d, a}});
            }
        }

        string s, t;
        cin >> s >> t;
        if (mapper.find(s) == mapper.end()) 
            mapper[s] = mapper.size(), AL.push_back(vector<Iii>());
        if (mapper.find(t) == mapper.end()) 
            mapper[t] = mapper.size(), AL.push_back(vector<Iii>());


        priority_queue<iiI, vector<iiI>, greater<iiI>> pq;
        vector<ii> dist(mapper.size(), {INF, 12});
        pq.push({{0, 0}, mapper[s]});
        dist[mapper[s]] = {0, 0};

        while (!pq.empty()) {
            iiI u = pq.top(); pq.pop();

            if (u.first == dist[u.second]) {
                for (auto&& v : AL[u.second]) {
                    int w = 1;
                    if (u.first.second <= v.second.first) w = 0;

                    ii res = {u.first.first + w, v.second.second};
                    if (res < dist[v.first]) {
                        dist[v.first] = res;
                        pq.push({res, v.first});
                    }
                }
            }
        }

        cout << "Test Case " << ++case_n << ".\n";
        if (dist[mapper[t]].first == INF) cout << "There is no route Vladimir can take.\n";
        else cout << "Vladimir needs " << dist[mapper[t]].first << " litre(s) of blood.\n";
    }
}