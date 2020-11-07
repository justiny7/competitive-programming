#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define pb push_back
#define rsz resize
#define ins insert
#define mp make_pair
#define beg(x) x.begin()
#define en(x) x.end()
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()
#define lb lower_bound
#define ub upper_bound
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue

//Some for loop stuff stolen from tmw's template
#define for_base(i, a, b, x) for (int i=((a)<(b))?(a):(a)-1; ((a)<(b))?i<(b):i>=(b); ((a)<(b))?i+=(x):i-=(x))
#define FOR1(a) for_base(i, 0, a, 1)
#define FOR2(i, a) for_base(i, 0, a, 1)
#define FOR3(i, a, b) for_base(i, a, b, 1)
#define FOR4(i, a, b, x) for_base(i, a, b, x)
#define FIFTH(a, b, c, d, e, ...) e
#define FOR(...) FIFTH(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)
#define in(i, x) for (auto& i : x)
#define FIT(i, x) for (auto i=(x).begin(); i!=(x).end(); ++i)
#define RIT(i, x) for (auto i=(x).rbegin(); i!=(x).rend(); ++i)

using ll=long long;
using db=double;
using ld=long double;
using pii=pair<int, int>;
using pll=pair<ll, ll>;
using pdd=pair<db, db>;
using vi=vector<int>;
using vl=vector<ll>;
using vd=vector<db>;
using vs=vector<string>;
using vii=vector<pii>;
using vll=vector<pll>;
using vdd=vector<pdd>;
template<class T> using min_heap=pqueue<T, vector<T>, greater<T>>;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<class T> bool ckmin(T& a, const T& b) {return (b<a)?a=b, 1:0;}
template<class T> bool ckmax(T& a, const T& b) {return (a<b)?a=b, 1:0;}

//Read/write stuff also partially stolen from tmw
template<class T> void read(T& x) {
    cin >> x;
}
template<class H, class T> void read(pair<H, T>& p) {
    cin >> p.fi >> p.se;
}
template<class T> void read(vector<T>& v) {
    in(i, v)
        read(i);
}
template<class T> void read(T a[], int n) {
    FOR(n)
        read(a[i]);
}
template<class H, class... T> void read(H& h, T&... t) {
    read(h);
    read(t...);
}

template<class H, class T> ostream& operator<<(ostream& o, const pair<H, T> &p) {
    o << p.fi << " " << p.se;
    return o;
}
template<class T> ostream& operator<<(ostream& o, vector<T> &v) {
    bool f=0;
    in(i, v) {
        if (f)
            o << " ";
        f=1;
        o << i;
    }
    return o;
}
template<class T> ostream& operator<<(ostream& o, vector<vector<T>> &v) {
    bool f=0;
    in(i, v) {
        if (f)
            o << '\n';
        f=1;
        o << i;
    }
    return o;
}
template<class H, class T> ostream& operator<<(ostream& o, vector<pair<H, T>> &v) {
    bool f=0;
    in(i, v) {
        if (f)
            o << '\n';
        f=1;
        o << i;
    }
    return o;
}

template<class T> void write(T x) {
    cout << x;
}
template<class H, class... T> void write(const H& h, const T&... t) {
    write(h);
    write(t...);
}

void print() {
    write('\n');
}
template<class H, class... T> void print(const H& h, const T&... t) {
    write(h);
    if (sizeof...(t))
        write(' ');
    print(t...);
}

const ll M=1e9+7, M2=998244353;
const int kx[]={0,1,0,-1}, ky[]={1,0,-1,0};

void fileIO(string filename) {
    freopen((filename+".in").c_str(), "r", stdin);
    freopen((filename+".out").c_str(), "w", stdout);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    //fileIO("");
    int t; read(t);
    while (t--) {
        int n; string s;
        read(n, s);
        set<int> zero, one;
        int zcnt=0, ocnt=0;
        FOR(n) {
            if (s[i]=='0')
                zero.ins(i);
            else
                one.ins(i);
        }
        int cur=1, last_pos=-1;
        bool is_zero=(s[0]=='0');
        vector<int> ans(n);
        while (!zero.empty() || !one.empty()) {
            if (is_zero) {
                auto it=zero.ub(last_pos);
                if (it==zero.end()) {
                    ++cur;
                    last_pos=-1;
                    if (!zero.empty())
                        is_zero=(one.empty()?1:(*beg(zero)<*beg(one)?1:0));
                    else
                        is_zero=!is_zero;
                }
                else {
                    ans[*it]=cur;
                    last_pos=*it;
                    zero.erase(it);
                    is_zero=!is_zero;
                }
            }
            else {
                auto it=one.ub(last_pos);
                if (it==one.end()) {
                    ++cur;
                    last_pos=-1;
                    if (!one.empty())
                        is_zero=(zero.empty()?0:(*beg(zero)<*beg(one)?1:0));
                    else
                        is_zero=!is_zero;
                }
                else {
                    ans[*it]=cur;
                    last_pos=*it;
                    one.erase(it);
                    is_zero=!is_zero;
                }
            }
        }
        print(cur);
        print(ans);
    }
    cerr << "Time elapsed: " << 1.0*clock()/CLOCKS_PER_SEC << "s\n";
}


