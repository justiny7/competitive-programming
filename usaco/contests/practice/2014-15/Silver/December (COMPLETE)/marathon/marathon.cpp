#include <bits/stdc++.h>
using namespace std;
//Noo I was so close to getting the solution myself but I had to sneak a peek at the answer T-T
//dp is definitely a weak point for me
ifstream fin("marathon.in");
ofstream fout("marathon.out");

const int mxN=501;
int n, k, ans, dp[mxN][mxN], x[mxN], y[mxN];

int get_dist(int a, int b) {
    int x1=x[a], x2=x[b], y1=y[a], y2=y[b];
    return (abs(x1-x2)+abs(y1-y2));
}

int main(void) {
    fin >> n >> k;
    memset(dp, 0x3f, sizeof(dp));
    for (int i=0; i<n; ++i)
        fin >> x[i] >> y[i];
    dp[0][0]=0;
    for (int i=0; i<=k; ++i)
        for (int j=0; j<n; ++j)
            for (int l=j+1; l<n && l-j-1+i<=k; ++l)
                dp[i+l-j-1][l]=min(dp[i+l-j-1][l], dp[i][j]+get_dist(j, l));
    fout << dp[k][n-1] << '\n';
}
