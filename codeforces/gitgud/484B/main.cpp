#include <bits/stdc++.h>
using namespace std;

const int mxV=2e6+1;
int n, ans, a[mxV], lb[mxV];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    while (n--) {
        int x; cin >> x;
        a[x]=1;
    }
    for (int i=2; i<mxV; ++i)
        lb[i]=(a[i-1]?i-1:lb[i-1]);
    for (int i=1; i<mxV; ++i)
        if (a[i])
            for (int j=i*2; j<mxV; j+=i)
                ans=max(ans, lb[j]%i);
    cout << ans << '\n';
}

