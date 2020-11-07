#include <bits/stdc++.h>
#define x first
#define m first
#define y second
#define b second
using namespace std;
using ll=long long;
using pll=pair<ll, ll>;
using line=pair<pll, pll>;

const int mxN=1e3+1;
int n;
pll p[mxN];
map<pll, ll> mp;
set<line> v;

inline ll gcd(ll p, ll q) {
    return (q?gcd(q, p%q):p);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=0; i<n; ++i)
        cin >> p[i].x >> p[i].y;
    for (int i=0; i<n; ++i)
        for (int j=i+1; j<n; ++j) {
            ll dy=p[j].y-p[i].y, dx=p[j].x-p[i].x;
            if (dx) {
                ll GCD=gcd(dy, dx);
                pll cm(dy/GCD, dx/GCD);
                ll buf=p[i].y*dx-p[i].x*dy;
                GCD=gcd(buf, dx);
                pll cb(buf/GCD, dx/GCD);
                v.insert(line{cm, cb});
            }
            else
                v.insert(line{pll(1, 0), pll(0, p[i].x)});
        }
    for (auto l:v)
        ++mp[l.m];
    ll par=0, sz=v.size();
    for (auto p:mp)
        par+=p.y*(p.y-1)/2;
    cout << sz*(sz-1)/2-par << '\n';
}

