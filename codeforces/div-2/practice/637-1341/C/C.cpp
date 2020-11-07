#include <bits/stdc++.h>
#define fi first
#define se second 
using namespace std;
using pii=pair<int, int>;

pii a[100001];

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        bool f=0;
        cin >> n;
        for (int i=0; i<n; ++i) {
            cin >> a[i].fi;
            a[i].se=i+1;
        }
        sort(a, a+n);
        int cmin=a[0].se, cmax=n;
        for (int i=0; i<n-1; ++i) {
            if (a[i].se!=cmax && a[i+1].se!=a[i].se+1) {
                f=1;
                break;
            }
            else if (a[i].se==cmax) {
                cmax=cmin-1;
                cmin=a[i+1].se;
            }
        }
        if (f)
            cout << "No\n";
        else
            cout << "Yes\n";
    }
}
