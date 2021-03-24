#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define x first
#define y second
using namespace std;
using namespace __gnu_pbds;
using ll = long long;

template<class t> using oset = tree<t, null_type, less<t>, rb_tree_tag, tree_order_statistics_node_update>;

const int mxN = 2e5 + 1;
int n; ll ans;
pair<int, int> pts[mxN];

void dnc(int l = 0, int r = n - 1) {
    if (l > r)
        return;
    int m = pts[l + r >> 1].x;
    vector<pair<int, int>> here;
    for (int i = l; i <= r; ++i)
        here.push_back(pts[i]);
    sort(here.begin(), here.end(), [](pair<int, int> a, pair<int, int> b) {
        if (a.y == b.y)
            return a.x < b.x;
        return a.y > b.y;
    });
    oset<int> s;
    int lf = -1, rt = -1;
    for (int i = 0; i < here.size(); ++i) {
        pair<int, int> p = here[i];
        s.insert(p.x);
        if (p.x <= m && (lf < 0 || lf < p.x))
            lf = p.x;
        if (p.x >= m && (rt < 0 || rt > p.x))
            rt = p.x;
        if (i == here.size() - 1 || p.y != here[i + 1].y) {
            ll lf_cnt = s.order_of_key(lf + 1),
               lm_cnt = s.order_of_key(m + 1),
               rt_cnt = s.size() - s.order_of_key(rt),
               rm_cnt = s.size() - s.order_of_key(m);
            if (lf < 0)
                ans += rt_cnt * lm_cnt;
            else if (rt < 0)
                ans += lf_cnt * rm_cnt;
            else
                ans += rt_cnt * lm_cnt + lf_cnt * rm_cnt - lf_cnt * rt_cnt;
            lf = rt = -1;
        }
    }
    int nl = r, nr = l;
    for (; pts[nr].x < m; ++nr);
    for (; pts[nl].x > m; --nl);
    dnc(l, nr - 1);
    dnc(nl + 1, r);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> pts[i].x >> pts[i].y;
    sort(pts, pts + n);
    dnc();
    cout << ans << '\n';
}
