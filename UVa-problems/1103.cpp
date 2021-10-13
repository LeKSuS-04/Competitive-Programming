/* UVa 1103 - Ancient Messages */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=667&page=show_problem&problem=3544
// Date: 2021-08-21 16:45:14
// Runtime: 0.030
// Verdict: AC

#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
using namespace std;

const int NOPIXEL = 0;
const int PIXEL = 1;
const int BG = 2;
const int FIGURE = 3;

int h, w, holes, c = 0;
string line;
vector<vector<int>> image;

vector<int> amount_with_holes;

void add_pixels(char hex, int i, int j) {
    int n;
    if ('0' <= hex && hex <= '9') n = (hex - '0');
    if ('a' <= hex && hex <= 'f') n = 10 + (hex - 'a');

    image[i][4 * j] = bool(n & 8);
    image[i][4 * j + 1] = bool(n & 4);
    image[i][4 * j + 2] = bool(n & 2);
    image[i][4 * j + 3] = bool(n & 1);
}

int dr[] = {0, 1, -1, 0};
int dc[] = {1, 0, 0, -1};
void bfs_floodfill(int r, int c) {
    queue<pair<int, int>> q;
    q.push({r, c});

    while (!q.empty()) {
        pair<int, int> v = q.front(); q.pop();
        if (v.first < 0 || v.first >= image.size() ||
            v.second < 0 || v.second >= image[v.first].size() ||
            image[v.first][v.second] != NOPIXEL)
            continue;

        image[v.first][v.second] = BG;
        for (int i = 0; i < 4; i++) q.push({v.first + dr[i], v.second + dc[i]});
    }
}

void bfs_floodfill_image(int r, int c) {
    queue<pair<int, int>> q;
    q.push({r, c});

    while (!q.empty()) {
        pair<int, int> v = q.front();
        q.pop();

        if (v.first < 0 || v.first >= image.size() || 
            v.second < 0 || v.second >= image[v.first].size())
            continue;
        if (image[v.first][v.second] != PIXEL) {
            if (image[v.first][v.second] == NOPIXEL) {
                bfs_floodfill(v.first, v.second);
                ++holes;
            }
            continue;
        }
        image[v.first][v.second] = FIGURE;

        for (int i = 0; i < 4; i++) {
            q.push({v.first + dr[i], v.second + dc[i]});
        }
    }
}

void find_hieroglyphs() {
    for (int i = 0; i < image.size(); i++) {
        bfs_floodfill(i, 0), bfs_floodfill(i, w * 4 - 1);
    }
    for (int i = 0; i < image[0].size(); i++) {
        bfs_floodfill(0, i), bfs_floodfill(h - 1, i);
    }

    for (int r = 0; r < image.size(); r++) {
        for (int c = 0; c < image[r].size(); c++) {
            if (image[r][c] == PIXEL) {
                holes = 0;
                bfs_floodfill_image(r, c);
                ++amount_with_holes[holes];
            }
        }
    }
}

int main() {
    while (cin >> h >> w, h | w) {
        amount_with_holes.assign(6, 0);
        image.assign(h, vector<int>(w * 4));

        for (int i = 0; i < h; i++) {
            cin >> line;
            for (int j = 0; j < line.size(); j++) add_pixels(line[j], i, j);
        }

        find_hieroglyphs();

        cout << "Case " << ++c << ": ";
        for (int i = 0; i < amount_with_holes[1]; i++) cout << 'A';
        for (int i = 0; i < amount_with_holes[5]; i++) cout << 'D';
        for (int i = 0; i < amount_with_holes[3]; i++) cout << 'J';
        for (int i = 0; i < amount_with_holes[2]; i++) cout << 'K';
        for (int i = 0; i < amount_with_holes[4]; i++) cout << 'S';
        for (int i = 0; i < amount_with_holes[0]; i++) cout << 'W';
        cout << endl;
    }
}