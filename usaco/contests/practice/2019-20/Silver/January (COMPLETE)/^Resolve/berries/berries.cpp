#include <bits/stdc++.h>
using namespace std;

const int mxN=1e3+1;
int n, k, a[mxN], sz[mxN], ans;

int main() {
    ifstream cin("berries.in");
    ofstream cout("berries.out");
    cin >> n >> k;
    for (int i=0; i<n; ++i)
        cin >> a[i];
    for (int i=1; i<mxN; ++i) {
        memset(sz, 0, sizeof(sz));
        for (int j=0; j<n; ++j) {
            sz[i]+=a[j]/i;
            ++sz[a[j]%i];
        }
        int cur=k, tot=0;
        for (int j=i; j>=1 && cur; --j) {
            while (cur && sz[j]) {
                --sz[j], --cur;
                if (cur<k/2)
                    tot+=j;
            }
        }
        ans=max(ans, tot);
    }
    cout << ans << '\n';
}

