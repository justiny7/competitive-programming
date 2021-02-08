#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int A, B, n;
        cin >> A >> B >> n;
        vector<ll> a(n), b(n), need(n);
        for (ll &i:a)
            cin >> i;
        for (ll &i:b)
            cin >> i;
        ll tot=0;
        for (int i=0; i<n; ++i) {
            ll cur=a[i]*((b[i]+A-1)/A);
            tot+=cur;
            need[i]=cur-a[i]+1;
        }
        bool f=0;
        for (int i=0; i<n; ++i) {
            if (B-(tot-(a[i]*((b[i]+A-1)/A)))>=need[i])
                f=1;
        }
        if (!f)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}

