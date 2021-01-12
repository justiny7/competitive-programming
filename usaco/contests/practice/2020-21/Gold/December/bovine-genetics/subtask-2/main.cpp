#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=1e2+1;
const ll M=1e9+7;
string s;
int n;
ll dp[mxN][mxN][4][4], dp2[mxN][4], mp[256];

int main() {
    mp['A']=0, mp['C']=1, mp['G']=2, mp['T']=3;
    cin.tie(0)->sync_with_stdio(0);
    cin >> s, n=s.size();
    for (int i=0; i<n; ++i) {
        if (s[i]^'?') {
            int st=mp[s[i]];
            dp[i][i][st][st]=1;
            for (int j=i+1; j<n; ++j) {
                if (s[j]=='?' || s[j]=='A')
                    (dp[i][j][st][0]+=(dp[i][j-1][st][1]+dp[i][j-1][st][2]+dp[i][j-1][st][3])%M)%=M;
                if (s[j]=='?' || s[j]=='C')
                    (dp[i][j][st][1]+=(dp[i][j-1][st][0]+dp[i][j-1][st][2]+dp[i][j-1][st][3])%M)%=M;
                if (s[j]=='?' || s[j]=='G')
                    (dp[i][j][st][2]+=(dp[i][j-1][st][1]+dp[i][j-1][st][0]+dp[i][j-1][st][3])%M)%=M;
                if (s[j]=='?' || s[j]=='T')
                    (dp[i][j][st][3]+=(dp[i][j-1][st][1]+dp[i][j-1][st][2]+dp[i][j-1][st][0])%M)%=M;
            }
        }
        else {
            for (int st=0; st<4; ++st) {
                dp[i][i][st][st]=1;
                for (int j=i+1; j<n; ++j) {
                    if (s[j]=='?' || s[j]=='A')
                        (dp[i][j][st][0]+=(dp[i][j-1][st][1]+dp[i][j-1][st][2]+dp[i][j-1][st][3])%M)%=M;
                    if (s[j]=='?' || s[j]=='C')
                        (dp[i][j][st][1]+=(dp[i][j-1][st][0]+dp[i][j-1][st][2]+dp[i][j-1][st][3])%M)%=M;
                    if (s[j]=='?' || s[j]=='G')
                        (dp[i][j][st][2]+=(dp[i][j-1][st][1]+dp[i][j-1][st][0]+dp[i][j-1][st][3])%M)%=M;
                    if (s[j]=='?' || s[j]=='T')
                        (dp[i][j][st][3]+=(dp[i][j-1][st][1]+dp[i][j-1][st][2]+dp[i][j-1][st][0])%M)%=M;
                }
            }
        }
    }
    for (int i=0; i<n; ++i) {
        if (s[i]^'?') {
            int en=mp[s[i]];
            for (int j=0; j<4; ++j)
                dp2[i][j]+=dp[0][i][j][en];
            for (int j=0; j<i; ++j) {
                if (s[j+1]=='?' || s[j+1]=='A')
                    (dp2[i][0]+=(dp2[j][en]*dp[j+1][i][0][en])%M)%=M;
                if (s[j+1]=='?' || s[j+1]=='C')
                    (dp2[i][1]+=(dp2[j][en]*dp[j+1][i][1][en])%M)%=M;
                if (s[j+1]=='?' || s[j+1]=='G')
                    (dp2[i][2]+=(dp2[j][en]*dp[j+1][i][2][en])%M)%=M;
                if (s[j+1]=='?' || s[j+1]=='T')
                    (dp2[i][3]+=(dp2[j][en]*dp[j+1][i][3][en])%M)%=M;
            }
        }
        else {
            for (int en=0; en<4; ++en) {
                for (int j=0; j<4; ++j)
                    dp2[i][j]+=dp[0][i][j][en];
                for (int j=0; j<i; ++j) {
                    if (s[j+1]=='?' || s[j+1]=='A')
                        (dp2[i][0]+=(dp2[j][en]*dp[j+1][i][0][en])%M)%=M;
                    if (s[j+1]=='?' || s[j+1]=='C')
                        (dp2[i][1]+=(dp2[j][en]*dp[j+1][i][1][en])%M)%=M;
                    if (s[j+1]=='?' || s[j+1]=='G')
                        (dp2[i][2]+=(dp2[j][en]*dp[j+1][i][2][en])%M)%=M;
                    if (s[j+1]=='?' || s[j+1]=='T')
                        (dp2[i][3]+=(dp2[j][en]*dp[j+1][i][3][en])%M)%=M;
                }
            }
        }
    }
    cout << (dp2[n-1][0]+dp2[n-1][1]+dp2[n-1][2]+dp2[n-1][3])%M << '\n';
}

