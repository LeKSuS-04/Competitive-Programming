/* 71A. Way To Long Words */
// https://codeforces.com/problemset/problem/71/A
// Date: Jul/25/2022 21:42 	
// Run time: 15 ms
// Memory: 0 KB
// Verdict: AC

#include <iostream>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n;
    while (n--) {
        cin >> s;
        if (s.size() <= 10) cout << s;
        else cout << s[0] << s.size() - 2 << s[s.size() - 1];
        cout << endl;
    }
}