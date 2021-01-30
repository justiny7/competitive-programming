#include <bits/stdc++.h>
using namespace std;

const int mxN=2e4+1;
int n, ans[mxN];
map<int, int> pos[5];

bool cmp(int a, int b) {
    int cnt=0;
    for (int i=0; i<5; ++i)
        cnt+=(pos[i][a]<pos[i][b]);
    return (cnt>=3);
}

int main() {
    cin >> n;
    for (int t=0; t<5; ++t) {
        for (int i=0; i<n; ++i) {
            int x; cin >> x;
            pos[t][x]=i;
        }
        if (!t) {
            int c=0;
            for (auto p:pos[t])
                ans[c++]=p.first;
        }
    }
    sort(ans, ans+n, cmp);
    for (int i=0; i<n; ++i)
        cout << ans[i] << '\n';
}

