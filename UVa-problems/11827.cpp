/* UVa 11827 - Maximum GCD */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2927
// Date: 2021-09-20 16:56:23
// Runtime: 0.000
// Verdict: AC

#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
    int TC;
    string s;

    cin >> TC;
    getline(cin, s);
    while (TC--) {
        getline(cin, s);
        istringstream sin(s);

        vector<int> nums; int n;
        while (sin >> n) nums.push_back(n);

        int max_gcd = 1;
        for (int i = 0; i < nums.size(); i++)
            for (int j = i + 1; j < nums.size(); j++)
                max_gcd = max(max_gcd, gcd(nums[i], nums[j]));

        cout << max_gcd << endl;
    }
}