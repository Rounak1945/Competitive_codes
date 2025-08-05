#include<bits/stdc++.h>
using namespace std;


// Digit Dp states
// 1) index
// 2) tight (bool)
// 3) leading zero
// 4) other custom state (eg: sum, parity, pattern, count, etc);


// Example : sum of digits in range l to r
//constraint : 1 <= l < r <= 1e18


// Dp array index x tight(bool) x sum (current sum of digits accumulated so far)
#define ll long long

ll dp[19][2][174];

ll f(ll idx, bool tight, ll sum, string &s) {
    if(idx == s.size()) return sum;

    if(dp[idx][tight][sum] != -1) return dp[idx][tight][sum];

    ll ans = 0;
    // calculate limit for current index
    ll limit = tight ? s[idx] - '0' : 9;

    for(int d = 0; d <= limit; d ++) {
        bool newTight = tight & (d == limit);
        ans += f(idx + 1, newTight, sum + d, s);
    }

    return dp[idx][tight][sum] = ans;
}

int main() {
    ll l, r;
    cin >> l >> r;

    string a = to_string(l - 1);
    memset(dp, -1, sizeof(dp));
    ll ans1 = f(0, 1, 0, a);

    string b = to_string(r);
    memset(dp, -1, sizeof(dp));
    ll ans2 = f(0, 1, 0, b);

    cout << ans2 - ans1 << endl;
}
