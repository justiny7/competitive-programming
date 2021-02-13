#include <bits/stdc++.h>
using namespace std;

struct Trie {
    struct node {
        set<int> inds, en;
        node *to[26];
        node() {
            for (int i=0; i<26; ++i)
                to[i]=nullptr;
        }
        int get(char c) {
            return (c-'a');
        }
        void ins(string &x, int v, int pos) {
            inds.insert(v);
            if (pos==x.size()) {
                en.insert(v);
                return;
            }
            int c=get(x[pos]);
            if (!to[c])
                to[c]=new node();
            to[c]->ins(x, v, pos+1);
        }
        void rem(string &x, int v, int pos) {
            inds.erase(v);
            if (pos==x.size()) {
                en.erase(v);
                return;
            }
            int c=get(x[pos]);
            to[c]->rem(x, v, pos+1);
        }
        bool vfind(string &x, int l, int r, int pos) {
            if (en.size()) {
                auto it=en.lower_bound(l);
                if (it!=en.end() && *it<=r)
                    return 1;
            }
            if (pos==x.size())
                return 0;
            int c=get(x[pos]);
            if (!to[c])
                return 0;
            return to[c]->vfind(x, l, r, pos+1);
        }
        bool sfind(string &x, int l, int r, int pos) {
            if (pos==x.size()) {
                if (inds.size()) {
                    auto it=inds.lower_bound(l);
                    if (it!=inds.end() && *it<=r)
                        return 1;
                }
                return 0;
            }
            int c=get(x[pos]);
            if (!to[c])
                return 0;
            return to[c]->sfind(x, l, r, pos+1);
        }
    };

    node *root;
    Trie() {
        root=new node();
    }
    void ins(string &x, int ind) {
        root->ins(x, ind, 0);
    }
    void rem(string &x, int ind) {
        root->rem(x, ind, 0);
    }
    bool vfind(string &x, int l, int r) {
        return root->vfind(x, l, r, 0);
    }
    bool sfind(string &x, int l, int r) {
        return root->sfind(x, l, r, 0);
    }
};

const int mxN=1e5+1;
int n, q;
string s[mxN];
Trie tr;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=1; i<=n; ++i) {
        cin >> s[i];
        tr.ins(s[i], i);
    }
    cin >> q;
    while (q--) {
        int t, l, r; string x;
        cin >> t;
        if (t==1) {
            cin >> l >> x;
            tr.rem(s[l], l);
            tr.ins(s[l]=x, l);
        }
        else if (t==2) {
            cin >> l >> r >> x;
            cout << (tr.vfind(x, l, r)?'Y':'N') << '\n';
        }
        else {
            cin >> l >> r >> x;
            cout << (tr.sfind(x, l, r)?'Y':'N') << '\n';
        }
    }
}

