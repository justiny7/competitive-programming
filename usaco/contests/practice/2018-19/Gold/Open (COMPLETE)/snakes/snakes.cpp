//Yay got it second try when I changed it from recursive to iterative segtree
#include <bits/stdc++.h>
using namespace std;

struct node {
    int mx=0, sum=0;
    node() {}
    node(int mx, int sum):mx(mx), sum(sum) {}
};

const int mxN=401;
int n, k, dp[mxN][mxN];
node seg[mxN*2];

node merge(node a, node b) {
    return node(max(a.mx, b.mx), a.sum+b.sum);
}

void build() {
    for (int i=n-1; i; --i)
        seg[i]=merge(seg[i*2], seg[i*2+1]);
}

node query(int l, int r) {
    node ans;
    for (l+=n, r+=n+1; l<r; l/=2, r/=2) {
        if (l&1)
            ans=merge(ans, seg[l++]);
        if (r&1)
            ans=merge(ans, seg[--r]);
    }
    return ans;
}

int main() {
    memset(dp, 0x3f, sizeof(dp));
    ifstream cin("snakes.in");
    ofstream cout("snakes.out");
    cin >> n >> k;
    for (int i=0; i<n; ++i) {
        int a; cin >> a;
        seg[n+i].sum=seg[n+i].mx=a;
    }
    build();
    for (int i=0; i<n; ++i) {
        node r=query(0, i);
        dp[i][0]=r.mx*(i+1)-r.sum;
        for (int j=1; j<=k; ++j)
            for (int l=0; l<=i; ++l) {
                node q=query(l, i);
                dp[i][j]=min(dp[i][j], (l?dp[l-1][j-1]:0)+q.mx*(i-l+1)-q.sum);
            }
    }
    cout << dp[n-1][k] << '\n';
}

