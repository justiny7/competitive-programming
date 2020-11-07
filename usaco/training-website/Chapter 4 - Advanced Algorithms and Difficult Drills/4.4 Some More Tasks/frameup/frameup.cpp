/*
ID: justiny7
LANG: C++
TASK: frameup
*/

//Old strategy of working top-down took too long on the last test case - trying new strat where you find which frames are guaranteed to be on
//top of another one and work out the possible combinations given those contraints

#include <bits/stdc++.h>
#define pb push_back
using namespace std;

ifstream fin("frameup.in");
ofstream fout("frameup.out");

int h, w, numf, tb[27], bb[27], lb[27], rb[27], lets[27];
bool u[27][27], vis[27];
string alph = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
vector<string> frames, ans;

bool und(int x, int y) { //is a under b? If a character of b rests on the frame of a, then yes
    int a = lets[x], b = lets[y];
    for (int i = lb[a]; i <= rb[a]; i++)
        if (frames[tb[a]][i] == alph[b] || frames[bb[a]][i] == alph[b])
            return true;
    for (int i = bb[a]; i <= tb[a]; i++)
        if (frames[i][lb[a]] == alph[b] || frames[i][rb[a]] == alph[b])
            return true;
    return false;
}

bool works(int ind, string p) { //checks to see if all the frames under frame ind is already present in path p
    int c1 = 0, c2 = 0;
    for (int i = 0; i < numf; i++)
        if (u[i][ind]) {
            c1++;
            for (int j = 0; j < p.length(); j++)
                if (alph[lets[i]] == p[j]) {
                    c2++;
                    break;
                }
        }
    return (c1 == c2);
}

void make(string path) { //recursively generates all possible combinations using DFS
    if (path.length() == numf) {
        ans.pb(path);
        return;
    }
    for (int i = 0; i < numf; i++) {
        if (!vis[i] && works(i, path)) {
            vis[i] = true;
            path += alph[lets[i]];
            make(path);
            path.pop_back();
            vis[i] = false;
        }
    }
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
        if (rb[a] != -1)
            lets[numf++] = a;
    }
    for (int i = 0; i < numf; i++)
        for (int j = 0; j < numf; j++)
            if (i != j)
                u[i][j] = und(i, j);
    make("");
    sort(ans.begin(), ans.end());
    for (string s : ans)
        fout << s << '\n';
    return 0;
}
