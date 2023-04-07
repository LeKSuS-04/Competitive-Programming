/* G. Закупка */
// Date: 1 Sep 2022, 12:13:27 (+02:13)
// Run time: -
// Memory: -
// Verdict: WA

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, pair<int, char>> iic;

vector<char> days;
vector<iic> things;
void read_with(int day, char type) {
    int price; cin >> price;
    things.push_back({price, {day, type}});
}


int main() { 
    freopen("/home/leksus/Data/Competitive-Programming/IO/input.txt", "r", stdin);
    
    int n, na, nb, nc;
    cin >> n >> na >> nb >> nc;
    for (int i = 0; i < n; i++) read_with(i, 'a');
    for (int i = 0; i < n; i++) read_with(i, 'b');
    for (int i = 0; i < n; i++) read_with(i, 'c');

    days.assign(n, 0);
    sort(things.begin(), things.end());

    int sum = 0;
    for (auto thing : things) {
        int price = thing.first;
        int day = thing.second.first;
        char type = thing.second.second;

        if (type == 'a' && na > 0 && days[day] == 0) {
            days[day] = 1;
            na -= 1;
            sum += price;
        } else if (type == 'b' && nb > 0 && days[day] == 0) {
            days[day] = 1;
            nb -= 1;
            sum += price;
        } else if (type == 'c' && nc > 0 && days[day] == 0) {
            days[day] = 1;
            nc -= 1;
            sum += price;
        }
    }

    cout << sum << endl;
}