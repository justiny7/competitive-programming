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
        string s;
        cin >> n >> s;
        //cout << "s: " <<s <<'\n';
        for (int i=n-2; i>=0; --i) {
            if (s[i]=='1' && s[i+1]=='0') {
                //cout << s << " -- " << '\n';
                if (i+2>=s.length())
                    s.erase(s.begin()+i);
                else if (s[i+2]=='0') {
                    s.erase(s.begin()+i+1);
                    ++i;
                }
                else if (s[i+2]=='1')
                    s.erase(s.begin()+i);
            }
        }
        cout << s << '\n';
    }

    return 0;
}
