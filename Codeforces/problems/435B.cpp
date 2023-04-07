/* 478C. Table Decorations */
// https://codeforces.com/problemset/problem/478/C
// Date: Sep/11/2022 12:52
// Run time: 15 ms
// Memory: 0 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;


int main() {
    string a;
    int k;
    cin >> a >> k;

    int current_char = 0;
    while (k != 0 && current_char < a.size()) {
        int max_index = current_char;
        for (int i = current_char; i < min(current_char + k + 1, (int) a.size()); i++)
            if (a[i] > a[max_index]) max_index = i;
        
        for (int i = max_index; i > current_char; i--) {
            --k;
            swap(a[i], a[i - 1]);
        }
        ++current_char;
    }

    cout << a << endl;
}