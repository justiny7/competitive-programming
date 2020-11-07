#include <bits/stdc++.h>
using namespace std;

int n, ans=1;
const int MOD=1e9+7;

int main(void) {
    cin >> n;
    if (n==0) {
        cout << "0\n";
        return 0;
    }
    for (int i=0; i<n; ++i)
        ans=(2*ans)%MOD;
    cout << ans << '\n';
}
