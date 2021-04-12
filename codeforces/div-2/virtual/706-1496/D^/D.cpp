#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 69;
int n, a[N], dl[N], dr[N], ul[N], ur[N], ml[N], mr[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 2; i <= n; ++i) {
        if (a[i] > a[i - 1])
            ur[i] = ur[i - 1] + 1;
        else
            dr[i] = dr[i - 1] + 1;
    }
    for (int i = n - 1; i; --i) {
        if (a[i] > a[i + 1])
            ul[i] = ul[i + 1] + 1;
        else
            dl[i] = dl[i + 1] + 1;
    }
    for (int i = 2; i <= n; ++i)
        mr[i] = max({mr[i - 1], ur[i], dr[i]});
    for (int i = n - 1; i; --i)
        ml[i] = max({ml[i + 1], ul[i], dl[i]});
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int here = max(ur[i], ul[i]),
            opp = max(mr[i - 1], ml[i + 1]);
        if ((here & 1) || here <= opp)
            continue;
        ans += (min(ur[i], ul[i]) + 1 > here);
    }
    cout << ans << '\n';
}
