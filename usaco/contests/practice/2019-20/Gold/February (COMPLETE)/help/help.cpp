//Had to look at solution - I probably need to practice more math
#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5+1, M=1e9+7;
int n, ans, cnt[mxN*2], p[mxN], s[mxN];

int main() {
    ifstream cin("help.in");
    ofstream cout("help.out");
    cin >> n;
    for (int i=0; i<n; ++i) {
        int a, b;
        cin >> a >> b;
        ++cnt[a], --cnt[b];
        s[i]=a;
    }
    for (int i=1; i<=n*2; ++i)
        cnt[i]+=cnt[i-1];
    p[0]=1;
    for (int i=1; i<=n; ++i)
        p[i]=p[i-1]*2%M;
    for (int i=0; i<n; ++i)
        ans=(ans+p[n-1-cnt[s[i]-1]])%M;
    cout << ans << '\n';
}

