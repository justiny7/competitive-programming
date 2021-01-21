#include <bits/stdc++.h>
using namespace std;

template<class T> struct PST {
    struct node {
        int lb, rb;
        T val;
        node *l, *r;
        inline T comb(T a, T b) {
            return min(a, b);
        }
        inline void app(T &v, T x) {
            v=x;
        }
        node(int lb, int rb, vector<T> &a):lb(lb), rb(rb) {
            if (lb==rb) {
                l=r=NULL;
                val=a[lb];
                return;
            }
            int m=lb+rb>>1;
            l=new node(lb, m, a);
            r=new node(m+1, rb, a);
            val=comb(l->val, r->val);
        }
        node(int lb, int rb, T x):lb(lb), rb(rb), val(x) {
            if (lb==rb) {
                l=r=NULL;
                return;
            }
            int m=lb+rb>>1;
            l=new node(lb, m, x);
            r=new node(m+1, rb, x);
        }
        node(node *o) {
            lb=o->lb;
            rb=o->rb;
            val=o->val;
            l=o->l;
            r=o->r;
        }
        void upd(int i, T x) {
            if (lb==rb) {
                app(val, x);
                return;
            }
            int m=lb+rb>>1;
            if (i<=m) {
                l=new node(l);
                l->upd(i, x);
            }
            else {
                r=new node(r);
                r->upd(i, x);
            }
            val=comb(l->val, r->val);
        }
        T query(int lq, int rq, T ID) {
            if (rb<lq || lb>rq)
                return ID;
            if (lb>=lq && rb<=rq)
                return val;
            return comb(l->query(lq, rq, ID), r->query(lq, rq, ID));
        }
    };

    const T ID=INT_MAX;
    vector<node*> t;
    PST(vector<T> &a) {
        t.push_back(new node(0, a.size()-1, a));
    }
    PST(int SZ) {
        t.push_back(new node(0, SZ-1, ID));
    }
    T query(int lq, int rq, int v=-1) {
        int ind=(~v?v:t.size()-1);
        return (t[ind]->query(lq, rq, ID));
    }
    void upd(int i, T x, int v=-1) {
        int ind=(~v?v:t.size()-1);
        t[ind]->upd(i, x);
    }
    void cpy(int v=-1) {
        int ind=(~v?v:t.size()-1);
        t.push_back(new node(t[ind]));
    }
};

const int mxN=1e5+1;
int n, r, t, q, lst, mxD, a[mxN], in[mxN], out[mxN], dep[mxN];
vector<int> adj[mxN], qu[mxN];

void dfs(int v=r, int p=0, int d=1) {
    in[v]=t++;
    dep[v]=d;
    mxD=max(mxD, d);
    qu[d].push_back(v);
    for (int u:adj[v])
        if (u^p)
            dfs(u, v, d+1);
    out[v]=t;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> r;
    for (int i=1; i<=n; ++i)
        cin >> a[i];
    for (int i=1; i<n; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs();
    PST<int> pst(n+1);
    for (int i=1; i<=mxD; ++i) {
        pst.cpy();
        for (int v:qu[i])
            pst.upd(in[v], a[v]);
    }
    cin >> q;
    while (q--) {
        int p, q, x, k;
        cin >> p >> q;
        x=(p+lst)%n+1, k=(q+lst)%n;
        cout << (lst=pst.query(in[x], out[x]-1, min(mxD, dep[x]+k))) << '\n';
    }
}

