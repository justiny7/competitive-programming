#include <bits/stdc++.h>
using namespace std;

const int N = 4e5 + 69, I = 1e8 + 420;
int n, mx, need, a[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> mx, mx *= 8;
    need = (1 << 31);
    if (mx / n < 31)
        need = (1 << (mx / n));
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    map<int, int> cur;
    //cout << need << '\n';
    int l = 0, r = 0, ans = INT_MAX;
    while (l < n) {
        while (r < n && cur.size() < need)
            ++cur[a[r++]];
        while (r < n && a[r] == a[r - 1])
            ++cur[a[r++]];
        //cout << l << " " << r << '\n';
        ans = min(ans, n - (r - l));
        --cur[a[l]];
        if (cur[a[l]] == 0)
            cur.erase(a[l]);
        ++l;
    }
    cout << ans << '\n';
}
