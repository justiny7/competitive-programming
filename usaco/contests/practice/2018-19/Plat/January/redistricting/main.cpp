#include <bits/stdc++.h>
using namespace std;

const int mxN=3e5+1;
int n, k, pref[mxN], dp[mxN];
string s;
multiset<pair<int, int>> m;

int main() {
    ifstream cin("redistricting.in");
    ofstream cout("redistricting.out");
    cin >> n >> k >> s;
    for (int i=0; i<n; ++i)
        pref[i+1]=pref[i]+(s[i]=='H'?1:-1);
    m.emplace(0, 0);
    for (int i=1; i<=n; ++i) {
        auto it=m.begin();
        dp[i]=it->first+(pref[i]-it->second<=0);
        m.emplace(dp[i], pref[i]);
        if (i>=k)
            m.erase(m.find({dp[i-k], pref[i-k]}));
    }
    cout << dp[n] << '\n';
}

