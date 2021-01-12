//Read editorial
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=1e5+1;
const ll M=1e9+7;
string s;
int n, mp[256];
ll ans, dp[mxN][4][4][4]; //dp[i][j][k][l] = # of ways to have the last substring starting with j and the current substring starting with k and ending with l, ending at position i

int main() {
    mp['A']=0, mp['C']=1, mp['G']=2, mp['T']=3;
    cin.tie(0)->sync_with_stdio(0);
    cin >> s, n=s.size();
    for (int i=0; i<n; ++i) {
        if (i) {
            for (int j=0; j<4; ++j) //append current character to last substrings
                for (int k=0; k<4; ++k)
                    for (int l=0; l<4; ++l)
                        for (int m=0; m<4; ++m)
                            if ((l^m) && (s[i]=='?' || mp[s[i]]==m))
                                (dp[i][j][k][m]+=dp[i-1][j][k][l])%=M;
            for (int j=0; j<4; ++j) //create new substring here
                for (int k=0; k<4; ++k)
                    for (int l=0; l<4; ++l)
                        if (s[i]=='?' || mp[s[i]]==l)
                            (dp[i][k][l][l]+=dp[i-1][j][k][j])%=M;
        }
        else { //base case
            for (int j=0; j<4; ++j)
                for (int k=0; k<4; ++k)
                    if (s[i]=='?' || mp[s[i]]==k)
                        dp[i][j][k][k]=1;
        }
    }
    for (int i=0; i<4; ++i)
        for (int j=0; j<4; ++j)
            (ans+=dp[n-1][i][j][i])%=M;
    cout << ans << '\n';
}

