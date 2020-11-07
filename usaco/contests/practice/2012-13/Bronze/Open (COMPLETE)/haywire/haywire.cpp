//Looked at sol - was not expecting dp on old bronze xd
#include <bits/stdc++.h>
using namespace std;

const int mxN=12;
int n, a[mxN][3], dp[1<<mxN];

int main() {
    memset(dp, 0x3f, sizeof(dp));
    ifstream cin("haywire.in");
    ofstream cout("haywire.out");
    cin >> n;
    for (int i=0; i<n; ++i)
        for (int j=0; j<3; ++j)
            cin >> a[i][j], --a[i][j];
    dp[0]=0;
    for (int i=1; i<(1<<n); ++i) {
        int cur=0; //total # of times this segment of wire is crossed
        for (int j=0; j<n; ++j)
            if (i&(1<<j)) {
                cur+=3; //each cow contributes 3-(# of friends already here)
                for (int k=0; k<3; ++k)
                    if (i&(1<<a[j][k]))
                        --cur;
            }
        for (int j=0; j<n; ++j)
            if (i&(1<<j)) {
                int c=cur-3; //-3+(# of friends already here) undos a cow's contribution to cur,
                for (int k=0; k<3; ++k) //then we add (# of friends already here) again to get the
                    if (i&(1<<a[j][k])) //cost for adding that cow
                        c+=2;
                dp[i]=min(dp[i], dp[~(1<<j)&i]+c);
            }
    }
    cout << dp[(1<<n)-1] << '\n';
}

