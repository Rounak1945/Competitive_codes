// Distinct colors (CSES)
// Union by size using set which is more intutive
// see gfg article if forget

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> g(200005);
vector<set<int>> colors(200005);
vector<int> grp(200005);

int merge(int grp_a, int grp_b){
    if(colors[grp_a].size() < colors[grp_b].size()) swap(grp_a, grp_b);

    for(auto c: colors[grp_b]) colors[grp_a].insert(c);
    colors[grp_b].clear();
    return grp_a;
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++){
        int x;
        cin >> x;
        grp[i] = i;
        colors[grp[i]].insert(x);
    }

    vector<int> ans(n);
    for(int i = 0; i < n - 1; i ++){
        int u, v;
        cin >> u >> v;
        u --, v --;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    auto dfs = [&] (auto &dfs, int v, int par) -> int {

        for(auto c: g[v]){
            if(c == par) continue;

            grp[v] = merge(grp[v], dfs(dfs, c, v));
        }
        ans[v] = colors[grp[v]].size();
        return grp[v];
    };

    dfs(dfs, 0, -1);
    for(int i = 0; i < n; i ++) cout << ans[i] << " ";
    cout << endl;
}
