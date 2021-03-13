#include <bits/stdc++.h>
using namespace std;

const int mxN=5e5+1, mxL=20;
int n;
string s;
bool have[1<<mxL];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> s;
    for (int l=1; l<=mxL; ++l) {
        memset(have, 0, sizeof(have));
        int cur=0;
        for (int i=n-1; ~i; --i) {
            cur>>=1;
            if (s[i]=='b')
                cur|=(1<<l-1);
            if (i+l<=n)
                have[cur]=1;
        }
        for (int i=0; i<(1<<l); ++i) {
            if (!have[i]) {
                cout << l << '\n';
                for (int j=l-1; ~j; --j)
                    cout << ((i&(1<<j))?'b':'a');
                cout << '\n';
                return 0;
            }
        }
    }
    assert(false);
}

