#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, ans, last;

int main(void) {
    cin >> n >> last;
    ans=last;
    for (int i=1; i<n; i++) {
        ll cur;
        cin >> cur;
        last=max(cur, cur+last);
        ans=max(ans, last);
    }
    cout << ans << '\n';
}

