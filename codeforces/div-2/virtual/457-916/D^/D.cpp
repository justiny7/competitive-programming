#include <bits/stdc++.h>
using namespace std;

template<class H, class T> struct P_Binary_Trie {
    struct node {
        const T ID=0; //or whatever ID
        T val;
        node *c[2];
        node() {
            c[0]=c[1]=nullptr;
            val=ID;
        }
        node(node *o) {
            c[0]=o->c[0];
            c[1]=o->c[1];
            val=o->val;
        }
        void ins(H x, T v, int pos) {
            if (pos<0) {
                val+=v;
                return;
            }
            bool i=(x&(1LL<<pos));
            c[i]=(c[i])?new node(c[i]):new node();
            c[i]->ins(x, v, pos-1);
            val=ID;
            if (c[0])
                val+=c[0]->val;
            if (c[1])
                val+=c[1]->val;
        }
        T find(H x, int pos) {
            if (pos<0)
                return val;
            bool i=(x&(1LL<<pos));
            T ret=ID;
            if (i && c[!i])
                ret+=c[!i]->val;
            if (!c[i])
                return ret;
            return ret+=c[i]->find(x, pos-1);
        }
    };

    vector<node*> trie;
    P_Binary_Trie() {
        trie.push_back(new node());
    }
    void ins(H x, T val, int v=-1) {
        int ind=(~v?v:trie.size()-1),
            st=(sizeof(x))<<3;
        trie[ind]->ins(x, val, st);
    }
    T find(H x, int v=-1) {
        int ind=(~v?v:trie.size()-1),
            st=(sizeof(x))<<3;
        return trie[ind]->find(x, st);
    }
    void cpy(int v=-1) {
        int ind=(~v?v:trie.size()-1);
        trie.push_back(new node(trie[ind]));
    }
    int sz() {
        return trie.size();
    }
};

template<class T> struct P_Trie {
    struct node {
        const T ID=0; //or whatever ID
        T val;
        node *to[26];
        node() {
            for (int i=0; i<26; ++i)
                to[i]=nullptr;
            val=ID;
        }
        node(node *o) {
            for (int i=0; i<26; ++i)
                to[i]=o->to[i];
            val=o->val;
        }
        int get(char c) {
            return (c-'a'); //or 'A' if capital
        }
        void ins(string &x, T v, int pos) {
            if (pos==x.size()) {
                val=v;
                return;
            }
            int c=get(x[pos]);
            to[c]=(to[c])?new node(to[c]):new node();
            to[c]->ins(x, v, pos+1);
        }
        bool rem(string &x, int pos) {
            if (pos==x.size()) {
                val=ID;
                return 1;
            }
            int c=get(x[pos]);
            if (!to[c])
                return 0;
            to[c]=new node(to[c]);
            return to[c]->rem(x, pos+1);
        }
        T find(string &x, int pos) {
            if (pos==x.size())
                return val;
            int c=get(x[pos]);
            if (!to[c])
                return ID;
            return to[c]->find(x, pos+1);
        }
    };

    vector<node*> trie;
    P_Trie() {
        trie.push_back(new node());
    }
    void ins(string &x, T val, int v=-1) {
        int ind=(~v?v:trie.size()-1);
        trie[ind]->ins(x, val, 0);
    }
    bool rem(string &x, int v=-1) {
        int ind=(~v?v:trie.size()-1);
        return trie[ind]->rem(x, 0);
    }
    T find(string &x, int v=-1) {
        int ind=(~v?v:trie.size()-1);
        return trie[ind]->find(x, 0);
    }
    void cpy(int v=-1) {
        int ind=(~v?v:trie.size()-1);
        trie.push_back(new node(trie[ind]));
    }
    int sz() {
        return trie.size();
    }
};

int main() {
    int q; cin >> q;
    P_Trie<int> trie;
    P_Binary_Trie<int, int> pbt;
    while (q--) {
        string t, s; int x;
        cin >> t;
        if (t=="set") {
            pbt.cpy();
            trie.cpy();
            cin >> s >> x;
            int ID=trie.find(s);
            if (ID) {
                pbt.ins(ID, -1);
                trie.rem(s);
            }
            pbt.ins(x, 1);
            trie.ins(s, x);
        }
        else if (t=="remove") {
            pbt.cpy();
            trie.cpy();
            cin >> s;
            int ID=trie.find(s);
            if (ID) {
                pbt.ins(ID, -1);
                trie.rem(s);
            }
        }
        else if (t=="undo") {
            cin >> x, ++x;
            pbt.cpy(pbt.sz()-x);
            trie.cpy(trie.sz()-x);
        }
        else {
            pbt.cpy();
            trie.cpy();
            cin >> s;
            int ID=trie.find(s);
            if (ID)
                cout << pbt.find(ID-1) << endl;
            else
                cout << -1 << endl;
        }
    }
}

