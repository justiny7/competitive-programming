#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
using pii=pair<int, int>;

struct cow {
    int pos, w, dir;
    bool operator<(const cow& c) const {
        return pos<c.pos;
    }
};

const int mxN=5e4+1;
int n, l, t, tot, ans;
cow cows[mxN];
vector<pii> lcows, rcows;

int main() {
    ifstream cin("meetings.in");
    ofstream cout("meetings.out");
    cin >> n >> l;
    for (int i=0; i<n; ++i) {
        cin >> cows[i].w >> cows[i].pos >> cows[i].dir;
        if (cows[i].dir==-1)
            lcows.pb({cows[i].pos, 0});
        else
            rcows.pb({l-cows[i].pos, 0});
        tot+=cows[i].w;
    }
    sort(cows, cows+n);
    sort(lcows.begin(), lcows.end());
    sort(rcows.begin(), rcows.end());
    for (int i=0; i<n; ++i) {
        if (i<lcows.size())
            lcows[i].se=cows[i].w;
        else
            rcows[n-1-i].se=cows[i].w;
    }
    int cur=0, a=0, b=0;
    while (cur*2<tot) {
        if (a<lcows.size() && (b==rcows.size() || (lcows[a].fi<rcows[b].fi)))
            cur+=lcows[a].se, t=lcows[a++].fi;
        else
            cur+=rcows[b].se, t=rcows[b++].fi;
    }
    cur=0;
    for (int i=0, j=0; i<n; ++i) {
        if (cows[i].dir==-1) {
            if (cur)
                --cur;
            continue;
        }
        if (j<i)
            j=i;
        while (j<n && cows[j].pos<=cows[i].pos+2*t)
            if (cows[j++].dir==-1)
                ++cur;
        ans+=cur;
    }
    cout << ans << '\n';
}

