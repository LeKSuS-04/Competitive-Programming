/* UVa 10182 - Bee Maja */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1123
// Date: 2021-09-11 13:48:32
// Runtime: 0.000
// Verdict: AC

#include <iostream>
#include <utility>
#include <vector>
using namespace std;

const int LAPS = 200;
const int SIZE = 120610;

vector<pair<int, int>> coords;
void generate_coords() {
    coords.assign(SIZE, {-1, -1});
    coords[1] = {0, 0};

    int x = 0, y = 0, idx = 1;
    for (int l = 0; l < LAPS; l++) {
        ++x;
        for (int i = 0; i <= l; i++) coords[++idx] = {--x, ++y};
        for (int i = 0; i <= l; i++) coords[++idx] = {--x,   y};
        for (int i = 0; i <= l; i++) coords[++idx] = {  x, --y};
        for (int i = 0; i <= l; i++) coords[++idx] = {++x, --y};
        for (int i = 0; i <= l; i++) coords[++idx] = {++x,   y};
        for (int i = 0; i <= l; i++) coords[++idx] = {  x, ++y};
    }
}

int main() {
    int n;
    generate_coords();
    while (cin >> n) 
        cout << coords[n].first << " " << coords[n].second << endl;
}