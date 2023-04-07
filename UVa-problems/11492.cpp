/* UVa 11492 - Babel */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2487
// Date: 2021-08-31 06:24:19
// Runtime: 0.830
// Verdict: AC

#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

typedef pair<int, int> ii;
const int INF = 1e9;
const int START = 0;
const int END = 1;

int first(int i)  { return ((1 + i) << 1); }
int second(int i) { return ((1 + i) << 1) + 1; }

int main() {
    int m;
    while (cin >> m, m) {
        string o, v;
        cin >> o >> v;

        vector<string> word;
        vector<pair<string, string>> lang;

        string i1, i2, p;
        while (m--) {
            cin >> i1 >> i2 >> p;
            word.push_back(p);
            lang.push_back({i1, i2});
        }

        vector<vector<ii>> AL(2 + 2 * word.size());
        for (int from = 0; from < word.size(); from++) {
            for (int to = 0; to < word.size(); to++) {
                if (from != to && word[from][0] != word[to][0]) {
                    if (lang[from].first == lang[to].first) {
                        AL[first(from)].push_back({second(to), word[to].size()});
                    } else if (lang[from].first == lang[to].second) {
                        AL[first(from)].push_back({first(to), word[to].size()});
                    } else if (lang[from].second == lang[to].first) {
                        AL[second(from)].push_back({second(to), word[to].size()});
                    } else if (lang[from].second == lang[to].second) {
                        AL[second(from)].push_back({first(to), word[to].size()});
                    }
                }
            }

            if (lang[from].first == o) {
                AL[START].push_back({second(from), word[from].size()});
            } else if (lang[from].second == o) {
                AL[START].push_back({first(from), word[from].size()});
            }

            if (lang[from].first == v) {
                AL[first(from)].push_back({END, 0});
            } else if (lang[from].second == v) {
                AL[second(from)].push_back({END, 0});
            }
        }

        priority_queue<ii, vector<ii>, greater<ii>> pq;
        pq.push({0, START});
        vector<int> dist(AL.size(), INF);
        dist[START] = 0;
        while (!pq.empty()) {
            ii u = pq.top();
            pq.pop();

            if (u.first == dist[u.second]) {
                for (auto&& v : AL[u.second]) {
                    if (u.first + v.second < dist[v.first]) {
                        dist[v.first] = u.first + v.second;
                        pq.push({dist[v.first], v.first});
                    }
                }
            }
        }

        if (dist[END] == INF) cout << "impossivel\n";
        else cout << dist[END] << endl;
    }
}