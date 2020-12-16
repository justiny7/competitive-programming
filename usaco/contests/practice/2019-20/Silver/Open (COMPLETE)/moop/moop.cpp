//Yay worked first try
#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using pii=pair<int, int>;

const int mxN=1e5+1;
int n;
pii a[mxN];
stack<int> st;

int main() {
    ifstream cin("moop.in");
    ofstream cout("moop.out");
    cin >> n;
    for (int i=0; i<n; ++i)
        cin >> a[i].x >> a[i].y;
    sort(a, a+n);
    st.push(INT_MAX);
    for (int i=0; i<n; ++i) {
        if (st.top()<=a[i].y) {
            int c=st.top();
            while (st.top()<=a[i].y)
                st.pop();
            st.push(c);
        }
        else
            st.push(a[i].y);
    }
    cout << st.size()-1 << '\n';
}

