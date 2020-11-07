#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const ll d[]={14,1,2,4,7,8,11,13};
ll n;

int main() {
    ifstream cin("moobuzz.in");
    ofstream cout("moobuzz.out");
    cin >> n;
    cout << ((n%8==0)?(n/8-1):(n/8))*15+d[n%8] << '\n';
}

