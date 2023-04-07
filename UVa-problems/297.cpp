/* UVa 297 - Quadtrees */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=233
// Date: 2021-08-18 12:25:09
// Run time: 0.000
// Verdict: AC

#include <iostream>
#include <bitset>
using namespace std;

bitset<1024> pixels;

void enable(int l, int r) {
    for (int i = l; i < r; i++) pixels[i] = 1;
}

int handle_quadrant(const string& s, int q, int L, int R) {
    int qs = 1;
    if (s[q] == 'p') {
        qs += handle_quadrant(s, q + qs, L + 0 * (R - L)/4, L + 1 * (R - L)/4);
        qs += handle_quadrant(s, q + qs, L + 1 * (R - L)/4, L + 2 * (R - L)/4);
        qs += handle_quadrant(s, q + qs, L + 2 * (R - L)/4, L + 3 * (R - L)/4);
        qs += handle_quadrant(s, q + qs, L + 3 * (R - L)/4, L + 4 * (R - L)/4);
    } else if (s[q] == 'f') {
        enable(L, R);
    }
    return qs;
}

int main() {
    int TC, i, j;
    int step;
    string a, b;

    cin >> TC;
    while (TC--) {
        step = 1024;
        pixels.reset();

        cin >> a >> b;
        handle_quadrant(a, 0, 0, 1024), handle_quadrant(b, 0, 0, 1024);
        cout << "There are " << pixels.count() << " black pixels.\n";
    }
}