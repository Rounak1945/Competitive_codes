// Sereja and Brackets Codeforces

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int open, close, full;

    public:
    Node(int o, int c, int f){
        open = o, close = c, full = f;
    }
    Node(){
        open = 0, close = 0, full = 0;
    }
};

Node merge(Node a, Node b){
    Node c;
    c.full = a.full + b.full + min(a.open, b.close);
    c.open = a.open + b.open - min(a.open, b.close);
    c.close = a.close + b.close - min(a.open, b.close);
    return c;
}

class SGTree{
    vector<Node> seg;
    
    public:
    SGTree(int n){
        seg.resize(4 * n + 1);
    }

    void build(int ind, int low, int high, string &s){
        if(low == high) {
            seg[ind] = Node(s[low] == '(', s[low] == ')', 0);
            return;
        }

        int mid = (low + high) >> 1;

        build(2 * ind + 1, low, mid, s);
        build(2 * ind + 2, mid + 1, high, s);

        seg[ind] = merge(seg[2 * ind + 1], seg[2 * ind + 2]);

    }

    Node query(int ind, int low, int high, int l, int r){
        // no overlap
        // l r low high or low high l r
        if(r < low || high < l) return Node();

        // complete overlap
        // [l low high r]
        if(low >= l && high <= r) return seg[ind];

        // on overlap
        int mid = (low + high) >> 1;
        Node left = query(2 * ind + 1, low, mid, l, r);
        Node right = query(2 * ind + 2, mid + 1, high, l, r);
        return merge(left, right);
    }
};

int main() {
    int n;
    string s; cin >> s;
    n = s.size();
    SGTree seg(n);
    seg.build(0, 0, n - 1, s);

    int q;
    cin >> q;
    while(q --){
        int l, r; cin >> l >> r;
        l --, r --;
        cout << 2 * seg.query(0, 0, n - 1, l, r).full << endl;
    }
}