#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k, a[200001], ans=0, ansl=0;
        cin >> n >> k;
        vector<int> p(n+1), is(n+1);
        for (int i=0; i<n; ++i)
            cin >> a[i];
        for (int i=1; i<n-1; ++i)
            if (a[i]>a[i-1] && a[i]>a[i+1])
                p[i]++, is[i]++;
        for (int i=1; i<n; ++i)
            p[i]+=p[i-1];
        for (int i=0; i<n; ++i)
            if (p[min(i+k-1, n-1)]-p[i]-is[min(i+k-1, n-1)]-is[i]>ans) {
                ans=p[min(i+k-1, n-1)]-p[i]-is[min(i+k-1, n-1)]-is[i];
                ansl=i;
            }
        cout << ans+1 << " " << ansl+1 << '\n';
    }
}

