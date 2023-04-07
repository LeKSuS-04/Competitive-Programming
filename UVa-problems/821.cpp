/* UVa 821 - Page Hopping */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=682&page=show_problem&problem=762
// Date: 2021-09-01 15:55:21
// Runtime: 0.080
// Verdict: AC

#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

const int INF = 1e9;
const int SIZE = 110;

int main() {
    int a, b, case_n = 0;
    while (cin >> a >> b, a | b) {
        vector<vector<int>> AM(SIZE, vector<int>(SIZE, INF));
        set<int> used;

        while (a | b) {
            AM[a][b] = 1;
            used.insert(a), used.insert(b);

            cin >> a >> b;
        }

        for (int k = 0; k < SIZE; k++) 
            for (int i = 0; i < SIZE; i++)
                for (int j = 0; j < SIZE; j++)
                    AM[i][j] = min(AM[i][j], AM[i][k] + AM[k][j]);
        
        double s = 0;
        for (auto&& i : used)
            for (auto&& j : used)  
                if (i != j) s += AM[i][j];

        printf("Case %d: average length between pages = %.3f clicks\n", ++case_n, s / (used.size() * (used.size() - 1)));
    }
}