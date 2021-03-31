#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;
int n, k, a[N];
long long ans;
map<int, int> mp;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int l = 0, r = 0;
    while (l < n) {
        while (r < n) {
            if (mp.size() == k && !mp.count(a[r]))
                break;
            ++mp[a[r++]];
        }
        ans += (long long)(r - l);
        if (--mp[a[l++]] == 0)
            mp.erase(a[l - 1]);
    }
    cout << ans << '\n';
}
