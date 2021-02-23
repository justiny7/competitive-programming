#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll n, x, a, ans;
map<ll, int> freq;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> x;
    ++freq[0];
    for (int i=0; i<n; ++i) {
        int c; cin >> c;
        a+=c;
        ans+=freq[a-x];
        ++freq[a];
    }
    cout << ans << '\n';
}
