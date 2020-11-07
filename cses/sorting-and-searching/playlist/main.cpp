#include <bits/stdc++.h>
using namespace std;

int n, k[200001], s[200001], ans, l;
map<int, int> seen;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i=0; i<n; ++i)
        cin >> k[i];
    for (int i=0; i<n; ++i) {
        if (seen.find(k[i])==seen.end()) {
            seen[k[i]]=i;
            if (i>0)
                s[i]=s[i-1]+1;
            else
                s[i]=1;
        }
        else {
            l=max(l, seen[k[i]]);
            s[i]=i-l;
            seen[k[i]]=i;
        }
        ans=max(ans, s[i]);
    }
    cout << ans << '\n';
}
