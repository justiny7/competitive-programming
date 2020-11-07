#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=2e5+1;
ll n, a, b, pref[mxN], ans=LLONG_MIN;
multiset<ll> s;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> a >> b;
    for (int i=0; i<n; ++i) {
        cin >> pref[i+1], pref[i+1]+=pref[i];
        if (i>=a-1) {
            s.insert(pref[i-a+1]);
            if (i>=b)
                s.erase(s.find(pref[i-b]));
            ans=max(ans, pref[i+1]-*s.begin());
        }
    }
    cout << ans << '\n';
}

