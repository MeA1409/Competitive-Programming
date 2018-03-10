#include <iostream>
using namespace std;

int main() {
	int a, b, c, d; 
	while (cin >> a >> b >> c >> d, a || b || c || d) {
		int ans = 0;
		ans += (a < b ? 40 - b + a : a - b);
		ans += (b < c ? c - b : 40 - b + c);
		ans += (c < d ? 40 - d + c : c - d);
		ans = ans * 9 + 360 * 3;
		cout << ans << endl;
	}
}
