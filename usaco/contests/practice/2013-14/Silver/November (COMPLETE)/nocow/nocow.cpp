#include <bits/stdc++.h>
#define pb push_back
using namespace std;
//A relatively easy problem that took me wayy too long to debug
ifstream fin("nocow.in");
ofstream fout("nocow.out");

const int mxN=32;
int n, k, num, cnt[mxN], p[mxN], place[mxN];
vector<string> adj[mxN];
vector<string> no;

bool get(int ind, string s) {
    for (string str:adj[ind])
        if (str==s)
            return 1;
    return 0;
}

string build() {
    string ans="";
    for (int i=0; i<n; ++i)
        ans.append(adj[i][place[i]]+" ");
    return ans;
}

int main(void) {
    fin >> num >> k, --k;
    for (int i=0; i<num; ++i) {
        string s, temp="";
        for (int j=0; j<4; ++j)
            fin >> s;
        int j=0;
        fin >> s;
        while (s!="cow.") {
            if (!get(j, s))
                adj[j].pb(s);
            temp.append(s+" "), ++j, fin >> s;
        }
        n=j;
        no.pb(temp);
    }
    sort(no.begin(), no.end());
    for (int i=0; i<n; ++i) {
        sort(adj[i].begin(), adj[i].end());
        cnt[i]=adj[i].size();//, cout << "cnt: " << cnt[i] << '\n';
    }
    p[n]=1;
    for (int i=n-1; i>=0; --i)
        p[i]=cnt[i]*p[i+1];//, cout << i << " " << p[i] << '\n';
    for (int i=0; i<n; ++i)
        place[i]=k/p[i+1], k%=p[i+1];//cout << k << " " << p[i+1] << " " << place[i] << '\n';
    int cur=0;
    while (no[cur++]<=build()) {
        int carry=1;
        for (int i=n-1; i>=0; --i) {
            place[i]+=carry;
            if (place[i]==cnt[i])
                place[i]=0, carry=1;
            else
                carry=0;
        }
        if (cur==num)
            break;
    }
    for (int i=0; i<n; ++i) {
        if (i)
            fout << " ";
        fout << adj[i][place[i]];
    }
    fout << '\n';
}
