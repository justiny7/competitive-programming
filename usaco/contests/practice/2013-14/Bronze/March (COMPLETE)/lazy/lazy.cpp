#include <bits/stdc++.h>
using namespace std;

ifstream fin("lazy.in");
ofstream fout("lazy.out");

const int mxN=1e6+1;
int sum, n, k, pref[mxN], ans;
map<int, int> mp;

int main(void) {
    fin >> n >> k;
    for (int i=0; i<n; ++i) {
        int a, b;
        fin >> a >> b;
        mp[b]+=a, sum+=a;
    }
    if (k>mxN/2) {
        fout << sum << '\n';
        return 0;
    }
    for (int i=1; i<mxN; ++i)
        pref[i]=mp[i]+pref[i-1];
    for (int i=1; i<mxN; ++i)
        ans=max(ans, pref[min(mxN-1, i+k)]-pref[max(0, i-k-1)]);
    fout << ans << '\n';
}
