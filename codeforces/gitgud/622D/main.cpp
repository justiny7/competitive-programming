#include <bits/stdc++.h>
using namespace std;

const int mxN=5e5+1;
int n, ans[mxN<<1];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=1, j=0; i<=n; i+=2, ++j)
        ans[j]=ans[n-j-1]=i;
    for (int i=2, j=0; i<=n; i+=2, ++j)
        ans[j+n]=ans[n*2-j-2]=i;
    for (int i=0; i<n<<1; ++i)
        cout << (ans[i]?ans[i]:n) << (i<(n<<1)-1?" ":"\n");
}

