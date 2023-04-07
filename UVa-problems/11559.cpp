/* UVa 11559 - Event Planning */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2595
// Date: 2021-02-02 15:36:27
// Run time: 0.000
// Verdict: AC

#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int n, b, h, w;
    while (scanf("%d %d %d %d", &n, &b, &h, &w) != EOF) {
        int optimal = 1e6;

        for(int i = 0; i < h; i++) {
            int temp, price;
            cin >> price;

            for (int i = 0; i < w; i++) {
                cin >> temp;
                
                if (temp >= n && price * n < optimal) {
                    optimal = n * price;
                }
            }
        }

        if (optimal <= b) cout << optimal << endl;
        else cout << "stay home\n";
    }
}