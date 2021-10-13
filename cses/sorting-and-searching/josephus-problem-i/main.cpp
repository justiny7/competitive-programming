#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5 + 69;
int n, nxt[N], prv[N];
 
void del(int &pos) {
    nxt[prv[pos]] = nxt[pos];
    prv[nxt[pos]] = prv[pos];
    pos = nxt[pos];
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n;
    
    for (int i = 1; i <= n; ++i) {
        nxt[i] = i % n + 1;
        prv[i % n + 1] = i;
    }
    
    int pos = 1;
    for (int t = n; t--; ) {
        pos = nxt[pos];
        cout << pos << " \n"[t == 0];
        del(pos);
    }
}
