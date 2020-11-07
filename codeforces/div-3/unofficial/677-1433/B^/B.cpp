#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, lst=-1, ans=0; cin >> n;
        for (int i=0; i<n; ++i) {
            int a; cin >> a;
            if (a) {
                if (~lst)
                    ans+=i-lst-1;
                lst=i;
            }
        }
        cout << ans << '\n';
    }
}

