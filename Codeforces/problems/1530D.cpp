/* 1530D. Secret Santa */
// https://codeforces.com/problemset/problem/1530/D
// Date: 2021-09-06 18:46:40
// Runtime: 873ms
// Memory: 7840 KB
// Verdict: AC

#include <bitset>
#include <iostream>
#include <vector>
using namespace std;

const int MAXPEOPLE = 2 * 1e5 + 10;
const int NOBODY = -1;

int main() {
    bitset<MAXPEOPLE> used;
    vector<int> gifts;
    vector<int> gifters, recievers;
    vector<int> wishes;
    int n, satisfied = 0;

    int TC;
    cin >> TC;
    while (TC--) {
        cin >> n;
        used.reset();
        gifts.assign(n, NOBODY);
        wishes.resize(n);
        gifters.clear(); recievers.clear();
        satisfied = 0;

        for (int i = 0; i < n; i++) {
            cin >> wishes[i]; --wishes[i];
            if (!used[wishes[i]]) {
                satisfied++;
                used[wishes[i]] = true;
                gifts[i] = wishes[i] + 1;
            } else {
                gifters.push_back(i);
            }
        }
        for (int i = 0; i < n; i++) if (!used[i]) recievers.push_back(i);

        if (gifters.size() == 1 && gifters[0] == recievers[0]) 
            for (int i = 0; i < n; i++) 
                if (gifts[i] - 1 == wishes[gifters[0]]) {
                    gifts[gifters[0]] = gifts[i];
                    gifts[i] = NOBODY;
                    gifters.pop_back();
                    gifters.push_back(i);
                    break;
                }
            
        
        while (gifters.size() > 0) {
            int g = gifters.back(), r = recievers.back();
            gifters.pop_back(); recievers.pop_back();
            if (g == r || (gifters.size() == 1 && gifters[0] == recievers[0])) {
                int tmp = gifters.back();
                gifters.pop_back();
                gifters.push_back(g);
                g = tmp;
            }
            gifts[g] = r + 1;
        }

        cout << satisfied << endl;
        for (int i = 0; i < n; i++) 
            cout << gifts[i] << " ";
        cout << endl;
    }
}