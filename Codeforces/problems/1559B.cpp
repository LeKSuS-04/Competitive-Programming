/* 1559B - Mocha and Red and Blue */
// https://codeforces.com/contest/1559/problem/B
// Date: Aug/23/2021 15:49
// Runtime: 31ms
// Memory: 3700 KB
// Verdict: AC

#include <iostream>
#include <string>
using namespace std;

string s;
void paint(int i, int j, bool next_red) {
    for (; i < j; i++, next_red = !next_red) s[i] = (next_red ? 'R' : 'B');
}

void paint(int i) {
    int j;
    char l, r = '#';

    if (i == 0) l = '#';
    else l = s[i - 1];

    for (j = i; j < s.size() && r == '#'; j++) {
        if (s[j] != '?') r = s[j--];
    }

    if (l == '#' && r == '#') paint(i, j, true);
    else if (l == '#') paint(i, j, ((j - i) % 2 == 0 ? r == 'R' : r == 'B'));
    else if (r == '#') paint(i, j, l == 'B');
    else {
        if (r == l && (j - i) % 2 == 1) paint(i, j, l == 'B'); 
        else if (r != l && (j - i) % 2 == 0) paint(i, j, l == 'B');
        else paint(i, j, true); 
    }
}

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        int n;
        cin >> n >> s;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '?') paint(i);
        }

        cout << s << endl; 
    }
}