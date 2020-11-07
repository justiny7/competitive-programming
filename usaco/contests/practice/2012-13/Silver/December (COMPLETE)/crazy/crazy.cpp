//Yay got it third try cuz overflow
#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
using namespace std;
using pii=pair<int, int>;

const int mxN=1e3+1;
const pii far={(int)2e6+7, (int)2e6+17};
int n, c, grp[mxN], gcnt;
pii cows[mxN];
struct fence {
    pii a, b;
} v[mxN];
unordered_map<bitset<mxN>, int> cnt;

bool ccw(pii p, pii q, pii r) {
    return 1LL*(r.y-p.y)*(q.x-p.x)>1LL*(q.y-p.y)*(r.x-p.x);
}

bool isect(pii p, pii q, pii r, pii s) {
    return ((ccw(p, r, s)^ccw(q, r, s)) && (ccw(p, q, r)^ccw(p, q, s)));
}

int main() {
    ifstream cin("crazy.in");
    ofstream cout("crazy.out");
    cin >> n >> c;
    for (int i=0; i<n; ++i)
        cin >> v[i].a.x >> v[i].a.y >> v[i].b.x >> v[i].b.y;
    for (int i=0; i<c; ++i)
        cin >> cows[i].x >> cows[i].y;
    for (int i=0; i<n; ++i) {
        if (grp[i])
            continue;
        grp[i]=++gcnt;
        fence lst=v[i];
        bool f;
        do {
            f=0;
            for (int j=0; j<n; ++j) {
                if (grp[j])
                    continue;
                if (v[j].a==lst.a || v[j].b==lst.a ||
                    v[j].a==lst.b || v[j].b==lst.b)
                    grp[j]=gcnt, f=1, lst=v[j];
            }
        } while (f);
    }
    int ans=0;
    for (int i=0; i<c; ++i) {
        bitset<mxN> cur;
        for (int j=0; j<n; ++j)
            if (isect(cows[i], far, v[j].a, v[j].b))
                cur^=(1<<grp[j]);
        ans=max(ans, ++cnt[cur]);
    }
    cout << ans << '\n';
}

