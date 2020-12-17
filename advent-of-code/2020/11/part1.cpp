#include <bits/stdc++.h>
using namespace std;

const int mxN=101, dx[]={0,1,1,1,0,-1,-1,-1}, dy[]={1,1,0,-1,-1,-1,0,1};
int n, m;
vector<string> a, b;

inline bool in(int i, int j) {
    return (i>=0 && j>=0 && i<n && j<m);
}
inline int cnt(int i, int j) {
    int ret=0;
    for (int t=0; t<8; ++t) {
        int x=i+dx[t], y=j+dy[t];
        if (in(x, y))
            ret+=(a[x][y]=='#');
    }
    return ret;
}

int main() {
    freopen("test.txt", "r", stdin);
    {
        string s;
        for (; cin >> s; ++n)
            b.push_back(s);
    }
    m=b[0].size();
    do {
        a=b;
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j) {
                int c=cnt(i, j);
                if (a[i][j]=='#' && c>=4)
                    b[i][j]='L';
                else if (a[i][j]=='L' && !c)
                    b[i][j]='#';
            }
    } while (b!=a);
    int ans=0;
    for (int i=0; i<n; ++i)
        for (int j=0; j<m; ++j)
            ans+=b[i][j]=='#';
    cout << ans << '\n';
}

