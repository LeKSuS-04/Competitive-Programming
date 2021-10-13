/* UVa 10338 - Mischievous Children */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1279
// Date: 2021-09-20 16:51:10
// Runtime: 0.040
// Verdict: Ac

#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
const int LETTERS = 26;
const int MAX = 21;
ll fact[MAX];


int main() {
    fact[0] = fact[1] = 1;
    for (int i = 2; i < MAX; i++) {
        fact[i] = fact[i - 1] * i;
    }

    vector<int> letters;
    int TC, case_n = 0;
    cin >> TC;
    while (TC--) {
        letters.assign(LETTERS, 0);
        string s;
        cin >> s;
        for (int i = 0; i < s.size(); i++) 
            ++letters[s[i] - 'A'];

        ll ans = fact[s.size()];
        for (int i = 0; i < LETTERS; i++)
            ans /= fact[letters[i]];

        cout << "Data set " << ++case_n << ": " << ans << endl;
    }
}