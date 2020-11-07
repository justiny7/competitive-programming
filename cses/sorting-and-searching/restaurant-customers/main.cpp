#include <bits/stdc++.h>
using namespace std;

int n, cur, ans;
map<int, int> mp;

int main(void) {
    cin >> n;
    for (int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        mp[a]++;
        mp[b]--;
    }
    for (auto p : mp) {
        cur+=p.second;
        ans=max(cur, ans);
    }
    cout << ans << '\n';
}
