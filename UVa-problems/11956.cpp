/* UVa 11956 - Brainfuck */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3107
// Date: 2021-02-05 14:53:11
// Run time: 0.200
// Verdict: AC

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string alphabet = "0123456789ABCDEF";
    int n, c = 1;
    cin >> n;

    while (n--) {
        string s;
        vector<int> bytes(100, 0);
        cin >> s;

        int point = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '>') point++;
            else if (s[i] == '<') point--;
            else if (s[i] == '+') bytes[point]++;
            else if (s[i] == '-') bytes[point]--;

            while (point < 0) point += bytes.size();
            while (point >= bytes.size()) point -= bytes.size();
            while (bytes[point] < 0) bytes[point] += 256;
            while (bytes[point] > 255) bytes[point] -= 256;
        }

        cout << "Case " << c << ": ";
        for (int i = 0; i < bytes.size(); i++) {
            if (i != 0) cout << " ";
            cout << alphabet[bytes[i] / 16] << alphabet[bytes[i] % 16];
        }
        cout << "\n";
        c++;
    }
}