#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5+5;
int n, a[mxN], mins[mxN], pref[mxN];
vector<int> ans;
double avg;

int main() {
    ifstream cin("homework.in");
    ofstream cout("homework.out");
    cin >> n;
    for (int i=1; i<=n; ++i)
        cin >> a[i], pref[i]=a[i]+pref[i-1];
    mins[n]=a[n];
    for (int i=n-1; i; --i)
        mins[i]=min(a[i], mins[i+1]);
    for (int i=1; i<n-1; ++i) {
        double cur=(double)(pref[n]-pref[i]-mins[i+1])/(n-i-1);
        if (cur>avg)
            ans.clear();
        if (cur>=avg)
            ans.push_back(i), avg=cur;
    }
    for (int i:ans)
        cout << i << '\n';
}

