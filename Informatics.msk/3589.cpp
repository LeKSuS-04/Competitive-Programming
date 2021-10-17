/* Problem No. 3589 */
// https://informatics.msk.ru/mod/statements/view.php?chapterid=3589#1
// Date: 2021-10-17 14:46:45
// Max proccessor time: 0.003
// Max memory usage: 5607424
// Verdict: AC

#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
    vector<ll> fibs = {1, 2};
    for (int i = 0; i < 50; i++) 
        fibs.push_back(fibs[fibs.size() - 1] + fibs[fibs.size() - 2]);

    int n;
    cin >> n;

    bool leading_zero = true;
    for (int i = fibs.size() - 1; i >= 0; i--) {
        if (fibs[i] <= n) {
            n -= fibs[i];
            leading_zero = false;
            cout << '1';
        } else if (!leading_zero) cout << '0';
    }
    cout << endl;
}