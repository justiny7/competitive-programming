#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> a(n);
    int cnt[4]={};
    for (int i=0; i<n; ++i) {
        int a; cin >> a;
        ++cnt[a];
    }
    sort(cnt+1, cnt+4);
    cout << cnt[1]+cnt[2] << '\n';
}

