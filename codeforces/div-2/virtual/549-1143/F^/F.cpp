#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using ll=long long;
using pll=pair<ll, ll>;

const int mxN=1e5+1;
int n;
pll a[mxN];
vector<pll> hull;

bool ccw(pll p, pll q, pll r) {
    return (p.x*(q.y-r.y)+q.x*(r.y-p.y)+r.x*(p.y-q.y))>=0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    if (n<3)
        return cout << n-1 << '\n', 0;
    for (int i=1; i<=n; ++i)
        cin >> a[i].x >> a[i].y, a[i].y-=a[i].x*a[i].x;
    sort(a+1, a+n+1);
    for (int i=1; i<=n; ++i) {
        while (hull.size()>1 && ccw(hull[hull.size()-2], hull.back(), a[i]))
            hull.pop_back();
        hull.push_back(a[i]);
    }
    cout << hull.size()-(hull[0].x==hull[1].x?2:1) << '\n';
}

