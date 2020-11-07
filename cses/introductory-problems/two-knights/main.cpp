#include <iostream>
using namespace std;

int n;

int main(void) {
    cin >> n;
    for (int i=1; i<=n; i++) {
        if (i==1)
            cout << "0\n";
        else if (i==2)
            cout << "6\n";
        else if (i==3)
            cout << "28\n";
        else if (i==4)
            cout << "96\n";
        else {
            long long sq=i*i;
            cout << ((long long)(4*(sq-3)+8*(sq-4)+4*(sq-5)+4*(i-4)*(sq-5)+4*(i-4)*(sq-7)+(i-4)*(i-4)*(sq-9)))/2 << '\n';
        }
    }
}
