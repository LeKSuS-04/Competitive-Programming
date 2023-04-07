/* UVa 481 - What Goes Up */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=422
// Date: 2021-07-31 18:27:47
// Run time: 0.220
// Verdict: AC

#include <iostream>
#include <utility>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int lim = -1e9;
int max_idx = 0;
vi nums, last, lsi;
vii sequence;

void calcLSI(int idx) {
    int i; for (i = sequence.size() - 1; i > -1 && sequence[i].first >= nums[idx]; i--);

    if (i != -1)  {
        if (i == sequence.size() - 1) sequence.push_back({ nums[idx], idx });
        else sequence[i + 1] = { nums[idx], idx };

        last[idx] = sequence[i].second;
    }
}

int main() {
    int n;
    while (cin >> n) nums.push_back(n);
    last.assign(nums.size(), -1);
    sequence.push_back({ lim, -1});

    for (int i = 0; i < nums.size(); i++) calcLSI(i);
    sequence.erase(sequence.begin());

    cout << sequence.size() << "\n-\n"; 
    for (int i = sequence.back().second; i != -1; i = last[i]) lsi.push_back(nums[i]);
    for (auto it = lsi.rbegin(); it != lsi.rend(); it++) cout << *it << endl;
}