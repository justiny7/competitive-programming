#include <bits/stdc++.h>
using namespace std;

const int mxN=501, mxT=5e3+1;
int N, T, a[mxN];
vector<int> dp[mxT];
bool vis[mxN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> T >> N;
    dp[0].push_back(-1);
    for (int i=0; i<N; ++i)
        cin >> a[i];
    for (int i=0; i<N; ++i) {
        for (int j=T; ~j; --j) {
            if (j-a[i]>=0 && dp[j-a[i]].size() && dp[j].size()<dp[j-a[i]].size()+1) {
                dp[j]=dp[j-a[i]];
                dp[j].push_back(i);
            }
        }
    }
    for (int i=T; ~i; --i) {
        if (dp[i].size()) {
            for (int j:dp[i])
                if (~j)
                    vis[j]=1;
            int t0=0, t1=0;
            for (int j=0; j<N; ++j) {
                if (vis[j]) {
                    cout << t0;
                    t0+=a[j];
                }
                else {
                    cout << t1;
                    t1+=a[j];
                }
                cout << " \n"[j==N-1];
            }
            return 0;
        }
    }
}

