#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

//Utilities
#define fi first
#define se second
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define finish(...) return void(print(__VA_ARGS__))

//Loops
#define IN(i, x) for (auto &(i):(x))
#define FIT(i, x) for (auto (i)=(x).begin(); (i)!=(x).end(); ++(i))
#define RIT(i, x) for (auto (i)=(x).rbegin(); (i)!=(x).rend(); ++(i))

//Data types/structures
using ll=long long;
using db=double;
using ld=long double;

using pii=pair<int, int>;
using pll=pair<ll, ll>;
using pdd=pair<db, db>;

using vi=vector<int>;
using vl=vector<ll>;
using vd=vector<db>;
using vb=vector<bool>;
using vs=vector<string>;

using vii=vector<pii>;
using vll=vector<pll>;
using vdd=vector<pdd>;

template<class T> using pqueue=priority_queue<T>;
template<class T> using mqueue=priority_queue<T, vector<T>, greater<T>>;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//Input
template<class T> void read(T &x) { cin >> x; }
template<class H, class T> void read(pair<H, T> &p) { cin >> p.fi >> p.se; }
template<class T, size_t S> void read(array<T, S> &a) { IN(i, a) read(i); }

template<class T> void read(vector<T> &v) { IN(i, v) read(i); }
template<class H, class... T> void read(H &h, T &...t) { read(h); read(t...); }

//Output
template<class H, class T> ostream &operator<<(ostream &o, pair<H, T> &p) { o << p.fi << " " << p.se; return o; }
template<class T, size_t S> ostream &operator<<(ostream &o, array<T, S> &a) { string s; IN(i, a) o << s << i, s=" "; return o; }

template<class H, class T> ostream &operator<<(ostream &o, vector<pair<H, T>> &v) { string s; IN(i, v) o << s << i, s="\n"; return o; }
template<class T, size_t S> ostream &operator<<(ostream &o, vector<array<T, S>> &v) { string s; IN(i, v) o << s << i, s="\n"; return o; }
template<class T> ostream &operator<<(ostream &o, vector<T> &v) { string s; IN(i, v) o << s << i, s=" "; return o; }
template<class T> ostream &operator<<(ostream &o, vector<vector<T>> &v) { string s; IN(i, v) o << s << i, s="\n"; return o; }

template<class T> void write(T x) { cout << x; }
template<class H, class... T> void write(const H &h, const T &...t) { write(h); write(t...); }

void print() { write('\n'); }
template<class H, class... T> void print(const H &h, const T &...t) { write(h); if (sizeof...(t)) write(' '); print(t...); }

//More utilities
template<class T> bool ckmin(T &a, const T &b) { return (b<a?a=b, 1:0); }
template<class T> bool ckmax(T &a, const T &b) { return (a<b?a=b, 1:0); }

//Constants
const ll M=1e9+7; //998244353;
const int dx[]={0,1,0,-1}, dy[]={1,0,-1,0};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*

    | 00 | 01 | 10 | 11
 ----------------------
 00 |  0 |  1 |  1 |  0
 01 |  1 |  0 |  0 |  1
 10 |  1 |  0 |  0 |  1
 11 |  0 |  1 |  1 |  0

*/

void solve() {
    int n; read(n);
    vii a(n); read(a);
    IN(p, a) {
        p.fi+=1e6;
        p.se+=1e6;
    }
    vector<vi> parities(4); //00 (0) -> even even, 01 (1) -> even odd, 10 (2) -> odd even, 11 (3) -> odd odd
    if (n==2) {
        print(1);
        print(1);
        return;
    }
    while (1) {
        for (int i=0; i<n; ++i) {
            pii p=a[i];
            int c1=(p.fi&1), c2=(p.se&1);
            //print(p, ":", c1, c2, "->", c1*2+c2);
            parities[c1*2+c2].eb(i);
        }
        bool f=0;
        for (int i=0; i<4; ++i) {
            if (parities[i].size()==n)
                f=1;
        }
        if (f) {
            for (int i=0; i<4; ++i)
                parities[i].clear();
            IN(p, a)
                p.fi/=2, p.se/=2;
        }
        else
            break;
    }
    if ((parities[0].size() || parities[3].size()) && (parities[1].size() || parities[2].size())) {
        print(parities[0].size()+parities[3].size());
        IN(i, parities[0])
            write(i+1, ' ');
        IN(i, parities[3])
            write(i+1, ' ');
        print();
    }
    else if (parities[0].size() || parities[3].size()) {
        assert(parities[0].size() && parities[3].size());
        print(parities[0].size());
        IN(i, parities[0])
            write(i+1, ' ');
        print();
    }
    else {
        assert(parities[1].size() && parities[2].size());
        print(parities[1].size());
        IN(i, parities[1])
            write(i+1, ' ');
        print();
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    //int t; read(t);
    //while (t--)
        solve();
    cerr << "Time elapsed: " << 1.0*clock()/CLOCKS_PER_SEC << "s\n";
}

