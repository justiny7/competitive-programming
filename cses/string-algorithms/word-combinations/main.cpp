#include <bits/stdc++.h>
using namespace std;

const int mxN=5e3+1, M=1e9+7;
int n, m, dp[mxN];
string s;
struct node {
    bool en;
    node *to[26];
};
node* make() {
    node *ret=new node();
    for (int i=0; i<26; ++i)
        ret->to[i]=NULL;
    return ret;
}
node *root=make();

void ins(string &x, int pos=0, node *cur=root) {
    if (pos==x.size()) {
        cur->en=1;
        return;
    }
    int c=(x[pos]-'a');
    if (!cur->to[c])
        cur->to[c]=make();
    ins(x, pos+1, cur->to[c]);
}
int go(int pos, node *cur=root) {
    int ret=(cur->en?dp[pos]:0);
    if (pos<n) {
        int c=(s[pos]-'a');
        if (cur->to[c])
            (ret+=go(pos+1, cur->to[c]))%=M;
    }
    return ret;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> s >> m, n=s.size();
    while (m--) {
        string x; cin >> x;
        ins(x);
    }
    dp[n]=1;
    for (int i=n-1; ~i; --i)
        dp[i]=go(i);
    cout << dp[0] << '\n';
}

