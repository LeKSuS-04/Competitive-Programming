/* UVa 10507 - Waking up brain */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1448
// Date: 2021-08-17 15:30:48
// Run time: 0.000
// Verdict: AC

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<char> vc;
#define ASLEEP 0
#define JUST_WOKE_UP 1
#define AWAKE 2

vc alpha;
vector<vc> connections;
vi state;

void add_to_alphabet(char c) {
    if (alpha[alpha.size() - 1]) return;
    for (int i = 0; i < alpha.size(); i++) {
        if (alpha[i] == 0) alpha[i] = c;
        if (alpha[i] == c) return;
    }
}

int main() {
    int n, m, c, y;
    char a, b;
    string s;
    bool changed, all_awake;

    while(cin >> n) {
        alpha.assign(n, 0);
        connections.assign(256, vc());
        state.assign(256, ASLEEP);

        cin >> m >> s;
        state[s[0]] = state[s[1]] = state[s[2]] = AWAKE;
        add_to_alphabet(s[0]), add_to_alphabet(s[1]), add_to_alphabet(s[2]);
        while (m--) {
            scanf("\n%c%c", &a, &b);

            add_to_alphabet(a), add_to_alphabet(b);
            connections[a].push_back(b), connections[b].push_back(a);
        }

        changed = true;
        y = 0;
        while (changed) {
            changed = false;

            for (int i = 0; i < alpha.size(); i++) if (state[alpha[i]] == JUST_WOKE_UP) state[alpha[i]] = AWAKE, changed = true;
            for (int i = 0; i < alpha.size(); i++) {
                if (state[alpha[i]] == ASLEEP) {
                    for (int j = c = 0; j < connections[alpha[i]].size(); j++) if (state[connections[alpha[i]][j]] == AWAKE) ++c;

                    if (c >= 3) {
                        changed = true;
                        state[alpha[i]] = JUST_WOKE_UP;
                    }
                }
            }
            ++y;
        }
        
        all_awake = true;
        for (int i = 0; i < alpha.size(); i++) if (state[alpha[i]] != AWAKE) {
            all_awake = false;
            break;
        }

        if (all_awake) printf("WAKE UP IN, %d, YEARS\n", max(0, y - 2));
        else printf("THIS BRAIN NEVER WAKES UP\n");
    }
}