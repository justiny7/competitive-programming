#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5+1;
bitset<mxN> dp;
int n;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    dp[0]=1;
    while (n--) {
        int c; cin >> c;
        dp|=(dp<<c);
    }
    cout << dp.count()-1 << '\n';
    for (int i=1; i<mxN; ++i)
        if (dp[i])
            cout << i << " ";
    cout << '\n';
}
