#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (auto&& ai : a) {
	cin >> ai;
	--ai;
    }

    vector<int> mapped_before(n), after_mapper(n), after_unmapper(n);
    for (int i = 0; i < mapped_before.size(); i++) {
	mapped_before[i] = i;
	after_mapper[i] = i;
    }
    for (int i = 1; i < m; i++) {
	swap(after_mapper[a[i]], after_mapper[a[i]+1]);
    }
    for (int i = 0; i < n; i++) {
	after_unmapper[after_mapper[i]] = i;
    }
    cout << after_unmapper[0] + 1 << endl;

    for (int i = 1; i < m; i++) {	
	swap(mapped_before[a[i-1]], mapped_before[a[i-1]+1]);
	int k, l;

	k = after_unmapper[mapped_before[a[i-1]]];
	l = after_unmapper[mapped_before[a[i-1]+1]];
	swap(after_mapper[k], after_mapper[l]);
	after_unmapper[after_mapper[k]] = k;
	after_unmapper[after_mapper[l]] = l;
    
	k = after_unmapper[mapped_before[a[i]]];
	l = after_unmapper[mapped_before[a[i]+1]];
	swap(after_mapper[k], after_mapper[l]);
	after_unmapper[after_mapper[k]] = k;
	after_unmapper[after_mapper[l]] = l;

	cout << after_unmapper[0] + 1 << endl;
    }
}
