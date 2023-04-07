/* 520B. Two Buttons */
// https://codeforces.com/problemset/problem/520/B/
// Date: 2023-03-14 21:19:07
// Run time: 15 ms
// Memory: 800 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

bool add_and_check_if_reached_goal(int prev, int number, queue<int>& q,
                                   unordered_map<int, int>& dist, int goal) {
    if (dist.find(number) == dist.end()) {
        if (0 <= number && number <= goal + 10'000) {
            q.push(number);
            dist[number] = dist[prev] + 1;
        }
        return number == goal;
    }
    return false;
}

int main() {
#ifdef LOCALENV
    freopen("/home/leksus/competitive-programming/IO/input.txt", "r", stdin);
#endif

    int n, m;
    cin >> n >> m;

    queue<int> q;
    unordered_map<int, int> dist;
    q.push(n);
    dist[n] = 0;

    while (true) {
        int t = q.front();
        q.pop();

        if (add_and_check_if_reached_goal(t, t - 1, q, dist, m)) break;
        if (add_and_check_if_reached_goal(t, t * 2, q, dist, m)) break;
    }

    cout << dist[m] << endl;
}