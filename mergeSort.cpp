#include<bits/stdc++.h>
using namespace std;
#define ll long long

/* -----------------------------------------------------(•‿•)-------------------------------------------------------------*/


void merge(vector<ll> &v, ll lo, ll mid, ll hi){
    vector<ll>temp;
    ll l = lo;
    ll r = mid+1;

    while(l <= mid && r <= hi){
        if(v[l] <= v[r]) {
            temp.push_back(v[l]);
            l++;
        }
        else {
            temp.push_back(v[r]);
            r++;
        }
    }

    while(l <= mid){
        temp.push_back(v[l]);
        l++;
    }
    while(r <= hi){
        temp.push_back(v[r]);
        r++;
    }

    for(ll i = lo; i <= hi; i++){
        v[i] = temp[i-lo];
    }
}

void mS(vector<ll> &v, ll lo, ll hi){
    if(lo == hi) return;
    ll mid = lo + (hi-lo)/2;
    
    mS(v, lo, mid);
    mS(v, mid+1, hi);

    merge(v, lo, mid, hi);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
    ll n;
    cin>>n;
    vector<ll>v;
    for(ll i=0; i<n; i++){
        ll x;
        cin>>x;
        v.push_back(x);
    }
    mS(v, 0, n-1);

    for(auto it:v){
        cout<<it<<" ";
    }
}