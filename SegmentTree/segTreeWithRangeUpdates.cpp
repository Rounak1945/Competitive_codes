// Range Sum queries

#include <bits/stdc++.h>
using namespace std;

class SGTree{
    vector<int> seg, lazy;
    
    public:
    SGTree(int n){
        seg.resize(4 * n + 1);
        lazy.resize(4 * n + 1);
    }

    void build(int ind, int low, int high, vector<int> &v){
        if(low == high) {
            seg[ind] = v[low];
            return;
        }

        int mid = (low + high) >> 1;

        build(2 * ind + 1, low, mid, v);
        build(2 * ind + 2, mid + 1, high, v);

        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }

    int query(int ind, int low, int high, int l, int r){
        // Update the previous remaining update 
        // and propagate one step downward to update in future
        if(lazy[ind] != 0){
            seg[ind] += (high - low + 1) * lazy[ind];
            // propagation if child exist
            if(low != high){
                lazy[2 * ind + 1] += lazy[ind];
                lazy[2 * ind + 2] += lazy[ind];
            }
            lazy[ind] = 0;
        } 

        // no overlap
        // l r low high or low high l r
        if(r < low || high < l) return 0;

        // complete overlap
        // [l low high r]
        if(low >= l && high <= r) return seg[ind];

        // on overlap
        int mid = (low + high) >> 1;
        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, high, l, r);
        return left + right;
    }

    void update(int ind, int low, int high, int l, int r, int val){
        // Update the previous remaining update 
        // and propagate one step downward to update in future
        if(lazy[ind] != 0){
            seg[ind] += (high - low + 1) * lazy[ind];
            // propagation if child exist
            if(low != high){
                lazy[2 * ind + 1] += lazy[ind];
                lazy[2 * ind + 2] += lazy[ind];
            }
            lazy[ind] = 0;
        }

        // no overlap
        // we don't do anything and return 
        if(r < low || high < l) return;

        // complete overlap
        if(low >= l && high <= r) {
            seg[ind] += (high - low + 1) * val;
            // propagation if child exist
            if(low != high){
                lazy[2 * ind + 1] += val;
                lazy[2 * ind + 2] += val;
            }
            return;
        }

        int mid = (low + high) >> 1;
        update(2 * ind + 1, low, mid, l, r, val);
        update(2 * ind + 2, mid + 1, high, l, r, val);

        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    SGTree seg(n);
    seg.build(0, 0, n - 1, v);

    int q;
    cin >> q;
    while(q --){
        int t;
        cin >> t;
        if(t == 1){
            int l, r; cin >> l >> r;
            cout << seg.query(0, 0, n - 1, l, r) << endl;
        }
        else {
            int l, r, val; cin >> l >> r >> val;
            seg.update(0, 0, n - 1, l, r, val);
        }
    }
}