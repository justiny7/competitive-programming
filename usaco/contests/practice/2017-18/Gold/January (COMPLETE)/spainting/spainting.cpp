//Idea: you need at least 1 section of k consecutive same colors, and everything else
//can be whatever you want
//Sadly, I have no idea how to implement this so I looked at the solution
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ifstream fin("spainting.in");
ofstream fout("spainting.out");

const int mxN=1e6+1;
const ll M=1e9+7;
ll n, m, k, dp[mxN], all=1;

int main() {
    fin >> n >> m >> k;
    for (int i=1; i<k; ++i)
        dp[i]=(m*dp[i-1]+m)%M;
    for (int i=k; i<=n; ++i)
        dp[i]=(m*dp[i-1]-((m-1)*dp[i-k])%M+M)%M;
    for (int i=1; i<=n; ++i)
        all=(m*all)%M;
    fout << (all-(dp[n]-dp[n-1])%M+M)%M << '\n';
}
