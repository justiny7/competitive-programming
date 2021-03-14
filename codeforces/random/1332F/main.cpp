#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=3e5+1, M=998'244'353;

//{{{ Mint 
struct Mint {
    int val;
    Mint (int _val=0):val(_val) {
        val=(-M<=val && val<M)?val:val%M;
        if (val<0)
            val+=M;
    }
    explicit operator int() const { return val; }
    friend bool operator==(const Mint &a, const Mint &b) { return a.val==b.val; }
    friend bool operator!=(const Mint &a, const Mint &b) { return !(a==b); }
    friend bool operator<(const Mint &a, const Mint &b) { return a.val<b.val; }

    Mint &operator+=(const Mint &o) { if ((val+=o.val)>=M) val-=M; return *this; }
    Mint &operator-=(const Mint &o) { if ((val-=o.val)<0) val+=M; return *this; }
    Mint &operator*=(const Mint &o) { val=static_cast<int>(static_cast<long long>(val)*o.val%M); return *this; }
    Mint &operator/=(const Mint &o) { return (*this)*=inv(o); }

    friend Mint binpow(Mint a, int b) {
        Mint ret(1);
        for (; b; b>>=1, a*=a) if (b&1) ret*=a;
        return ret;
    }
    friend Mint inv(const Mint &a) { return binpow(a, M-2); }

    Mint operator-() { return Mint(-val); }
    Mint operator++() { return (*this)+=1; }
    Mint operator--() { return (*this)-=1; }
    friend Mint operator+(Mint a, const Mint b) { return a+=b; }
    friend Mint operator-(Mint a, const Mint b) { return a-=b; }
    friend Mint operator*(Mint a, const Mint b) { return a*=b; }
    friend Mint operator/(Mint a, const Mint b) { return a/=b; }

    friend ostream &operator<<(ostream &o, const Mint &m) { o << m.val; return o; }
    friend istream &operator>>(istream &i, Mint &m) { int x; i >> x; m.val=x; return i; }
};
//}}}

int n;
Mint ans, dp[mxN][3]; //0: color as 0 | 1: color as 1 | 2: split this node from all of its children
vector<int> adj[mxN];

void dfs(int v=1, int p=0) {
    dp[v][0]=dp[v][1]=dp[v][2]=1;
    for (int u:adj[v]) {
        if (u==p)
            continue;
        dfs(u, v); //Look at edge from v <-> u
        //Splitting the tree at node v is dp[u][0] + dp[u][1] - dp[u][2] because dp[u][0] + dp[u][1] gives total # of sets for subtree u,
        //and subtratcting dp[u][2] gets rid of the cases where we split off the children of u (so we don't have a single node in its own component)
        Mint split=dp[u][0]+dp[u][1]-dp[u][2];
        dp[v][0]*=(dp[u][0]+dp[u][1]+split); //0's can connect with 0's and 1's OR split the edge
        dp[v][1]*=(dp[u][0]+split); //1's can only connect with 0's OR split the edge
        dp[v][2]*=split; //To separate node v from all its children, you can only split all of the edges
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=1; i<n; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs();
    cout << dp[1][0]+dp[1][1]-dp[1][2]-1 << '\n';
}

