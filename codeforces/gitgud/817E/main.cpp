#include <bits/stdc++.h>
using namespace std;

struct node {
    node *c[2];
    int sz;
    node() {
        c[0]=c[1]=NULL;
        sz=0;
    }
};
node *root;
void ins(int x, node *cur=root, int bit=31) {
    if (bit<0)
        return;
    int r=bool(x&(1<<bit));
    if (!cur->c[r])
        cur->c[r]=new node();
    ++cur->c[r]->sz;
    ins(x, cur->c[r], bit-1);
}
void del(int x, node *cur=root, int bit=31) {
    if (bit<0)
        return;
    int r=bool(x&(1<<bit));
    del(x, cur->c[r], bit-1);
    if (!--cur->c[r]->sz) {
        delete cur->c[r];
        cur->c[r]=NULL;
    }
}
int query(int p, int l, node *cur=root, int bit=31) {
    if (!cur || bit<0)
        return 0;
    int r=bool(p&(1<<bit)), ans=0;
    if (l&(1<<bit)) {
        ans+=query(p, l, cur->c[!r], bit-1);
        if (cur->c[r])
            ans+=cur->c[r]->sz;
    }
    else
        ans+=query(p, l, cur->c[r], bit-1);
    return ans;
}

string s;
void print(node *cur=root) {
    if (!cur->c[0] && !cur->c[1]) {
        cout << s << '\n';
        return;
    }
    for (int i=0; i<2; ++i)
        if (bool(cur->c[i])) {
            s+='0'+i;
            print(cur->c[i]);
            s.pop_back();
        }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int q; cin >> q;
    root=new node();
    while (q--) {
        int t, p, l;
        cin >> t >> p;
        if (t==1)
            ins(p);
        else if (t==2)
            del(p);
        else {
            cin >> l;
            cout << query(p, l) << '\n';
        }
        //print();
        //cout << '\n';
    }
}
