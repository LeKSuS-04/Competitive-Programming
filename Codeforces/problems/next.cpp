/* B. Следующий */
// Date: 2023-03-07 20:39:09
// Run time: 1278 ms
// Memory: 13200 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
mt19937 rng(seed);

class Treap {
   private:
    struct Node {
        int p, key;
        shared_ptr<Node> l = nullptr, r = nullptr;
        Node(int key) : key(key), p(rng()) {}
    };
    using NodePtr = shared_ptr<Node>;
    using NodePair = pair<NodePtr, NodePtr>;

    NodePtr root = nullptr;

    static NodePtr merge(NodePtr t1, NodePtr t2) {
        if (t1 == nullptr) return t2;
        if (t2 == nullptr) return t1;
        if (t1->p > t2->p) {
            t1->r = merge(t1->r, t2);
            return t1;
        } else {
            t2->l = merge(t1, t2->l);
            return t2;
        }
    }

    static NodePair split(NodePtr n, int key) {
        if (n == nullptr) return {nullptr, nullptr};
        if (n->key <= key) {
            auto [fst, snd] = split(n->r, key);
            n->r = fst;
            return {n, snd};
        } else {
            auto [fst, snd] = split(n->l, key);
            n->l = snd;
            return {fst, n};
        }
    }

    static int min_element(NodePtr n) {
        if (n->l == nullptr) return n->key;
        return min_element(n->l);
    }

   public:
    void insert(int key) {
        NodePtr new_node = make_shared<Node>(key);
        auto [l, r] = split(root, key);
        root = merge(l, merge(new_node, r));
    }

    int lower_bound(int key) {
        auto [l, r] = split(root, key - 1);
        int result = r == nullptr ? -1 : min_element(r);
        root = merge(l, r);
        return result;
    }
};

int main() {
#ifdef LOCALENV
    freopen("/home/leksus/Data/Competitive-Programming/IO/input.txt", "r", stdin);
#else
    freopen("next.in", "r", stdin);
    freopen("next.out", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, y = 0;
    cin >> n;

    Treap treap;
    char cmd, prevcmd = '+';
    int i;
    while (n--) {
        cin >> cmd >> i;
        if (cmd == '+') {
            if (prevcmd == '?') {
                treap.insert((i + y) % 1'000'000'000);
            } else {
                treap.insert(i);
            }
        } else {
            y = treap.lower_bound(i);
            cout << y << '\n';
        }
        prevcmd = cmd;
    }
    cout.flush();
}
