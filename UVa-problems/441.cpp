/* UVa 441 - Lotto */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=382
// Date: 2021-07-29 15:37:51
// Run time: 0.000
// Verdict: AC

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, c = 0;
    vector<int> arr;

    while (cin >> n, n) {
        if (c++) cout << "\n";

        arr = vector<int>(n);
        for (int i = 0; i < n; i++) cin >> arr[i];

        for (int a = 0; a < n; a++)
            for (int b = a + 1; b < n; b++)
                for (int c = b + 1; c < n; c++)
                    for (int d = c + 1; d < n; d++)
                        for (int e = d + 1; e < n; e++)
                            for (int f = e + 1; f < n; f++)
                                cout << arr[a] << " " << arr[b] << " " << arr[c] << " " << arr[d] << " " << arr[e] << " " << arr[f] << "\n";
    }
}