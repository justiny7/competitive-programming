#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;

const int mxN=5e4+1;
const ll M=1e9+7;
int n, m, k, mx, mxn;
ll ans;
vector<int> dep[2][mxN];
vector<ll> tots[mxN], news[mxN], contrib[mxN], news_cpy[mxN], contrib_cpy[mxN];

//bool cmp(const vector<ll> &a, const vector<ll> &b) {
    //return a.size()>b.size();
//}
bool cmp(int a, int b) {
    return contrib[a].size()>contrib[b].size();
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> k;
    for (int t=0; t<k; ++t) {
        cin >> n >> m;
        mxn=max(mxn, n);
        dep[0][t].resize(n+1, -1);
        dep[1][t].resize(n+1, -1);
        vector<int> adj[n+1];
        while (m--) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        queue<pi> q;
        q.emplace(1, 0);
        dep[0][t][1]=0;
        while (q.size()) {
            int v, cd;
            tie(v, cd)=q.front(); q.pop();
            mx=max(mx, dep[cd][t][v]);
            while (news[t].size()<=mx)
                news[t].push_back(0);
            ++news[t][dep[cd][t][v]];
            for (int u:adj[v])
                if (dep[cd^1][t][u]<0)
                    dep[cd^1][t][u]=dep[cd][t][v]+1, q.emplace(u, cd^1);
        }
    }
    //cout << "mx: " << mx << '\n';
    for (int t=0; t<k; ++t) {
        contrib[t].push_back(1);
        for (int i=1; i<news[t].size(); ++i)
            contrib[t].push_back((news[t][i]+(i>1?contrib[t][i-2]:0))%M);
    }
    for (int t=0; t<k; ++t) {
        cout << "t: " << t << '\n';
        for (ll p:news[t])
            cout << p << " ";
        cout << '\n';
        for (ll p:contrib[t])
            cout << p << " ";
        cout << '\n';
    }
    vector<int> inds(k);
    for (int i=0; i<k; ++i) {
        inds[i]=i;
        contrib_cpy[i]=contrib[i];
        news_cpy[i]=news[i];
    }
    sort(inds.begin(), inds.end(), cmp);
    for (int i=0; i<k; ++i) {
        contrib[i]=contrib_cpy[inds[i]];
        news[i]=news_cpy[inds[i]];
    }
    //sort(contrib, contrib+k, cmp);
    //sort(news, news+k, cmp);
    ll st[2]={1,1};
    for (ll t=1; t<=mx; ++t) {
        ll both=st[(t&1)], old=st[(t&1)];
        //cout << t << " " << both << " " << old << '\n';
        for (int i=0; i<k; ++i) {
            if (contrib[i].size()<=t) {
                if (contrib[i].size()+1<=t)
                    break;
                int j=i;
                while (j<k && contrib[j].size()==contrib[i].size()) {
                    ll m2=contrib[j][t-2], m1=contrib[j][t-1];
                    //cout << ">> " << t << " " << m1 << " " << m2 << '\n';
                    if (t&1) {
                        (st[1]*=m2)%=M;
                        (st[0]*=m1)%=M;
                        (both*=(t&1)?m2:m1)%=M;
                        (old*=(t&1)?m2:m1)%=M;
                    }
                    else {
                        (st[0]*=m2)%=M;
                        (st[1]*=m1)%=M;
                        (both*=(t&1)?m1:m2)%=M;
                        (old*=(t&1)?m1:m2)%=M;
                    }
                    ++j;
                }
                break;
            }
            (both*=(contrib[i][t]))%=M;
            (old*=((contrib[i][t]-news[i][t]+M)%M))%=M;
        }
        //cout << t << " " << both << " " << old << " " << both-old << '\n';
        //cout << '\n';
        (ans+=(t*((both-old+M)%M)%M))%=M;
    }
    cout << ans << '\n';
}

