//Peeked at solution
#include <bits/stdc++.h>
using namespace std;

const int mxN=1e3+1, M=2012;
string s;
int n, dp[mxN][mxN], dep[mxN];

int go(int i=0, int a=0) {
    if (i==n)
        return 1;
    if (dp[i][a]>=0)
        return dp[i][a];
    if (s[i]=='(')
        return dp[i][a]=(go(i+1, a+1)+go(i+1, a))%M;
    else {
        dp[i][a]=0;
        if (a>0)
            dp[i][a]+=go(i+1, a-1);
        if (dep[i]-a>0)
            dp[i][a]+=go(i+1, a);
        return dp[i][a]%=M;
    }
}

int main() {
    ifstream cin("bbreeds.in");
    ofstream cout("bbreeds.out");
    cin >> s, n=s.size();
    if (n&1 || (count(s.begin(), s.end(), '(')^(n/2))) {
        cout << "0\n";
        return 0;
    }
    for (int i=0; i<n; ++i)
        dep[i+1]=dep[i]+(s[i]=='('?1:-1);
    memset(dp, -1, sizeof(dp));
    cout << go() << '\n';
}

