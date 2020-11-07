/*
ID: justiny7
LANG: C++11
TASK: window
*/

//YESS worked first try - onto Chapter 5.4  xd
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
using db=double;

struct window {
    char id;
    int x1, y1, x2, y2;
    window() {}
    window(char e,int a,int b,int c,int d) {
        id=e;
        x1=min(a, c); x2=max(a, c);
        y1=min(b, d); y2=max(b, d);
    }
};

vector<window> cur;
string s;
int a,b,c,d;
char t, e;

int get_area(int i,int l,int b,int r,int u) {
    while (i<cur.size() &&
        (cur[i].x1>=r || cur[i].x2<=l || cur[i].y1>=u || cur[i].y2<=b))
        ++i;
    //cout << "i: " << i << '\n';
    //cout << l << " " << b << " " << r << " " << u << '\n';
    if (i==cur.size())
        return ((r-l)*(u-b));
    int nl=min(r, cur[i].x2),
        nb=min(u, cur[i].y2),
        nr=max(l, cur[i].x1),
        nu=max(b, cur[i].y1),
        sum=0;
    //cout << cur[i].x1 << " " << cur[i].y1 << " " << cur[i].x2 << " " <<cur[i].y2 << '\n';
    //cout << nl << " " << nb << " " <<nr << " " << nu << '\n';
    if (l<cur[i].x1)
        sum+=get_area(i+1, l, b, nr, u), l=max(l, nr);
    if (r>cur[i].x2)
        sum+=get_area(i+1, nl, b, r, u), r=min(r, nl);
    if (b<cur[i].y1)
        sum+=get_area(i+1, l, b, r, nu);
    if (u>cur[i].y2)
        sum+=get_area(i+1, l, nb, r, u);
    return sum;
}

void print() {
    for (int i=0; i<cur.size(); ++i)
        cout << i+1 << ": " << cur[i].id << '\n';
    cout << '\n';
}

int main() {
    freopen("window.in", "r", stdin);
    freopen("window.out", "w", stdout);
    while (cin >> s) {
        if (s[0]=='w') {
            sscanf(s.c_str(), "%c(%c,%d,%d,%d,%d)",&t,&e,&a,&b,&c,&d);
            cur.pb(window(e, a, b, c, d));
        }
        else {
            char targ=s[2]; int i=0;
            window w;
            for (; i<cur.size(); ++i)
                if (cur[i].id==targ) {
                    w=cur[i];
                    break;
                }
            if (s[0]=='s') {
                if (i==cur.size()-1)
                    cout << "100.000\n";
                else {
                    int blocked=get_area(i+1, cur[i].x1, cur[i].y1, cur[i].x2, cur[i].y2),
                        area=(cur[i].x2-cur[i].x1)*(cur[i].y2-cur[i].y1);
                    //cout << blocked << " " << area << '\n';
                    cout << fixed << setprecision(3) << (db)(((db)blocked/(db)area)*100) << '\n';
                }
                continue;
            }
            cur.erase(cur.begin()+i);
            if (s[0]=='t')
                cur.pb(w);
            else if (s[0]=='b')
                cur.insert(cur.begin(), w);
        }
        //print();
    }
}

