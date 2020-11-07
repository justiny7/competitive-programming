#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;

		if (y>x) { //makes x always greater than y
			int temp = x;
			x = y;
			y = temp;
		}
		int movesPer = (max(a, b) / min(a, b));
		//cout << movesPer;

		int dif = x - y;
		unsigned long long int money = 0;
		if (movesPer==1) {
			//cout << "1\n";
			money += (long long int) b*y + (long long int)a*dif;
		}
		else {
			if (a>b) {
				//cout << "2\n";
				money += (long long int) b*y + (long long int)a*dif;
				//cout << (long long int)a*dif << endl;
			}
			else {
				money += (long long int) a*(x+y);
				//cout << "1\n";
			}
		}
		cout << money << endl;

	}

	return 0;
}