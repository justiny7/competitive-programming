//Persistent segtree largely stolen from fishy15
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
using ll=long long;

struct node {
    ll l, r, sum;
    node *c[2];
    node(int l, int r, ll sum=0):l(l), r(r), sum(sum) {
        if (l==r) {
            c[0]=c[1]=NULL;
            return;
        }
        int m=l+r>>1;
        c[0]=new node(l, m);
        c[1]=new node(m+1, r);
    }
    node(node *o) {
        l=o->l;
        r=o->r;
        sum=o->sum;
        c[0]=o->c[0];
        c[1]=o->c[1];
    }
    void upd(int i, ll x) {
        if (l==r) {
            this->sum=x;
            return;
        }
        int m=l+r>>1, r=(i>m);
        c[r]=new node(c[r]);
        c[r]->upd(i, x);
        this->sum=c[0]->sum+c[1]->sum;
    }
    ll query(int lb, int rb) {
        if (r<lb || l>rb)
            return 0;
        if (l>=lb &&  r<=rb)
            return sum;
        return c[0]->query(lb, rb)+c[1]->query(lb, rb);
    }
};

int n, q;
vector<node*> t;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    t.pb(new node(1, n));
    for (int i=1; i<=n; ++i) {
        int a; cin >> a;
        t[0]->upd(i, a);
    }
    while (q--) {
        int p, k;
        cin >> p >> k, --k;
        if (p==1) {
            int i, x;
            cin >> i >> x;
            t[k]->upd(i, x);
        }
        else if (p==2) {
            int l, r;
            cin >> l >> r;
            cout << t[k]->query(l, r) << '\n';
        }
        else
            t.pb(new node(t[k]));
    }
}

