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
typedef pair<db, db> pdd;
typedef long long ll;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a, o=0, e=0;
        for (int i=0; i<n; ++i) {
            cin >> a;
            if ((a&1)!=(i&1)) {
                if (a&1)
                    o++;
                else
                    e++;
            }
        }
        if (o==e)
            cout << o << '\n';
        else
            cout << "-1\n";
    }

    return 0;
}
