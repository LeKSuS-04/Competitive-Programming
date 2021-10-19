/* Problem No. 170 */
// https://informatics.msk.ru/mod/statements/view.php?chapterid=170#1
// Date: 2021-10-18 07:54:03
// Max proccessor time: 0.021
// Max memory usage: 2031616
// Verdict: AC

#include <iostream>
using namespace std;

int main() {
    
}

#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = 1e9;

int main() {
    int n, src, dst;
    cin >> n >> src >> dst;
    --src; --dst;

    vector<vector<iii>> AL(n);
    int k; cin >> k;
    while (k--) {
        int u, v, a, b;
        cin >> u >> a >> v >> b;
        --u, --v;
        AL[u].push_back({v, {a, b}});
    }

    vector<int> min_t(n, INF);
    min_t[src] = 0;
    for (int i = 0; i < n; i++)
        for (int u = 0; u < n; u++)
            for (auto&& v : AL[u])
                if (min_t[u] <= v.second.first)
                    min_t[v.first] = min(min_t[v.first], v.second.second);

    if (min_t[dst] == INF) cout << "-1\n";
    else cout << min_t[dst] << endl;
}