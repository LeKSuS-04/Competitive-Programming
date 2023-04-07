/* UVa 11456 - Trainsorting */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=16&page=show_problem&problem=2451
// Date: 2021-08-06 18:23:46
// Run time: 0.010
// Verdict: AC

#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;

int n, max_length;
vi cars, lis, lds;

void ls(int idx) {
    for (int i = idx; i < n; i++) {
        if (cars[idx] < cars[i] && lis[i] >= lis[idx]) lis[idx] = lis[i] + 1;
        if (cars[idx] > cars[i] && lds[i] >= lds[idx]) lds[idx] = lds[i] + 1;
    }
    max_length = max(max_length, lis[idx] + lds[idx] - 1);
}

int main() {    
    int TC;
    cin >> TC;

    while(TC--) {
        cin >> n;
        cars.assign(n, 0);
        lis.assign(n, 1);
        lds.assign(n, 1);

        for (int i = 0; i < n; i++) cin >> cars[i];

        max_length = 0;
        for (int i = n - 1; i > -1 ; i--) ls(i);
        cout << max_length << endl;
    }
}