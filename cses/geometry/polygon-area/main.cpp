#include <iostream>
#define L std::
#define f for (i=n; i--;)
using l=int64_t;

l n, s, i;

main() {
    L cin >> n;
    l x[n], y[n];
    f L cin >> x[i] >> y[i];
    f s+=x[i]*y[(i+1)%n]-y[i]*x[(i+1)%n];
    L cout << L abs(s);
}

