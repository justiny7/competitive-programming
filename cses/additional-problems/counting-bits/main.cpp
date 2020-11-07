#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll n, ans;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n, ++n;
    for (ll i=1; i<=n; i*=2)
        ans+=(n-(n%(i*2)))/2+max(0LL, (n%(i*2)-i));
    cout << ans << '\n';
}

