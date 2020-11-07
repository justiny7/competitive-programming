#include <bits/stdc++.h>
using namespace std;

const int mxN=1e3+1;
long long n, m, row[mxN], col[mxN];
string b[mxN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i=0; i<n; ++i)
        cin >> b[i], row[i]=count(b[i].begin(), b[i].end(), '*');
    for (int i=0; i<m; ++i) {
        int c=0;
        for (int j=0; j<n; ++j)
            c+=b[j][i]=='*';
        col[i]=c;
    }
    long long ans=0;
    for (int i=0; i<n; ++i)
        for (int j=0; j<m; ++j)
            if (b[i][j]=='*')
                ans+=(row[i]-1)*(col[j]-1);
    cout << ans << '\n';
}

