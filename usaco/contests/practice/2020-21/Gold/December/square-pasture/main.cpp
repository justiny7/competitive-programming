#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

const int mxN=201;
int n, cnt, ovr;
pair<int, int> a[mxN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n, cnt=n;
    for (int i=0; i<n; ++i)
        cin >> a[i].x >> a[i].y;
    for (int t=0; t<2; ++t) {
        sort(a, a+n);
        for (int i=0; i<n; ++i) {
            for (int j=i+1; j<n; ++j) {
                int tb=max(a[i].y, a[j].y),
                    bb=min(a[i].y, a[j].y),
                    d=a[j].x-a[i].x;
                if (tb-bb>d)
                    continue;
                vector<int> pts;
                for (int k=i; k<=j; ++k)
                    pts.push_back(a[k].y);
                sort(pts.begin(), pts.end());
                int tp=tb, bp=tb-d, dif;
                while (bp<=bb) {
                    auto hi=prev(upper_bound(pts.begin(), pts.end(), tp)),
                         lo=lower_bound(pts.begin(), pts.end(), bp);
                    ++cnt;
                    if (*hi-*lo==d)
                        ++ovr;
                    dif=*lo+1-bp;
                    if (++hi!=pts.end())
                        dif=min(dif, *hi-tp);
                    bp+=dif, tp+=dif;
                }
            }
        }
        for (int i=0; i<n; ++i)
            swap(a[i].x, a[i].y);
    }
    cout << 1+cnt-ovr/2 << '\n';
}

