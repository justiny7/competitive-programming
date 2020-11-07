#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll=long long;
using pii=pair<int, int>;

ll n, x, a[1001];
vector<pair<ll, pii>> sums;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> x;
    for (int i=0; i<n; ++i)
        cin >> a[i];
    for (int i=0; i<n; ++i)
        for (int j=i+1; j<n; ++j)
            sums.push_back({a[i]+a[j], {i+1, j+1}});
    sort(sums.begin(), sums.end());
    n=sums.size();
    int i=0, j=n-1;
    while (i<j) {
        if (sums[i].fi+sums[j].fi==x) {
            if (sums[i].se.fi!=sums[j].se.fi && sums[i].se.fi!=sums[j].se.se &&
                    sums[i].se.se!=sums[j].se.fi && sums[i].se.se!=sums[j].se.se) {
                cout << sums[i].se.fi << " " << sums[i].se.se << " " <<
                    sums[j].se.fi << " " << sums[j].se.se << '\n';
                return 0;
            }
            --j;
        }
        else if (sums[i].fi+sums[j].fi<x)
            ++i;
        else
            --j;
    }
    cout << "IMPOSSIBLE\n";
}
