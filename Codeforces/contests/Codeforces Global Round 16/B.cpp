/* B. MIN-MEX Cut */
// https://codeforces.com/contest/1566/problem/B
// Date: Sep/12/2021 17:48 (00:13:29)
// Runtime: 77 ms
// Memory: 3900 KB
// Verdict: AC

#include <iostream>
#include <string>
using namespace std;

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        string bin;
        cin >> bin;

        int s = (bin[0] == '0');
        for (int i = 1; i < bin.size(); i++) 
            if (bin[i] == '0' && bin[i - 1] == '1') s++;

        cout << min(s, 2) << endl;
    }
}