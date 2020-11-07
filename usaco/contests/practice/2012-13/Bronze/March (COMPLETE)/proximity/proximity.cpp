//Yay worked first try
#include <bits/stdc++.h>
using namespace std;

const int mxV=1e6+1;
int n, k, ans, lst[mxV];

int main() {
    ifstream cin("proximity.in");
    ofstream cout("proximity.out");
    cin >> n >> k;
    for (int i=1; i<=n; ++i) {
        int a; cin >> a;
        if (lst[a] && i-lst[a]<=k)
            ans=max(ans, a);
        lst[a]=i;
    }
    cout << ans << '\n';
}

