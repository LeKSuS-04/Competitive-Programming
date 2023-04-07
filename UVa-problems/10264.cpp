/* UVa 10264 - The Most Potent Corner */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1205
// Date: 2021-07-28 11:11:21
// Run time: 0.000
// Verdict: AC

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;

    while (cin >> N) {
        vector<int> cube(1 << N, 0);
        vector<int> sums(1 << N, 0);

        for (int i = 0; i < (1 << N); i++) cin >> cube[i];

        for (int i = 0; i < (1 << N); i++)
            for (int j = 0; j < N; j++)
                sums[i] += cube[i ^ (1 << j)];

        int max_sum = 0, sum;
        for (int i = 0; i < (1 << N); i++)
            for (int j = 0; j < N; j++) {
                sum = sums[i] + sums[i ^ (1 << j)];
                if (sum > max_sum) max_sum = sum;
            }
        cout << max_sum << endl;
    }
}