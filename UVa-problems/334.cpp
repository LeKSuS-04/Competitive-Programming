/* UVa 334 - Identifying Concurrent Events */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=270
// Date: 2021-09-04 06:11:14
// Runtime: 0.000
// Verdict: AC

#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

const int SIZE = 250;

int main() {
    int n, case_n = 0;
    while (cin >> n, n) {
        int r, m;
        string u, v;

        unordered_map<string, int> mapper;
        unordered_map<int, string> rev_mapper;

        vector<vector<int>> AM(SIZE, vector<int>(SIZE, 0));
        while (n--) {
            cin >> r;

            cin >> u;
            if (mapper.find(u) == mapper.end()) {
                mapper[u] = mapper.size();
                rev_mapper[rev_mapper.size()] = u;
            }

            while (--r) {
                cin >> v;

                if (mapper.find(v) == mapper.end()) {
                    mapper[v] = mapper.size();
                    rev_mapper[rev_mapper.size()] = v;
                }

                AM[mapper[u]][mapper[v]] |= 1;
                u = v;
            }
        }

        cin >> m;
        while (m--) {
            cin >> u >> v;
            AM[mapper[u]][mapper[v]] |= 1;
        }

        for (int k = 0; k < mapper.size(); k++)
            for (int i = 0; i < mapper.size(); i++)
                for (int j = 0; j < mapper.size(); j++)
                    AM[i][j] |= (AM[i][k] & AM[k][j]);

        int concurrent = 0;
        vector<pair<int, int>> events;
        for (int i = 0; i < mapper.size(); i++)
            for (int j = i + 1; j < mapper.size(); j++) 
                if (!(AM[i][j] || AM[j][i])) {
                    ++concurrent;
                    if (events.size() < 2) events.push_back({i, j});
                }
        
        cout << "Case " << ++case_n << ", ";
        if (concurrent == 0) cout << "no concurrent events.\n";
        else {
            cout << concurrent << " concurrent events:\n";
            for (auto&& p : events) {
                cout << "(" << rev_mapper[p.first]
                     << "," << rev_mapper[p.second] << ") ";
            }
            cout << endl;
        } 
    }
}