#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=50, src=45, snk=47;

bool ok[1001];
array<int, 4> mp[mxN];
string mp2[mxN];
vector<int> v[50], mine, departure;
ll ans=1;

//Global variables required: src, snk, mxN
struct Edge {
    ll v, flow, c, rev;
};
struct DINIC {
    int lvl[mxN], start[mxN];
    vector<Edge> adj[mxN];

    void add(int u, int v, ll cap) {
        Edge a{v, 0, cap, (int)adj[v].size()};
        Edge b{u, 0, 0, (int)adj[u].size()};
        adj[u].push_back(a);
        adj[v].push_back(b);
    }
    bool bfs() {
        memset(lvl, -1, sizeof(lvl));
        lvl[src]=0;
        queue<int> q;
        q.push(src);
        while (q.size()) {
            int t=q.front(); q.pop();
            for (Edge &u:adj[t])
                if (lvl[u.v]<0 && u.flow<u.c)
                    lvl[u.v]=lvl[t]+1, q.push(u.v);
        }
        return (~lvl[snk]);
    }
    ll go(int cur, ll flo) {
        if (cur==snk)
            return flo;
        while (start[cur]<adj[cur].size()) {
            Edge &e=adj[cur][start[cur]];
            if (lvl[e.v]==lvl[cur]+1 && e.flow<e.c) {
                ll tflo=go(e.v, min(flo, e.c-e.flow));
                if (tflo>0) {
                    e.flow+=tflo, adj[e.v][e.rev].flow-=tflo;
                    return tflo;
                }
            }
            ++start[cur];
        }
        return 0;
    }
    ll dinic() {
        ll ret=0;
        while (bfs()) {
            memset(start, 0, sizeof(start));
            while (ll f=go(src, 1e18))
                ret+=f;
        }
        return ret;
    }
};

int main() {
    freopen("test.txt", "r", stdin);
    string s;
    {
        int c=0;
        while (1) {
            getline(cin, s);
            if (s.empty())
                break;
            stringstream ss(s);
            string nums, name;
            int a=0, b=0, i=0;
            while (ss >> nums) {
                if (nums[0]>='0' && nums[0]<='9')
                    break;
                else
                    name+=nums;
            }
            for (; nums[i]^'-'; ++i)
                a=a*10+(nums[i]-'0');
            for (++i; i<nums.size(); ++i)
                b=b*10+(nums[i]-'0');
            for (int t=a; t<=b; ++t)
                ok[t]=1;
            mp[c][0]=a, mp[c][1]=b;
            ss >> nums >> nums;
            for (a=b=i=0; nums[i]^'-'; ++i)
                a=a*10+(nums[i]-'0');
            for (++i; i<nums.size(); ++i)
                b=b*10+(nums[i]-'0');
            for (int t=a; t<=b; ++t)
                ok[t]=1;
            mp[c][2]=a, mp[c][3]=b;
            mp2[c++]=name;
        }
    }
    {
        while (1) {
            getline(cin, s);
            if (s.empty())
                break;
            if (s=="your ticket:")
                continue;
            vector<int> here;
            int cur=0, c=0, f=1;
            for (int i=0; i<s.size(); ++i) {
                if (s[i]==',')
                    f&=ok[cur], v[c++].push_back(cur), cur=0;
                else
                    cur=cur*10+(s[i]-'0');
            }
            if (ok[cur])
                v[c++].push_back(cur);
            if (!f)
                for (int i=0; i<20; ++i)
                    v[i].pop_back();
            for (int i=0; i<20; ++i)
                mine.push_back(v[i].back());
        }
    }
    {
        while (1) {
            getline(cin, s);
            if (s.empty())
                break;
            if (s=="nearby tickets:")
                continue;
            vector<int> here;
            int cur=0, c=0, f=1;
            for (int i=0; i<s.size(); ++i) {
                if (s[i]==',')
                    f&=ok[cur], v[c++].push_back(cur), cur=0;
                else
                    cur=cur*10+(s[i]-'0');
            }
            if (ok[cur])
                v[c++].push_back(cur);
            if (!f)
                for (int i=0; i<20; ++i)
                    v[i].pop_back();
        }
    }
    DINIC g;
    for (int i=0; i<20; ++i) {
        g.add(src, i, 1);
        g.add(i+20, snk, 1);
        for (int j=0; j<20; ++j) {
            bool f=1;
            for (int k:v[j])
                f&=((k>=mp[i][0] && k<=mp[i][1]) || (k>=mp[i][2] && k<=mp[i][3]));
            if (f)
                g.add(j, i+20, 1);
        }
    }
    assert(g.dinic()==20);
    vector<int> departure;
    for (int i=0; i<20; ++i) {
        for (auto e:g.adj[i])
            if (e.flow==1) {
                if (mp2[e.v-20].substr(0, 9)=="departure")
                    departure.push_back(i);
                break;
            }
    }
    for (int i:departure)
        ans*=mine[i];
    cout << ans << '\n';
}

