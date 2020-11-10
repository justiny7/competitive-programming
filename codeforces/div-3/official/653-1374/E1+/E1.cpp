#include <bits/stdc++.h>
using namespace std;

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

#define ffor(i, a, b) for (int (i)=a; i<b; ++i)
#define rfor(i, a, b) for (int (i)=b-1; i>=a; --i)
#define ff0r(i, a) for (int (i)=0; i<a; ++i)
#define rf0r(i, a) for (int (i)=a-1; i>=0; --i)
#define in(i, x) for (auto& i : x)
#define fitfor(i, x) for (auto i=(x).begin(); i!=(x).end(); ++i)
#define ritfor(i, x) for (auto i=(x).rbegin(); i!=(x).rend(); ++i)

using ll=long long;
using db=double;
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

template<class T> bool ckmin(T& a, const T& b) {return (b<a)?a=b, 1:0;}
template<class T> bool ckmax(T& a, const T& b) {return (a<b)?a=b, 1:0;}

const ll MOD=1e9+7;
const ll MOD2=998244353;
const int kx[]={0,1,0,-1}, ky[]={1,0,-1,0};

void fileIO(string filename) {
    freopen((filename+".in").c_str(), "r", stdin);
    freopen((filename+".out").c_str(), "w", stdout);
}

struct book {
    int t;
    bool a, b;
};

bool cmp(book p, book q) {
    return p.t<q.t;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //fileIO("");
    ll k, n, acnt=0, bcnt=0; cin >> n >> k;
    vector<book> alice, bob, both;
    ff0r(i, n) {
        book temp;
        cin >> temp.t >> temp.a >> temp.b;
        if (!temp.a && !temp.b)
            continue;
        if (temp.a && temp.b) {
            both.pb(temp);
            ++acnt, ++bcnt;
        }
        else if (temp.a) {
            alice.pb(temp);
            ++acnt;
        }
        else {
            bob.pb(temp);
            ++bcnt;
        }
    }
    if (acnt<k || bcnt<k) {
        cout << "-1\n";
        return 0;
    }
    sort(all(alice), cmp);
    sort(all(bob), cmp);
    for (int i=0; i<min(sz(alice), sz(bob)); ++i) {
        book temp={alice[i].t+bob[i].t, 1, 1};
        both.pb(temp);
    }
    sort(all(both), cmp);
    ll ans=0;
    for (int i=0; i<k; ++i)
        ans+=both[i].t;
    cout << ans << '\n';
    cerr << "Time elapsed: " << 1.0*clock()/CLOCKS_PER_SEC << "s\n";
}

