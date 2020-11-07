#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll n, ans;
map<int, ll> occ[2];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    occ[0][0]=1;
    for (int i=1, cur=0; i<=n; ++i) {
        int c=i&1, a;
        cin >> a;
        cur^=a;
        if (occ[c].count(cur))
            ans+=occ[c][cur];
        ++occ[c][cur];
    }
    cout << ans << '\n';
}


