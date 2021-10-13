/* UVa 991 - Safe Salutations */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=716&page=show_problem&problem=932
// Date: 2021-09-19 05:21:09
// Runtime: 0.000
// Verdict: AC

#include <iostream>
using namespace std;

typedef long long ll;
const int MAX = 25;
ll fact[MAX];

int main() {
    fact[0] = fact[1] = 1;
    for (int i = 2; i < MAX; i++) 
        fact[i] = fact[i - 1] * i;


    int n, case_n = 0;
    while (cin >> n) {
        if (case_n++) cout << endl;
        cout << fact[2*n] / fact[n] / fact[n] / (n + 1) << endl;
    }
}