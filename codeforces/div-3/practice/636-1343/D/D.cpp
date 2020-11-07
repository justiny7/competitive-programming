#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k, a[200001], ans=1e9+5;
        cin >> n >> k;
        vector<int> freq(2*k+2), cnt(2*k+2);
        for (int i=0; i<n; ++i)
            cin >> a[i];
        for (int i=0; i*2<n; ++i) {
            freq[a[i]+a[n-i-1]]++;
            cnt[min(a[i], a[n-i-1])+1]++;
            cnt[max(a[i], a[n-i-1])+k+1]--;
        }
        for (int i=1; i<2*k+2; ++i)
            cnt[i]+=cnt[i-1];
        for (int i=2; i<2*k+1; ++i)
            ans=min(ans, cnt[i]-freq[i]+n-2*cnt[i]);
        cout << ans << '\n';
    } 
}

