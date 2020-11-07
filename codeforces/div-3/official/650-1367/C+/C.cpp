#include <bits/stdc++.h>
#define fi first
#define se second
#define vec vector
#define pb push_back
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<db, db> pdd;typedef long long ll;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k, ans=0;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> v;
        for (int i=0; i<n; ++i)
            if (s[i]=='1')
                v.pb(i);
        if (v.size()>0 && v[0]!=0)
            ans+=(v[0]/(k+1));
        for (int i=1; i<v.size(); ++i) {
            if (v[i]-v[i-1]-1>=2*k+1) {
                ans+=(v[i]-v[i-1]-k-1)/(k+1);
            }
        }
        if (v.size()>0 && n-v[v.size()-1])
            ans+=(n-v[v.size()-1]-1)/(k+1);
        if (v.size()==0) {
            if (n>k+1) {
                if (n%(k+1)==0)
                    cout << n/(k+1) << '\n';
                else
                    cout << n/(k+1)+1 << '\n';
            }
            else
                cout << "1\n";
        }
        if (v.size()>0)
            cout << ans << '\n';
    }

    return 0;
}
