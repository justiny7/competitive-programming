#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 40;
int n; ll x, ans, a[N];
vector<ll> v0, v1;
vector<pair<ll, ll>> a0, a1;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> x;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int b0 = n / 2, b1 = n - b0;
    for (int i = 1; i < (1 << b0); ++i) {
        ll here = 0;
        for (int j = 0; j < b0; ++j)
            if (i & (1 << j))
                here += a[j];
        if (here == x)
            ++ans;
        else if (here < x)
            v0.push_back(here);
    }
    for (int i = 1; i < (1 << b1); ++i) {
        ll here = 0;
        for (int j = 0; j < b1; ++j)
            if (i & (1 << j))
                here += a[j + b0];
        if (here == x)
            ++ans;
        else if (here < x)
            v1.push_back(here);
    }
    sort(v0.begin(), v0.end());
    sort(v1.begin(), v1.end());
    if (v0.size()) {
        int c = 1, lst = v0[0];
        for (int i = 1; i < v0.size(); ++i) {
            if (v0[i] == lst)
                ++c;
            else {
                a0.emplace_back(lst, c);
                c = 1, lst = v0[i];
            }
        }
        a0.emplace_back(lst, c);
    }
    if (v1.size()) {
        int c = 1, lst = v1[0];
        for (int i = 1; i < v1.size(); ++i) {
            if (v1[i] == lst)
                ++c;
            else {
                a1.emplace_back(lst, c);
                c = 1, lst = v1[i];
            }
        }
        a1.emplace_back(lst, c);
    }
    for (int i = 0, j = a1.size() - 1; i < a0.size(); ++i) {
        while (j >= 0 && a0[i].first + a1[j].first > x)
            --j;
        if (j >= 0 && a0[i].first + a1[j].first == x)
            ans += a0[i].second * a1[j].second;
    }
    cout << ans << '\n';
}
