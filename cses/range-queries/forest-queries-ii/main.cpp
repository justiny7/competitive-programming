//It literally took me 90 minutes to find 1 stupid error
#include <bits/stdc++.h>
using namespace std;

const int mxN=1e3+1;
int n, q, bit[mxN][mxN];
string s[mxN];

int query(int x, int y) {
    int ans=0;
    for (int i=x; i>0; i-=i&(-i))
        for (int j=y; j>0; j-=j&(-j))
            ans+=bit[i][j];
    return ans;
}

int query(int x1, int y1, int x2, int y2) {
    --x1, --y1;
    return query(x2, y2)+query(x1, y1)-query(x1, y2)-query(x2, y1);
}

void upd(int x, int y, int d) {
    for (int i=x; i<=n; i+=i&(-i))
        for (int j=y; j<=n; j+=j&(-j))
            bit[i][j]+=d;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    for (int i=1; i<=n; ++i) {
        cin >> s[i-1];
        for (int j=1; j<=n; ++j)
            upd(i, j, (s[i-1][j-1]=='*'?1:0));
    }
    while (q--) {
        int t; cin >> t;
        if (t==2) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            cout << query(x1, y1, x2, y2) << '\n';
        }
        else {
            int x, y;
            cin >> x >> y;
            if (s[x-1][y-1]=='*') {
                upd(x, y, -1);
                s[x-1][y-1]='.';
            }
            else {
                upd(x, y, 1);
                s[x-1][y-1]='*';
            }
        }
    }
}
