/* UVa 10699 - Count the factors */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1640
// Date: 2021-09-27 15:59:35
// Runtime: 0.250
// Verdict: AC

#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1e7+10;
vector<int> num_diff_pf;
void mod_sieve() {
    num_diff_pf.assign(MAX, 0);
    for (int i = 2; i < MAX; i++) 
        if (num_diff_pf[i] == 0) 
            for (int j = i; j < MAX; j += i) ++num_diff_pf[j];

}

int main() {
    mod_sieve();

    int n;
    while (cin >> n, n) 
        cout << n << " : " << num_diff_pf[n] << endl;
}