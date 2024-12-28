//I DIDN'T GET THIS IN CONTEST BECAUSE OF STACK OVERFLOW AHHHHHH
//(and also cuz I accidentally copy/pasted 2 million lines of code but we don't talk about that)
#include <bits/stdc++.h>
#define fi first
#define se second
#define lb lower_bound
#define mp make_pair
using namespace std;
using pii=pair<int, int>;

template<class T> ckmax(T& a, const T& b) {
    return (a<b)?a=b,1:0;
}

ifstream fin("input.txt");
ofstream fout("output.txt");

const int mxN=1e6+1;
int n;
pii a[mxN];
bool vis[mxN];
map<int, pii> fall;

void go_r(int c, int len) {
    while (1) {
        vis[c]=1;
        int endpos=a[c].fi+a[c].se;
        len+=a[c].se;
        ckmax(fall[endpos].fi, len);
        int nxt=lb(a+c, a+n, mp(endpos, 0))-a;
        if (nxt==n)
            return;
        if (a[nxt].fi!=endpos)
            break;
        c=nxt;
    }
}

void go_l(int c, int len) {
    while (1) {
        vis[c]=1;
        int endpos=a[c].fi-a[c].se;
        len+=a[c].se;
        ckmax(fall[endpos].se, len);
        int nxt=lb(a, a+c+1, mp(endpos, 0))-a;
        if (nxt==n)
            return;
        if (a[nxt].fi!=endpos)
            break;
        c=nxt;
    }
}

int solve() {
    fall.clear();
    int ans=0;
    fill(vis, vis+n, 0);
    sort(a, a+n);
    for (int i=0; i<n; ++i)
        if (!vis[i])
            go_r(i, 0);
    fill(vis, vis+n, 0);
    for (int i=n-1; i>=0; --i)
        if (!vis[i])
            go_l(i, 0);
    for (auto a:fall)
        ckmax(ans, a.se.fi+a.se.se);
    return ans;
}

int main() {
    int t; fin >> t;
    for (int tt=1; tt<=t; ++tt) {
        fin >> n;
        for (int i=0; i<n; ++i)
            fin >> a[i].fi >> a[i].se;
        fout << "Case #" << tt << ": " << solve() << '\n';
    }
}
