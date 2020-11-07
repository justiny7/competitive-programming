#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

int main(void) {
    int t;
    cin >> t;
    //cout << t;
    for (int r = 0; r < t; r++) {
        int a, b;
        cin >> a >> b;

		if (a < b) {
			cout << "NO\n";
		}
		else if (a == b) {
			cout << "YES\n";
			for (int i = 0;i<b;i++) {
				cout << "1 ";
			}
		}
		else {
			if (a%2 == 1 && b%2 != 1) {
				cout << "NO\n";
			}
			else if (a%2 == 1 && b%2 == 1) {
				cout << "YES\n";
				for (int i = 0; i < b; i++) {
					if (i < b-1) {
						cout << "1 ";
						a--;
					}
					else {
						cout << a << endl;
					}
				}
			}
			else if (a%2 == 0) {
				if (2*b <= a) {
					cout << "YES\n";
					for (int i = 0; i < b; i++) {
						if (i < b-1) {
							cout << "2 ";
							a-=2;
						}
						else {
							cout << a << endl;
						}
					}
				}
				else if (b%2 == 0) {
					cout << "YES\n";
					for (int i = 0; i < b; i++) {
						if (i < b-1) {
							cout << "1 ";
							a--;
						}
						else {
							cout << a << endl;
						}
					}
				}
				else {
					cout << "NO\n";
				}
			}
		}
    }

    return 0;
}
