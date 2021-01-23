//Pretty horrible impl but if it works it works xd
#include <bits/stdc++.h>
using namespace std;
using pi=pair<int, int>;
using ar4=array<int, 4>;
using ar43=array<ar4, 3>;

const int dy[]={1,0,-1,0}, dx[]={0,1,0,-1}, MX=21;
vector<pi> dif[3];

struct box {
    int L, R, U, B;
    box() {}
    box(vector<pi> &a) {
        L=MX, R=-MX, B=MX, U=-MX;
        for (auto p:a) {
            L=min(L, p.first);
            R=max(R, p.first);
            B=min(B, p.second);
            U=max(U, p.second);
        }
    }
    box(const box &o) {
        L=o.L;
        R=o.R;
        U=o.U;
        B=o.B;
    }
    void move(int dir) {
        L+=dx[dir];
        R+=dx[dir];
        B+=dy[dir];
        U+=dy[dir];
    }
    ar4 pos() {
        return {L, R, B, U};
    }
};
struct state {
    vector<box> v;
    ar43 here;
    state(box A, box B, box C) {
        v.push_back(A);
        v.push_back(B);
        v.push_back(C);
        here=get();
    }
    ar43 get() {
        box A=v[0], B=v[1], C=v[2];
        return {sub(A.pos(), B.pos()), sub(B.pos(), C.pos()), sub(C.pos(), A.pos())};
    }
    ar4 sub(ar4 a, ar4 b) {
        ar4 ret;
        for (int i=0; i<4; ++i)
            ret[i]=a[i]-b[i];
        return ret;
    }
    bool operator<(const state &o) const {
        return here<o.here;
    }
    bool separate() {
        for (int t=0; t<3; ++t) {
            for (int k=0; k<3; ++k) {
                if (k==t)
                    continue;
                for (auto p:dif[t]) {
                    int cx=v[t].L+p.first, cy=v[t].B+p.second;
                    if (cx<=v[k].R && cx>=v[k].L && cy<=v[k].U && cy>=v[k].B)
                        return 0;
                }
            }
        }
        return 1;
    }
    bool shift(int i, int dir) {
        set<pi> vis;
        for (int t=0; t<3; ++t) {
            if (t==i)
                continue;
            for (auto p:dif[t])
                vis.emplace(p.first+v[t].L, p.second+v[t].B);
        }
        for (auto p:dif[i]) {
            int cx=v[i].L+p.first+dx[dir], cy=v[i].B+p.second+dy[dir];
            if (vis.count({cx, cy}))
                return 0;
        }
        v[i].move(dir);
        here=get();
        return 1;
    }
};

int n[3];
map<state, int> mp;
queue<state> q;

bool in(state &cur) {
    for (int t=0; t<3; ++t)
        if (cur.v[t].L<-10 || cur.v[t].R>20 || cur.v[t].B<-10 || cur.v[t].U>20)
            return 0;
    return 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n[0] >> n[1] >> n[2];
    box st[3];
    for (int t=0; t<3; ++t) {
        vector<pi> here;
        for (int i=0; i<n[t]; ++i) {
            int x, y;
            cin >> x >> y;
            here.emplace_back(x, y);
        }
        st[t]=box(here);
        for (int i=0; i<n[t]; ++i)
            dif[t].emplace_back(here[i].first-st[t].L, here[i].second-st[t].B);
    }
    state s(st[0], st[1], st[2]);
    mp[s]=0;
    q.push(s);
    while (q.size()) {
        state cur=q.front(); q.pop();
        if (cur.separate()) {
            cout << mp[cur] << '\n';
            return 0;
        }
        for (int dir=0; dir<4; ++dir) {
            for (int t=0; t<3; ++t) {
                state here(cur);
                if (here.shift(t, dir) && in(here) && !mp.count(here)) {
                    mp[here]=mp[cur]+1;
                    q.push(here);
                }
            }
        }
    }
    cout << "-1\n";
}

