#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> x(n);
    for (auto&& xi : x) cin >> xi;
    sort(x.begin(), x.end());
    
    int q, m;
    cin >> q;
    while (q--) {
        cin >> m;
        cout << lower_bound(x.begin(), x.end(), m + 1) - x.begin() << endl;
    }
}