#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5+1;
int n, c, pre[mxN], in[mxN], pos[mxN];

void go(int l=0, int r=n-1) {
    if (l>r)
        return;
    int i=pos[pre[c++]];
    go(l, i-1);
    go(i+1, r);
    cout << in[i] << " ";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=0; i<n; ++i)
        cin >> pre[i];
    for (int i=0; i<n; ++i)
        cin >> in[i], pos[in[i]]=i;
    go();
    cout << '\n';
}
