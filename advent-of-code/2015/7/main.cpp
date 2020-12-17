#include <bits/stdc++.h>
using namespace std;

const int mxN=1<<16;
const string ops[]={
    "AND",
    "NOT",
    "LSHIFT",
    "RSHIFT",
    "OR"
};
struct op {
    int val=-1;
    string type, s1, s2;
};
map<string, int> memo;
map<string, op> mp;

inline int complement(int x) {
    bitset<16> ret(x);
    for (int i=0; i<16; ++i)
        ret.flip(i);
    return (int)ret.to_ulong();
}
int do_op(string node) {
    //if (node=="b")             part 2
        //return memo[node]=956; part 2
    if (memo.count(node))
        return memo[node];
    op cur=mp[node];
    if (cur.type.empty()) {
        if (~cur.val)
            return memo[node]=cur.val;
        return memo[node]=do_op(cur.s1);
    }
    if (cur.type=="AND") {
        if (~cur.val)
            return memo[node]=(do_op(cur.s1))&cur.val;
        return memo[node]=(do_op(cur.s1))&(do_op(cur.s2));
    }
    if (cur.type=="OR") {
        if (~cur.val)
            return memo[node]=(do_op(cur.s1))&cur.val;
        return memo[node]=(do_op(cur.s1))|(do_op(cur.s2));
    }
    if (cur.type=="LSHIFT")
        return memo[node]=(do_op(cur.s1))<<cur.val;
    if (cur.type=="RSHIFT")
        return memo[node]=(do_op(cur.s1))>>cur.val;
    else
        return memo[node]=complement(do_op(cur.s1));
}

int main() {
    freopen("test.txt", "r", stdin);
    string s;
    while (1) {
        getline(cin, s);
        if (s.empty())
            break;
        stringstream ss(s);
        string cur;
        op here;
        while (ss >> cur) {
            for (string o:ops)
                if (cur==o) {
                    here.type=cur;
                    ss >> cur;
                    continue;
                }
            if (cur=="->") {
                ss >> cur;
                mp[cur]=here;
                break;
            }
            if (cur[0]>='0' && cur[0]<='9') {
                int ret=0;
                for (char c:cur)
                    ret=ret*10+(c-'0');
                here.val=ret;
            }
            else {
                if (here.s1.empty())
                    here.s1=cur;
                else
                    here.s2=cur;
            }
        }
    }
    cout << do_op("a") << '\n';
}

