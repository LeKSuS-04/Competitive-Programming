/* UVa 11790 - Murcia's Skyline */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2890
// Date: 2021-08-02 15:20:17
// Run time: 0.080
// Verdict: AC

#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

ll max_lis, max_lds;
vll heights, lengths, lis, lds;

void calc(int idx) {
    lds[idx] = lis[idx] = lengths[idx];

    for (int i = 0; i < idx; i++) {
        if (heights[i] < heights[idx] && lis[i] + lengths[idx] > lis[idx]) {
            lis[idx] = lis[i] + lengths[idx];
        }
        if (heights[i] > heights[idx] && lds[i] + lengths[idx] > lds[idx]) {
            lds[idx] = lds[i] + lengths[idx];
        }
    }

    if (lis[idx] > lis[max_lis]) max_lis = idx;
    if (lds[idx] > lds[max_lds]) max_lds = idx;
}

int main() {
    int TC, n;
    cin >> TC;

    for (int c = 1; TC--; c++) {
        cin >> n;

        heights = vll(n, 0);
        lengths = vll(n, 0);
        lis = vll(n, 0);
        lds = vll(n, 0);

        for (int i = 0; i < n; i++) cin >> heights[i];
        for (int i = 0; i < n; i++) cin >> lengths[i];

        max_lis = max_lds = 0;
        for (int i = 0; i < n; i++) calc(i);

        if (lis[max_lis] >= lds[max_lds]) {
            cout << "Case " << c << ". Increasing (" << lis[max_lis] << "). Decreasing (" << lds[max_lds] << ").\n";
        } else {
            cout << "Case " << c << ". Decreasing (" << lds[max_lds] << "). Increasing (" << lis[max_lis] << ").\n";
        }
    }
}