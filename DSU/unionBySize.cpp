#include<bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> size, parent;

    public:
    DSU(int n){
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for(int i = 0; i <= n; i++) parent[i] = i;
    }

    int findPar(int node){
        if(node == parent[node]) return node;
        else return parent[node] = findPar(parent[node]);
    }

    void unionByRank(int u, int v){
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

// Union by size is more intutive 

int main() {

}