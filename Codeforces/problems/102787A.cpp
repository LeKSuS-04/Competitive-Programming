/* 102787A. Shandom Ruffle */
// https://codeforces.com/gym/102787/problem/A
// Date: 2023-03-07 21:29:07
// Run time: 5100 ms
// Memory: 39240 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
mt19937 rng(seed);

class Treap {
   private:
    struct Node {
        int key, p, size = 1;
        shared_ptr<Node> l = nullptr, r = nullptr;

        Node(int key) : key(key), p(rng()) {}
    };
    using NodePtr = shared_ptr<Node>;
    using NodePair = pair<NodePtr, NodePtr>;

    NodePtr root = nullptr;

    static int size(NodePtr n) { return (n == nullptr ? 0 : n->size); }
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

    static void print(NodePtr t) {
        if (t == nullptr) return;
        print(t->l);
        cout << t->key << ' ';
        print(t->r);
    }

   public:
    void insert(int key) {
        NodePtr new_node = make_shared<Node>(key);
        auto [l, r] = split(root, key);
        root = merge(l, merge(new_node, r));
    }

    void shandom_ruffle(int a, int b) {
        if (b <= a) return;
        int length = min(size(root) - b + 1, b - a);
        NodePtr t1, ta, t2, tb, t3;
        tie(t1, ta) = split(root, a - 1);
        tie(ta, t2) = split(ta, length);
        tie(t2, tb) = split(t2, b - a - length);
        tie(tb, t3) = split(tb, length);
        root = merge(merge(t1, tb), merge(t2, merge(ta, t3)));
    }

    void print() {
        print(root);
        cout << endl;
    }
};

int main() {
#ifdef LOCALENV
    freopen("/home/leksus/Data/Competitive-Programming/IO/input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    Treap treap;
    for (int i = 1; i <= n; i++) {
        treap.insert(i);
    }

    while (n--) {
        int a, b;
        cin >> a >> b;
        treap.shandom_ruffle(a, b);
    }
    treap.print();
}