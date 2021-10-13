/* UVa 11507 - Bender B. Rodríguez Problem */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2502
// Date: 2021-02-05 14:36:41
// Run time: 0.030
// Verdict: AC

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
using namespace std;

int main() {
    int l;

    while (cin >> l, l--) {
        string dir = "+x";

        while (l--) {
            string turn;
            cin >> turn;
            
            if (turn == "+y") {
                if (dir == "+x") dir = "+y";
                else if (dir == "-x") dir = "-y";
                else if (dir == "+y") dir = "-x";
                else if (dir == "-y") dir = "+x";
                else if (dir == "+z") dir = "+z";
                else if (dir == "-z") dir = "-z";
            }
            else if (turn == "-y") {
                if (dir == "+x") dir = "-y";
                else if (dir == "-x") dir = "+y";
                else if (dir == "+y") dir = "+x";
                else if (dir == "-y") dir = "-x";
                else if (dir == "+z") dir = "+z";
                else if (dir == "-z") dir = "-z";
            }
            else if (turn == "+z") {
                if (dir == "+x") dir = "+z";
                else if (dir == "-x") dir = "-z";
                else if (dir == "+y") dir = "+y";
                else if (dir == "-y") dir = "-y";
                else if (dir == "+z") dir = "-x";
                else if (dir == "-z") dir = "+x";
            }
            else if (turn == "-z") {
                if (dir == "+x") dir = "-z";
                else if (dir == "-x") dir = "+z";
                else if (dir == "+y") dir = "+y";
                else if (dir == "-y") dir = "-y";
                else if (dir == "+z") dir = "+x";
                else if (dir == "-z") dir = "-x";
            }
        }

        cout << dir << endl;
    }
}