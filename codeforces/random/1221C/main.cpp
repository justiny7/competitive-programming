#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int c, m, x;
        cin >> c >> m >> x;
        int ans=min({c, m, x});
        c-=ans, m-=ans, x-=ans;
        if (c && m) {
            if (c>m)
                swap(c, m);
            if (m>=c*2)
                ans+=c;
            else
                ans+=(m-c)+(2*c-m)*2/3;
        }
        cout << ans << '\n';
    }
}

