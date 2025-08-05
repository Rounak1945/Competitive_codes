// For queries related to minimum value of range  

#include<bits/stdc++.h>
using namespace std;
#define ll long long

class SGTree{
    vector<ll> seg;
    
    public:
    SGTree(ll n){
        seg.resize(4 * n + 1);
    }

    void build(ll ind, ll low, ll high, vector<ll> &v){
        if(low == high) {
            seg[ind] = v[low];
            return;
        }

        ll mid = (low + high) >> 1;

        build(2 * ind + 1, low, mid, v);
        build(2 * ind + 2, mid + 1, high, v);

        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }

    ll query(ll ind, ll low, ll high, ll l, ll r){
        // no overlap
        // l r low high or low high l r
        if(r < low || high < l) return LLONG_MAX;

        // complete overlap
        // [l low high r]
        if(low >= l && high <= r) return seg[ind];

        // on overlap
        ll mid = (low + high) >> 1;
        ll left = query(2 * ind + 1, low, mid, l, r);
        ll right = query(2 * ind + 2, mid + 1, high, l, r);
        return min(left, right);
    }

    void update(ll ind, ll low, ll high, ll i, ll val){
        if(low == high) {
            seg[ind] = val;
            return;
        }

        ll mid = (low + high) >> 1;
        if(i <= mid) update(2 * ind + 1, low, mid, i, val);
        else update(2 * ind + 2, mid + 1, high, i, val);

        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
};

int main() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    for(ll i = 0; i < n; i++) cin >> v[i];
    SGTree seg(n);
    seg.build(0, 0, n - 1, v);

    ll q;
    cin >> q;
    while(q --){
        ll t;
        cin >> t;

        ll l, r; cin >> l >> r;
        cout << seg.query(0, 0, n - 1, l, r) << endl;
    }
}