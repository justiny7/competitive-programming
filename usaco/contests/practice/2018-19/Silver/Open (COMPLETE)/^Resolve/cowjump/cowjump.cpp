//YES got it second try after technical debugging (file I/O, compilation error, overflow)
#include <bits/stdc++.h>
#define y first
#define x second
#define pb push_back
using namespace std;
using pll=pair<long long, long long>;

ifstream fin("cowjump.in");
ofstream fout("cowjump.out");

struct cmp {
    bool operator() (pll a, pll b) const {
        if (a.y^b.y)
            return a.y<b.y;
        return a.x<b.x;
    }
};

int n;
map<pll, pll> other;
map<pair<pll, pll>, int> id;
set<pll, cmp> cur;
vector<pll> pts;

bool ccw(pll a, pll b, pll c) {
    return ((c.y-a.y)*(b.x-a.x)>(b.y-a.y)*(c.x-a.x));
}
bool isect(pll a, pll b, pll c, pll d) {
    return (ccw(a, c, d)^ccw(b, c, d) && ccw(a, b, c)^ccw(a, b, d));
}

void finish(pll a, pll b) {
    int acnt=0, bcnt=0,
        aid=id[make_pair(a, other[a])],
        bid=id[make_pair(b, other[b])];
    for (pll p:cur)
        if (isect(a, other[a], p, other[p]))
            ++acnt;
    if (acnt>1) {
        fout << aid << '\n';
        exit(0);
    }
    for (pll p:cur)
        if (isect(b, other[b], p, other[p]))
            ++bcnt;
    if (bcnt>1)
        fout << bid << '\n';
    else
        fout << min(aid, bid) << '\n';
    exit(0);
}

int main() {
    fin >> n;
    for (int i=0; i<n; ++i) {
        int a, b, c, d;
        fin >> a >> b >> c >> d;
        pll st=pll(a, b), en=pll(c, d);
        id[make_pair(st, en)]=id[make_pair(en, st)]=i+1;
        other[st]=en;
        other[en]=st;
        pts.pb(st);
        pts.pb(en);
    }
    sort(pts.begin(), pts.end());
    for (int i=0; i<n*2; ++i) {
        pll o=other[pts[i]];
        if (cur.count(o)) {
            auto it=cur.find(o);
            if (it==cur.begin() || it==cur.end()) {
                cur.erase(it);
                continue;
            }
            auto it2=it++;
            cur.erase(it2--);
            if (isect(*it, other[*it], *it2, other[*it2]))
                finish(*it, *it2);
        }
        else {
            cur.insert(pts[i]);
            auto it=cur.find(pts[i]);
            auto it2=it;
            if (it--!=cur.begin() && isect(pts[i], o, *it, other[*it]))
                finish(pts[i], *it);
            if (it2++!=cur.end() && isect(pts[i], o, *it2, other[*it2]))
                finish(pts[i], *it2);
        }
    }
}

