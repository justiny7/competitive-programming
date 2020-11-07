//USACO Silver December 2017 Problem 1

#include <bits/stdc++.h>
#define pb push_back
using namespace std;

ifstream fin("homework.in");
ofstream fout("homework.out");

int n, vals[100001], pref[100001], minval[100001];
double avg, curmax=-1;
vector<int> ans;

int main(void) {
    fin >> n;
    for (int i=1; i<=n; i++) {
        fin >> vals[i];
        pref[i]=vals[i]+pref[i-1];
    }
    minval[n]=vals[n];
    for (int i=n-1; i>0; i--)
        minval[i] = min(minval[i+1], vals[i]);
    for (int k=1; k<=n-2; k++) {
        avg=(double)(pref[n]-pref[k]-minval[k+1])/(n-k-1);
        //cout << k << " " << avg << '\n';
        if (avg>curmax) {
            ans.clear();
            ans.pb(k);
            curmax=avg;
        }
        else if (avg==curmax)
            ans.pb(k);
    }
    for (int a : ans)
        fout << a << '\n';
}
