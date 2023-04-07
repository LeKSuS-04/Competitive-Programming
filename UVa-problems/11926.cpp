/* UVa 11926 - Multitasking */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3077
// Date: 2021-07-28 13:09:56
// Run time: 0.190
// Verdict: AC

#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

int main() {
    int n, m;

    while (cin >> n >> m, n | m) {
        vii intervals;
        bool conflict = false;
        int start, end, interval;

        for (int i = 0; i < n; i++) {
            cin >> start >> end;
            intervals.push_back({ start, end });
        }
        for (int i = 0; i < m; i++) {
            cin >> start >> end >> interval;
            while (start < end) {
                intervals.push_back({ start, end });
                start += interval;
                end = min(end + interval, 1000000);
            }
        }

        sort(intervals.begin(), intervals.end());
        for (int i = 1; i < intervals.size() && !conflict; i++) 
            if (intervals[i].first < intervals[i - 1].second) conflict = true;

        if (conflict) cout << "CONFLICT\n";
        else cout << "NO CONFLICT\n";
    }
}