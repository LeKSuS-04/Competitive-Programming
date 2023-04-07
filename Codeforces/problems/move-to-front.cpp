/* A. В начало строя! */
// Date: 2023-03-07 19:49:10
// Run time: 1778 mc
// Memory: 7900 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
mt19937 rng(seed);

class Treap {
   private:
    struct Node {
        int key, p, size = 0;
        shared_ptr<Node> l = nullptr, r = nullptr;
        Node(int key) : key(key), p(rng()) {}
    };
    using NodePtr = shared_ptr<Node>;
    using NodePair = pair<NodePtr, NodePtr>;

    NodePtr root = nullptr;

    static int size(NodePtr n) { return n == nullptr ? 0 : n->size; }
    static void update(NodePtr n) { n->size = 1 + size(n->l) + size(n->r); }

    static NodePtr merge(NodePtr t1, NodePtr t2) {
        if (t1 == nullptr) return t2;
        if (t2 == nullptr) return t1;
        if (t1->p > t2->p) {
            t1->r = merge(t1->r, t2);
            update(t1);
            return t1;
        } else {
            t2->l = merge(t1, t2->l);
            update(t2);
            return t2;
        }
    }

    static NodePair split(NodePtr t, int key) {
        if (t == nullptr) return {nullptr, nullptr};
        if (size(t->l) + 1 <= key) {
            auto [fst, snd] = split(t->r, key - size(t->l) - 1);
            t->r = fst;
            update(t);
            return {t, snd};
        } else {
            auto [fst, snd] = split(t->l, key);
            t->l = snd;
            update(t);
            return {fst, t};
        }
    }

    static void print(NodePtr n) {
        if (n == nullptr) return;
        print(n->l);
        cout << n->key << ' ';
        print(n->r);
    }

   public:
    void insert(int key) {
        NodePtr new_node = make_shared<Node>(key);
        auto [l, r] = split(root, key);
        root = merge(l, merge(new_node, r));
    }

    void move_front(int l, int r) {
        NodePtr left, middle, right;
        tie(left, right) = split(root, r);
        tie(left, middle) = split(left, l - 1);
        root = merge(middle, merge(left, right));
    }

    void print() {
        print(root);
        cout << endl;
    }
};

int main() {
#ifdef LOCALENV
    freopen("/home/leksus/competitive-programming/IO/input.txt", "r", stdin);
#else
    freopen("movetofront.in", "r", stdin);
    freopen("movetofront.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    Treap treap;
    for (int i = 1; i <= n; i++) {
        treap.insert(i);
    }

    while (m--) {
        int l, r;
        cin >> l >> r;
        treap.move_front(l, r);
    }

    treap.print();
}