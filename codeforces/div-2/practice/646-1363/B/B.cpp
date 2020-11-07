#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n=s.length(), pref[n], ans=INT_MAX;
        fill(pref, pref+n, 0);
        pref[0]=(s[0]=='1');
        for (int i=1; i<n; ++i)
            pref[i]=pref[i-1]+(s[i]=='1');
        if (pref[n-1]==0 || pref[n-1]==n) {
            cout << "0\n";
            continue;
        }
        bool flag=1;
        for (int i=0; i<n; ++i) {
            if (pref[i]==pref[n-1] && pref[i]==i+1) {
                flag=0;
                break;
            }
            if (pref[i]==0 && pref[n-1]==n-i-1) {
                flag=0;
                break;
            }
        }
        if (!flag) {
            cout << "0\n";
            continue;
        }
        //cout << "test:\n";
        for (int i=0; i<n; ++i) {
            //cout << "i: " << i << '\n';
            //cout << i+1-pref[i] << " " << pref[n-1]-pref[i] << '\n';
            //cout << pref[i] << " " << n-i-pref[n-1]+pref[i]-1 << '\n';
            ans=min({ans, (i+1-pref[i]+pref[n-1]-pref[i]), (pref[i]+n-i-pref[n-1]+pref[i]-1)});
        }
        //cout << "testover\n";
        cout << ans << '\n';
    }
}
