// Verdict: WA???
// #ifndef LOCALENV
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #endif

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// #define int ll
typedef pair<int, int> ii;
typedef vector<int> vi;

const int SIZE = 6;
vector<ii> d = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};

struct Coords {
    int x, y;
};

bool is_valid(int y, int x) { return !(y < 0 || x < 0 || y >= SIZE || x >= SIZE); }

struct Position {
    Coords b_king, w_king, w_rook, w_bishop;
    int moves_from_start;

    bool w_bishop_alive() const { return w_bishop.x != -1; }

    bool w_rook_alive() const { return w_rook.x != -1; }

    bool is_under_black_attack(int y, int x) const {
        for (const auto& [dy, dx] : d) {
            int ny = y + dy;
            int nx = x + dx;
            if (ny == b_king.y && nx == b_king.x) {
                return true;
            }
        }
        return false;
    }

    bool is_under_white_attack(int y, int x) const {
        for (const auto& [dy, dx] : d) {
            int ny = y + dy;
            int nx = x + dx;
            if (ny == w_king.y && nx == w_king.x) {
                return true;
            }
        }

        if (w_rook_alive()) {
            if (x != w_rook.x && w_rook.y == y) {
                return true;
            }
            if (x == w_rook.x && w_rook.y != y) {
                return true;
            }
        }

        if (w_bishop_alive()) {
            if (abs(w_bishop.x - x) == abs(w_bishop.y - y) && abs(w_bishop.x - x) != 0) {
                return true;
            }
        }

        return false;
    }

    bool is_mate() const {
        if (!is_under_white_attack(b_king.y, b_king.x)) {
            return false;
        }

        for (const auto& [dy, dx] : d) {
            int ny = b_king.y + dy;
            int nx = b_king.x + dx;
            if (is_valid(ny, nx) && !is_under_white_attack(ny, nx)) {
                return false;
            }
        }

        return true;
    }

    bool has_white_piece(int y, int x) const {
        return ((w_king.x == x && w_king.y == y) || (w_rook.x == x && w_rook.y == y) ||
                (w_bishop.x == x && w_bishop.y == y));
    }
};

void solve() {
    Position start_pos;
    start_pos.moves_from_start = 0;
    cin >> start_pos.w_king.x >> start_pos.w_king.y;
    cin >> start_pos.w_rook.x >> start_pos.w_rook.y;
    cin >> start_pos.w_bishop.x >> start_pos.w_bishop.y;
    cin >> start_pos.b_king.x >> start_pos.b_king.y;

    if (start_pos.is_mate()) {
        cout << 0 << endl;
        return;
    }

    queue<Position> q;
    q.push(start_pos);

    auto try_make_black_moves = [&q](Position p) {
        p.moves_from_start += 1;
        if (p.is_mate()) {
            cout << p.moves_from_start << endl;
            exit(0);
        }

        for (const auto& [dy, dx] : d) {
            int ny = p.b_king.y + dy;
            int nx = p.b_king.x + dx;
            if (is_valid(ny, nx) && !p.is_under_white_attack(ny, nx)) {
                auto new_p = p;
                new_p.b_king.y = ny;
                new_p.b_king.x = nx;
                if (new_p.w_bishop.x == nx && new_p.w_bishop.y == ny) {
                    new_p.w_bishop.x = -1;
                    new_p.w_bishop.y = -1;
                }
                if (new_p.w_rook.x == nx && new_p.w_rook.y == ny) {
                    new_p.w_rook.x = -1;
                    new_p.w_rook.y = -1;
                }

                if (new_p.w_rook_alive()) {
                    q.push(new_p);
                }
            }
        }
    };

    while (!q.empty()) {
        auto p = q.front();
        q.pop();

        // White king
        for (const auto& [dy, dx] : d) {
            int ny = p.w_king.y + dy;
            int nx = p.w_king.x + dx;
            if (is_valid(ny, nx) && !p.is_under_black_attack(ny, nx) &&
                !p.has_white_piece(ny, nx)) {
                auto new_p = p;
                new_p.w_king.y = ny;
                new_p.w_king.x = nx;
                try_make_black_moves(new_p);
            }
        }

        // White bishop
        if (p.w_bishop_alive()) {
            for (int i = -SIZE; i < SIZE; i++) {
                int ny = p.w_bishop.y + i;
                int nx = p.w_bishop.x + i;
                if (is_valid(ny, nx) && !p.has_white_piece(ny, nx)) {
                    auto new_p = p;
                    new_p.w_bishop.y = ny;
                    new_p.w_bishop.x = nx;
                    try_make_black_moves(new_p);
                }
            }
            for (int i = -SIZE; i < SIZE; i++) {
                int ny = p.w_bishop.y - i;
                int nx = p.w_bishop.x + i;
                if (is_valid(ny, nx) && !p.has_white_piece(ny, nx)) {
                    auto new_p = p;
                    new_p.w_bishop.y = ny;
                    new_p.w_bishop.x = nx;
                    try_make_black_moves(new_p);
                }
            }
        }

        // White rook
        if (p.w_rook_alive()) {
            for (int i = 0; i < SIZE; i++) {
                int ny = p.w_rook.y;
                int nx = i;
                if (is_valid(ny, nx) && !p.has_white_piece(ny, nx)) {
                    auto new_p = p;
                    new_p.w_rook.y = ny;
                    new_p.w_rook.x = nx;
                    try_make_black_moves(new_p);
                }
            }
            for (int i = 0; i < SIZE; i++) {
                int ny = i;
                int nx = p.w_rook.x;
                if (is_valid(ny, nx) && !p.has_white_piece(ny, nx)) {
                    auto new_p = p;
                    new_p.w_rook.y = ny;
                    new_p.w_rook.x = nx;
                    try_make_black_moves(new_p);
                }
            }
        }
    }

    cout << -1 << endl;
}

signed main() {
#ifdef LOCALENV
    freopen("/home/leksus/competitive-programming/IO/input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int TC = 1;
    // cin >> TC;
    while (TC--) {
        solve();
    }
    cout.flush();
}