/* Problem No. 112652 */
// https://informatics.msk.ru/mod/statements/view.php?chapterid=112652#1
// Date: 2021-10-18 08:07:52
// Max proccessor time: 0.004
// Max memory usage: 2031616
// Verdict: AC

#include <iostream>
using namespace std;

int main() {
    
}

#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> AM(n, vector<int>(n));
    for (auto&& r : AM)
        for (auto&& uv : r) {
            cin >> uv;
            if (uv == 0) uv = INF;
        }

    vector<vector<int>> p(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i != j) p[i][j] = i;

    for (int k = 0; k < n; k++)
        for (int u = 0; u < n; u++)
            for (int v = 0; v < n; v++)
                if (AM[u][k] + AM[k][v] < AM[u][v]) {
                    AM[u][v] = AM[u][k] + AM[k][v];
                    p[u][v] = p[k][v];
                }

    for (int u = 0; u < n; u++) {
        for (int v = u + 1; v < n; v++) {
            cout << "(" << u + 1 << "," << v + 1 << "): ";
            if (AM[u][v] == INF) cout << "0\n";
            else {
                vector<int> path;
                int a = u, b = v;
                while (a != b) {
                    path.push_back(b);
                    b = p[a][b];
                }
                path.push_back(b);
                for (int i = path.size() - 1; i >= 0; i--)
                    cout << path[i] + 1 << " ";

                cout << "(" << AM[u][v] << ")\n";
            }
        }
    }
}