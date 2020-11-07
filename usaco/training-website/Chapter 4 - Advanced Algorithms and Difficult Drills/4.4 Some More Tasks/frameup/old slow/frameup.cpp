/*
ID: justiny7
LANG: C++
TASK: frameup
*/

//First strategy of working from top-down took too long on the last test case - trying new strat where you see which ones are guaranteed to be on top
//of another and working out possible combinations given those contraints
#include <bits/stdc++.h>
using namespace std;

ifstream fin("frameup.in");
ofstream fout("frameup.out");

int h, w, numf, nx[4] = {0, 1, 0, -1}, ny[4] = {1, 0, -1, 0}, per[27], tb[27], bb[27], lb[27], rb[27];
vector<string> frames, ans;
string alph = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

unordered_map<string, vector<string>> ev, od;

bool dfs(char ch, vector<string> fr) {
    int x, y;
    bool vis[31][31], done = false;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++) {
            vis[i][j] = false;
            if (fr[i][j] == ch && !done) {
                x = j;
                y = i;
                done = true;
            }
        }
    stack<pair<int, int>> st;
    st.push({y, x});
    vis[y][x] = true;
    int counter = 0, ind = ch-'A';
    //cout << ch << '\n' << y << " " << x << '\n';
    while (!st.empty()) {
        int cy = st.top().first, cx = st.top().second;
        st.pop();
        counter++;
        if (counter == per[ind])
            return true;
        for (int i = 0; i < 4; i++) {
            if ((cy+ny[i] >= bb[ind] && cy+ny[i] <= tb[ind] && cx+nx[i] >= lb[ind] && cx+nx[i] <= rb[ind])
                && (cy+ny[i] == tb[ind] || cy+ny[i] == bb[ind] || cx+nx[i] == rb[ind] || cx+nx[i] == lb[ind])
                && (fr[cy+ny[i]][cx+nx[i]] == ch || fr[cy+ny[i]][cx+nx[i]] == '-') && !vis[cy+ny[i]][cx+nx[i]]) {
                st.push({cy+ny[i], cx+nx[i]});
                vis[cy+ny[i]][cx+nx[i]] = true;
                //cout << cy+ny[i] << " " << cx+nx[i] <<  " " << fr[cy+ny[i]][cx+nx[i]] << '\n';
            }
        }
    }
    return false;
}

//uses dfs to find next possible frames (if you can even call it dfs - there's only one neighbor anyway)
string nframes(vector<string> f) {
    string ans;
    bool vis[27];
    int numvis = 0;
    fill(vis, vis+27, false);
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            if (f[i][j] != '.' && f[i][j] != '-' && !vis[f[i][j]-'A']) {
                vis[f[i][j]-'A'] = true;
                numvis++;
                if (dfs(f[i][j], f))
                    ans += f[i][j];
                if (numvis == numf)
                    return ans;
            }
    return ans;
}

//fill frame ch with '-' (wild card letter - can be any)
vector<string> fframe(char ch, vector<string> fr) {
    int x, y;
    bool done = false;
    for (y = 0; y < h; y++) {
        for (x = 0; x < w; x++)
            if (fr[y][x] == ch) {
                done = true;
                break;    
            }
        if (done)
            break;    
    }
    stack<pair<int, int>> st;
    st.push({y, x});
    bool vis[31][31];
    for (int i = 0; i < 31; i++)
        for (int j = 0; j < 31; j++)
            vis[i][j] = false;
    while (!st.empty()) {
        int cx = st.top().second, cy = st.top().first;
        fr[cy][cx] = '-';
        //cout << cx << " " << cy << '\n';
        st.pop();
        for (int i = 0; i < 4; i++)
            if ((cy+ny[i] >= 0 && cy+ny[i] < h) && (cx+nx[i] >= 0 && cx+nx[i] < w)
                && (fr[cy+ny[i]][cx+nx[i]] == ch || fr[cy+ny[i]][cx+nx[i]] == '-')
                && !vis[cy+ny[i]][cx+nx[i]]) {
                st.push({cy+ny[i], cx+nx[i]});
                vis[cy+ny[i]][cx+nx[i]] = true;
            }
    }
    return fr;
}

int main(void) {
    fin >> h >> w;
    frames.resize(h);
    for (int i = 0; i < h; i++)
        fin >> frames[i];
    for (int a = 0; a < 26; a++) {
        tb[a] = rb[a] = -1;
        bb[a] = lb[a] = INT_MAX;
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++) {
                if (frames[i][j] == alph[a]) {
                    tb[a] = max(tb[a], i);
                    bb[a] = min(bb[a], i);
                    lb[a] = min(lb[a], j);
                    rb[a] = max(rb[a], j);
                }
            }
        per[a] = 2*(rb[a]-lb[a]+tb[a]-bb[a]);
        if (rb[a] != -1)
            numf++;
    }
    int lastl = 0;
    queue<string> q;
    q.push("");
    ev[""] = frames;
    while (!q.empty()) { //not sure if this will run in time but at least it (should) stay in mem bounds -_-
        string path = q.front(), a, p2 = path;
        q.pop();
        sort(p2.begin(), p2.end());
        if (path.length() > lastl) {
            if (lastl%2 == 0)
                ev.clear();
            else
                od.clear();
            lastl++;
        }
        vector<string> cur = (path.length()%2 == 0) ? ev[p2] : od[p2];
        a = nframes(cur);
        if (a.length() == 0) {
            reverse(path.begin(), path.end());
            ans.push_back(path);
            continue;
        }
        for (int i = 0; i < a.length(); i++) {
            path += a[i];
            q.push(path);
            p2 = path;
            sort(p2.begin(), p2.end());
            if (path.length()%2 == 0 && ev.find(p2) == ev.end())
                ev[p2] = fframe(a[i], cur);
            else if (od.find(p2) == od.end())
                od[p2] = fframe(a[i], cur);
            path.pop_back();
        }
    }
    sort(ans.begin(), ans.end());
    for (string s : ans)
        fout << s << '\n';
    return 0;
}
