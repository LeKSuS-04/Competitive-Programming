/* UVa 259 - Software Allocation */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=195
// Date: 2021-09-06 14:33:00
// Runtime: 0.000
// Verdict: AC

#include <bitset>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INF = 1e9;
const int SIZE = 38;
const int S = 0;
const int T = 37;

int requests, max_flow, f;
bitset<SIZE> visited;
vector<vector<int>> AM;
vector<vector<int>> AL;
vector<int> p(SIZE, INF);

void augment(int v, int bottleneck) {
    if (v == S) { f += bottleneck; }
    else {
        augment(p[v], min(bottleneck, AM[p[v]][v]));
        AM[p[v]][v] -= f;
        AM[v][p[v]] += f;
    }
}

int main() {
    string line;
    while (getline(cin, line)) {
        AM.assign(SIZE, vector<int>(SIZE, 0));
        AL.assign(SIZE, vector<int>());

        for (int app = 1; app <= 26; app++) {
            AL[S].push_back(app);
            AM[S][app] = 0;
        }
        for (int pc = 27; pc  <= 36;  pc++) {
            AL[pc].push_back(T);
            AM[pc][T] = 1;
        }
        
        requests = 0;
        while (line != "") {
            int app = line[0] - 'A' + 1;
            int queries = line[1] - '0';
            string pcs = line.substr(3, line.size() - 4);

            AM[S][app] = queries;
            for (auto&& pc : pcs) {
                AL[app].push_back(pc - '0' + 27);
                AL[pc - '0' + 27].push_back(app);
                AM[app][pc - '0' + 27] = INF;
            }
            requests += queries;

            getline(cin, line);
        }

        max_flow = 0, f = 42;
        while (f != 0) {
            f = 0;

            queue<int> q;
            q.push(S);
            visited.reset();
            visited[S] = true;
            
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                if (u == T) break;

                for (auto&& v : AL[u]) {
                    if (!visited[v] && AM[u][v] > 0) {
                        visited[v] = true;
                        p[v] = u;
                        q.push(v);
                    }
                }
            }

            augment(T, INF);
            max_flow += f;
        }

        if (max_flow == requests) {
            for (int pc = 27; pc <= 36; pc++) {
                char letter = '_';
                for (int app = 1; app <= 26 && letter == '_'; app++) {
                    if (AM[pc][app] == 1) letter = app + 'A' - 1;
                }
                cout << letter;
            }
            cout << endl;
        } else {
            cout << "!\n";
        }
    }
}