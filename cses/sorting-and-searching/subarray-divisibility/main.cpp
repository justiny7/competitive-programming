#include <bits/stdc++.h>
#define se second
using namespace std;
using ll=long long;

int n;
ll pref, ans;
map<int, ll> mp;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i=0; i<n; ++i) {
        int a; cin >> a;
        pref+=a;
        int c=((pref%n)+n)%n;
        ++mp[c];
        if (!c)
            ++ans;
    }
    for (auto& p : mp)
        ans+=(p.se-1)*p.se/2;
    cout << ans << '\n';
}
