#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using ll=long long;
using pll=pair<ll, ll>;

const int mxP=2e5+5;
ll n, p, dp[mxP], t[mxP<<2];
map<ll, ll> cmp;
struct event {
    int type, id;
    pll pos;
    bool operator<(const event &o) const {
        return pos<o.pos;
    }
};
vector<event> events;

void upd(int i, ll val, int l=0, int r=mxP-1, int v=1) {
    if (l==r) {
        t[v]=min(t[v], val);
        return;
    }
    int m=l+r>>1;
    if (i<=m)
        upd(i, val, l, m, v<<1);
    else
        upd(i, val, m+1, r, v<<1|1);
    t[v]=min(t[v<<1], t[v<<1|1]);
}
ll query(int l, int r, int lo=0, int hi=mxP-1, int v=1) {
    if (l>hi || r<lo)
        return 0;
    if (lo>=l && hi<=r)
        return t[v];
    int m=lo+hi>>1;
    return min(query(l, r, lo, m, v<<1), query(l, r, m+1, hi, v<<1|1));
}

int main() {
    ifstream cin("boards.in");
    ofstream cout("boards.out");
    cin >> n >> p;
    {
        array<ll, 4> temp[mxP];
        set<ll> compress;
        for (int i=0; i<p; ++i)
            for (int j=0; j<4; ++j) {
                cin >> temp[i][j];
                if (j&1)
                    compress.insert(temp[i][j]);
            }
        int c=0;
        for (ll i:compress)
            cmp[i]=++c;
        for (int i=0; i<p; ++i) {
            auto here=temp[i];
            events.push_back(event{0, i, pll(here[0], here[1])});
            events.push_back(event{1, i, pll(here[2], here[3])});
        }
    }
    sort(events.begin(), events.end());
    for (int i=0; i<events.size(); ++i) {
        event here=events[i];
        if (here.type)
            upd(cmp[here.pos.y], dp[here.id]-here.pos.x-here.pos.y);
        else
            dp[here.id]=here.pos.x+here.pos.y+query(0, cmp[here.pos.y]);
    }
    cout << n*2+query(0, mxP-1) << '\n';
}

