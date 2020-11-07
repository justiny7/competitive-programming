#include <bits/stdc++.h>
using namespace std;

ifstream fin("lazy.in");
ofstream fout("lazy.out");

const int mxN=401;
int n, k, sum, ans, pref[mxN][mxN];

int get(int y, int x) {
    int b=y-k, t=y+k, a=0;
    for (int i=b; i<=t; ++i) {
        if (i<=0 || i>n)
            continue;
        a+=pref[i][min(n, x+k-abs(i-y))]-pref[i][max(0, x-k+abs(i-y)-1)];
    }
    return a;
}

int main(void) {
    fin >> n >> k;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=n; ++j) {
            int a; fin >> a;
            pref[i][j]=a+pref[i][j-1];
            sum+=a;
        }
    if (k>=n) {
        fout << sum << '\n';
        return 0;
    }
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=n; ++j)
            ans=max(ans, get(i, j));
    fout << ans << '\n';
}
