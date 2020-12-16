//Yay worked first try!
#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5+1;
int n, m, cnt, fi[mxN], se[mxN], taken[mxN];

void go(int cow) {
    if (~taken[fi[cow]]) {
        int nxt=taken[fi[cow]];
        if (nxt<cow) {
            if (~taken[se[cow]]) {
                nxt=taken[se[cow]];
                if (nxt<cow)
                    return;
                else {
                    taken[se[cow]]=cow;
                    go(nxt);
                }
            }
            else
                taken[se[cow]]=cow, ++cnt;
        }
        else {
            taken[fi[cow]]=cow;
            go(nxt);
        }
    }
    else
        taken[fi[cow]]=cow, ++cnt;
}

int main() {
    memset(taken, -1, sizeof(taken));
    ifstream cin("cereal.in");
    ofstream cout("cereal.out");
    cin >> n >> m;
    for (int i=0; i<n; ++i)
        cin >> fi[i] >> se[i];
    vector<int> ans;
    for (int i=n-1; ~i; --i)
        go(i), ans.push_back(cnt);
    for (int i=n-1; ~i; --i)
        cout << ans[i] << '\n';
}

