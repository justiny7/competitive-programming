/*
ID: justiny7
LANG: C++
TASK: theme
*/

//Brute force all 5-n/2 theme lengths? Should run in time...
//It didn't - try condensing themes into single block (linked list?) - themes of size n are guaranteed to have themes of size n-1
//Linked lists won't work (overlaps) - just keep track of their starts and ends in a map or smth
//Hm that was too slow as well - try dynamic programming (new file cuz this one's getting messy)
#include <bits/stdc++.h>
#define fi first
#define se second
#define vec vector
#define pb push_back
#define len length()
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<db, db> pdd;

ifstream fin("theme.in");
ofstream fout("theme.out");

int n, N, notes[5001], ans;
unordered_map<string, pii> themes;
unordered_map<string, vec<int>> newthemes, lastthemes;

string add(string s, int x) {
    if (x < 0)
        s += '-';
    else
        s += '+';
    if (abs(x) < 10)
        s += ' ';
    s.append(to_string(abs(x)));
    return s;
}

int main(void) {
    fin >> n;
    if (n < 10) {
        fout << "0\n";
        return 0;
    }
    int cur, last;
    fin >> last;
    for (int i = 1; i < n; i++) {
        fin >> cur;
        notes[i-1] = cur-last;
        last = cur;
    }
    N = (n%2) ? n-1 : n;
    for (int i = 4; i <= N/2; i++) {
        lastthemes = newthemes;
        newthemes.clear();
        themes.clear();
        string w = ""; //window
        bool found = false;
        if (i == 4) {
            for (int j = 0; j < n-1; j++) {
                w = add(w, notes[j]);
                //cout << w << '\n';
                if (w.len < 3*i)
                    continue;
                themes[w].fi++;
                if (themes[w].fi > 1) {
                    if (themes[w].se < j-i) {
                        ans = i+1;
                        found = true;
                    }
                    if (newthemes[w].empty())
                        newthemes[w].pb(themes[w].se);
                    newthemes[w].pb(j);
                }
                if (themes[w].fi == 1)
                    themes[w].se = j;
                w.erase(0, 3);
            }
        }
        else {
            for (auto p : lastthemes) {
                for (int k = 0; k < p.se.size(); k++) {
                    if (p.se[k]+1 < n-1)
                        w = add(p.fi, notes[p.se[k]+1]);
                    else
                        break;
                    themes[w].fi++;
                    if (themes[w].fi > 1) {
                        if (themes[w].se < p.se[k]+1-i) {
                            ans = i+1;
                            found = true;
                        }
                        if (newthemes[w].empty())
                            newthemes[w].pb(themes[w].se);
                        newthemes[w].pb(p.se[k]+1);
                    }
                    if (themes[w].fi == 1)
                        themes[w].se = p.se[k]+1;
                }
            }
        }
        if (!found)
            break;
    }
    fout << ans << '\n';
    return 0;
}
