#include <bits/stdc++.h>
#define fi first
#define se second
#define NO return void(cout << "NO\n")
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> v(m);
    for (auto &p:v)
        cin >> p.se >> p.fi;
    sort(v.begin(), v.end());
    if (m&1)
        NO;
    for (int i=0; i<m; i+=2) {
        if (i && v[i].fi==v[i-1].fi)
            NO;
        if (((v[i].fi+v[i].se)&1)==((v[i+1].fi+v[i+1].se)&1))
            NO;
    }
    cout << "YES\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        solve();
}

