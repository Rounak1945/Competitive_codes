#include<bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> rank, parent;

    public:
    DSU(int n){
        rank.resize(n + 1, 0);
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
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u] ++;
        }
    }
};

// Assigning at find parent function is for path compression
// we are adding the node of lower rank to a higher rank node 
// because of not getting high rank values;
// The parent will be the guy with higher rank
// Rank didn't actually tell about height because of path compression
// Ultimate parent is the topmost parent all;

int main() {

}
