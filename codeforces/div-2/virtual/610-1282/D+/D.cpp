#include <bits/stdc++.h>
using namespace std;

//Get lengths in 2 queries w/ aa...aa (300) and bb....bb (300)
int n, ac, bc;

int query(string s) {
    cout << s << endl;
    int ret; cin >> ret;
    if (ret <= 0)
        exit(0);
    return ret;
}

int main() {
    //#a + #b = n
    //aa....aa (300) edit distance = (300 - n) deletions + #b replaces = aq
    //aq = 300 - n + #b -> n - #b = 300 - aq = #a
    //aa....aa (n) edit distance = #b replaces
    ac = query(string(300, 'a')), bc = query(string(300, 'b'));
    ac = 300 - ac, bc = 300 - bc;
    n = ac + bc;
    string ret(n, 'a');
    //cout << "CUR: " << bc << '\n';
    for (int i = 0; i < n - 1; ++i) {
        //if you change ret[i] to a b and it increases, then it's an a, otherwise it's b?
        ret[i] = 'b';
        int here = query(ret);
        if (here > bc)
            ret[i] = 'a';
        else
            --bc;
    }
    if (bc)
        ret[n - 1] = 'b';
    query(ret);
    assert(false);
}
