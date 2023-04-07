/* UVa 10141 - Request for Proposal */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1082
// Date: 2021-02-05 13:53:50
// Run time: 0.000
// Verdict: AC

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main() {	
    int n, p, t = 1;
    string trash;

    while (cin >> n >> p, n || p) {
        cin.ignore();

        vector<string> req(n);
        int best_reqs;
        string best_name;
        float best_price;
        
        for (int i = 0; i < n; i++) getline(cin, req[i]);

        for (int i = 0; i < p; i++) {
            int r, c = 0;
            float d;
            string name;

            getline(cin, name);
            cin >> d >> r;
            cin.ignore();

            for (int j = 0; j < r; j++) {
                string temp;
                getline(cin, temp);

                // if (find(req.begin(), req.end(), temp) != req.end()) c++;   (Why though???)
                c++;
            }
            
            if (i == 0 || c > best_reqs || (c == best_reqs && d < best_price)) {
                best_reqs = c;
                best_name = name;
                best_price = d;
            } 
        }

        if (t != 1) cout << "\n";
        cout << "RFP #" << t++ << "\n" << best_name << "\n";
    }
}