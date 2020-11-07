/*
ID: justiny7
LANG: C++
TASK: starry
*/

//AYYY worked first try
//Update: I realized exceptions to my code (it should find upper-leftmost point, not leftmost-upper point) so I fixed that
#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef pair<int, int> pii;

ifstream fin("starry.in");
ofstream fout("starry.out");

struct cl { //cluster struct
    int sz, lbx = INT_MAX, lby = INT_MIN; //left-bottommost (for 90deg)
    char let; //letter
    vector<pii> pts; //points oriented by left-topmost points in cluster
};

int w, h, curlet;
string alph = "-abcdefghijklmnopqrstuvwxyz";
vector<string> sky;
vector<cl> clusters;

bool check(cl a, cl b) {
    if (a.sz != b.sz)
        return false;
    for (int i = 0; i < a.sz; i++)
        if (a.pts[i].fi != b.pts[i].fi || a.pts[i].se != b.pts[i].se)
            return false;
    return true;
}

cl rot(cl a) { //rotates cluster 90deg clockwise
    //get left-bottommost point in cluster, find relation of every other point to this point, which then maps to (y, x) -> (x, -y)
    cl b;
    vector<pii> newpts;
    int nx = INT_MAX, ny = INT_MIN; //new lbx, new lby
    for (pii p : a.pts) {
        newpts.pb({p.se-a.lbx, a.lby-p.fi});
        if (a.lby-p.fi < nx) {
            nx = a.lby-p.fi;
            ny = p.se-a.lbx;
        }
        else if (a.lby-p.fi == nx)
            ny = max(ny, p.se-a.lbx);
    }
    sort(newpts.begin(), newpts.end());
    b.pts = newpts;
    b.sz = newpts.size();
    b.lby = ny;
    b.lbx = nx;
    return b;
}

cl ref(cl a) { //reflects cluster across vertical line
    cl b;
    vector<pii> newpts;
    int trx = INT_MIN, trY = INT_MAX, nx = INT_MAX, ny = INT_MIN;
    for (pii p : a.pts) {
        if (p.fi < trY) {
            trx = p.se;
            trY = p.fi;
        }
        else if (p.fi == trY)
            trx = max(trx, p.se);
    }
    for (pii p : a.pts) {
        newpts.pb({-1*(trY-p.fi), trx-p.se});
        if (trx-p.se < nx) {
            ny = p.fi-trY;
            nx = trx-p.se;
        }
        else if (trx-p.se == nx)
            ny = max(ny, p.fi-trY);
    }
    sort(newpts.begin(), newpts.end());
    b.pts = newpts;
    b.sz = newpts.size();
    b.lby = ny;
    b.lbx = nx;
    return b;
}

cl bfs(int y, int x) { //to record a shape
    cl clust;
    vector<pii> vp; //vector of points
    queue<pii> q;
    q.push({y, x});
    bool vis[101][101];
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            vis[i][j] = false;
    vis[y][x] = true;
    while (!q.empty()) {
        int cy = q.front().fi, cx = q.front().se;
        vp.pb({cy-y, cx-x});
        if (cx-x < clust.lbx) {
            clust.lby = cy-y;
            clust.lbx = cx-x;
        }
        else if (cx-x == clust.lbx)
            clust.lby = max(clust.lby, cy-y);
        q.pop();
        if (cy > 0 && sky[cy-1][cx] == '1' && !vis[cy-1][cx]) {
            q.push({cy-1, cx});
            vis[cy-1][cx] = true;
        }
        if (cy < h-1 && sky[cy+1][cx] == '1' && !vis[cy+1][cx]) {
            q.push({cy+1, cx});
            vis[cy+1][cx] = true;
        }
        if (cx > 0 && sky[cy][cx-1] == '1' && !vis[cy][cx-1]) {
            q.push({cy, cx-1});
            vis[cy][cx-1] = true;
        }
        if (cx < w-1 && sky[cy][cx+1] == '1' && !vis[cy][cx+1]) {
            q.push({cy, cx+1});
            vis[cy][cx+1] = true;
        }
        if (cy > 0 && cx > 0 && sky[cy-1][cx-1] == '1' && !vis[cy-1][cx-1]) {
            q.push({cy-1, cx-1});
            vis[cy-1][cx-1] = true;
        }
        if (cy < h-1 && cx > 0 && sky[cy+1][cx-1] == '1' && !vis[cy+1][cx-1]) {
            q.push({cy+1, cx-1});
            vis[cy+1][cx-1] = true;
        }
        if (cy > 0 && cx < w-1 && sky[cy-1][cx+1] == '1' && !vis[cy-1][cx+1]) {
            q.push({cy-1, cx+1});
            vis[cy-1][cx+1] = true;
        }
        if (cy < h-1 && cx < w-1 && sky[cy+1][cx+1] == '1' && !vis[cy+1][cx+1]) {
            q.push({cy+1, cx+1});
            vis[cy+1][cx+1] = true;
        }
    }
    sort(vp.begin(), vp.end());
    clust.sz = vp.size();
    clust.pts = vp;
    return clust;
}

char cs(int sy, int sx) { //check to see if shape already exists - if not, create new one
    cl cur = bfs(sy, sx);
    for (cl clus : clusters) {
        for (int i = 0; i < 4; i++) {
            cur = rot(cur);
            if (check(cur, clus))
                return clus.let;
        }
        cur = ref(cur);
        for (int i = 0; i < 4; i++) {
            cur = rot(cur);
            if (check(cur, clus))
                return clus.let;
        }
    }
    cur.let = alph[++curlet];
    clusters.pb(cur);
    return cur.let;
}

void dfs(int y, int x, char let) { //fill shape with char let
    if (sky[y][x] == let)
        return;
    sky[y][x] = let;
    if (y > 0 && sky[y-1][x] == '1')
        dfs(y-1, x, let);
    if (y < h-1 && sky[y+1][x] == '1')
        dfs(y+1, x, let);
    if (x > 0 && sky[y][x-1] == '1')
        dfs(y, x-1, let);
    if (x < w-1 && sky[y][x+1] == '1')
        dfs(y, x+1, let);
    if (y > 0 && x > 0 && sky[y-1][x-1] == '1')
        dfs(y-1, x-1, let);
    if (y < h-1 && x > 0 && sky[y+1][x-1] == '1')
        dfs(y+1, x-1, let);
    if (y > 0 && x < w-1 && sky[y-1][x+1] == '1')
        dfs(y-1, x+1, let);
    if (y < h-1 && x < w-1 && sky[y+1][x+1] == '1')
        dfs(y+1, x+1, let);
}

int main(void) {
    fin >> w >> h;
    sky.resize(h);
    for (int i = 0; i < h; i++)
        fin >> sky[i];
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            if (sky[i][j] == '1')
                dfs(i, j, cs(i, j));
    for (int i = 0; i < h; i++)
        fout << sky[i] << '\n';
    return 0;
}
