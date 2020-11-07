#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, pref[8001], nums[8001], ans=0;
        bool marked[8001];
        memset(nums, 0, sizeof(nums));
        memset(marked, 0, sizeof(marked));
        set<int> pos;
        cin >> n;
        pref[0]=0;
        for (int i=1; i<=n; ++i) {
            int a;
            cin >> a;
            nums[a]++;
            pref[i]=a+pref[i-1];
        }
        for (int i=0; i<=n; ++i)
            for (int j=i+2; j<=n; ++j)
                if ((pref[j]-pref[i])<=8000 && !marked[pref[j]-pref[i]]) {
                    ans+=nums[pref[j]-pref[i]];
                    marked[pref[j]-pref[i]]=1;
                }
        cout << ans << '\n';
    }
}
