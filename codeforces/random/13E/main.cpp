#include <bits/stdc++.h>
using namespace std;

const int mxN=2e5+1, rt=320;
int n, m, id[mxN], a[mxN], nxt[mxN], cnt[mxN];

void app(int x) {
    if (id[x]==id[x+a[x]]) {
        cnt[x]=cnt[x+a[x]]+1;
        nxt[x]=nxt[x+a[x]];
    }
    else {
        cnt[x]=1;
        nxt[x]=x+a[x];
    }
}
void build() {
    for (int i=0; i<n; ++i)
        id[i]=i/rt;
    for (int i=n-1; ~i; --i)
        app(i);
}
void upd(int x, int y) {
    a[x]=y;
    int cur=x;
    for (; ~cur && id[cur]==id[x]; --cur)
        app(cur);
}
pair<int, int> query(int x) {
    int cur=x, c=1;
    while (nxt[cur]<n) {
        c+=cnt[cur];
        cur=nxt[cur];
    }
    while(~id[cur+a[cur]]) {
        cur+=a[cur];
        ++c;
    }
    return {cur+1, c};
}

int main() {
    memset(id, -1, sizeof(id));
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i=0; i<n; ++i)
        cin >> a[i];
    build();
    while (m--) {
        int t, x, y;
        cin >> t;
        if (t) {
            cin >> x;
            pair<int, int> ret=query(x-1);
            cout << ret.first << " " << ret.second << '\n';
        }
        else {
            cin >> x >> y;
            upd(x-1, y);
        }
    }
}

