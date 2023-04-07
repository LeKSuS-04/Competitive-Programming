/* UVa 12250 - Language Detection */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3402
// Date: 2021-01-19 11:33:49
// Run time: 0.000
// Verdict: AC

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    size_t i = 1;

    while (getline(cin, s), s != "#") {
        if (s == "HELLO") cout << "Case " << i << ": ENGLISH\n";
        else if (s == "HOLA") cout << "Case " << i << ": SPANISH\n";
        else if (s == "HALLO") cout << "Case " << i << ": GERMAN\n";
        else if (s == "BONJOUR") cout << "Case " << i << ": FRENCH\n";
        else if (s == "CIAO") cout << "Case " << i << ": ITALIAN\n";
        else if (s == "ZDRAVSTVUJTE") cout << "Case " << i << ": RUSSIAN\n";
        else cout << "Case " << i << ": UNKNOWN\n";
        ++i;
    }
}