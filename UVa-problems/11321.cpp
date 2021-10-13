/* UVa 11321 - Sort! Sort!! and Sort!!! */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2296
// Date: 2021-08-08 10:39:10
// Run time: 0.130
// Verdict: AC

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m;
bool cmp(int a, int b) {
    if (a % m != b % m) return a % m < b % m;
    else if (a % 2 == 0 && b % 2 == 0) return a < b;
    else if (a % 2 != 0 && b % 2 != 0) return a > b;
    else if (a % 2 == 0 && b % 2 != 0) return 0;
    else if (a % 2 != 0 && b % 2 == 0) return 1;
}

int main() {
    int n;
    vector<int> nums;

    while(cin >> n >> m, n | m) {
        nums.assign(n, 0);
        for (int i = 0; i < n; i++) cin >> nums[i];

        sort(nums.begin(), nums.end(), cmp);

        cout << n << " " << m << "\n";
        for (int i = 0; i < n; i++) cout << nums[i] << "\n";
    }
    cout << "0 0\n";
}