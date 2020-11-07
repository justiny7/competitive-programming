#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5+1;
int n, c[101], dp[mxN][101];
set<int> ans;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i=1; i<=n; ++i)
        cin >> c[i];
    dp[0][0]=1;
    for (int i=0; i<mxN; ++i) {
        for (int j=0; j<=n; ++j)
            if (dp[i][j])
                for (int k=j+1; k<=n; ++k)
                    dp[i+c[k]][k]=1;
    }
    for (int i=0; i<mxN; ++i)
        for (int j=1; j<=n; ++j)
            if (dp[i][j]) {
                ans.insert(i);
                break;
            }
    cout << ans.size() << '\n';
    for (int i:ans)
        cout << i << " ";
    cout << '\n';
}
