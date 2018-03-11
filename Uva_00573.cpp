#include <iostream>

using namespace std;

int main() {
	int h, d, f;
	double u; 
	while (cin >> h >> u >> d >> f, h > 0) {
		double pos = 0.0, rcd = u*(f/100.0);
		int ans = 1;
		pos += u;
		while (pos <= h) {
			pos -= d; u -= rcd;
			if (pos < 0) break;
			if (u > 0) pos += u;
			ans++;
		}
		
		if (pos > h) cout << "success on day ";
		else cout << "failure on day ";
		
		cout << ans << endl;
	}
}
