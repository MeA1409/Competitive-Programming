#include <iostream>

using namespace std;

int main() {
	int n, m, c;
	int app[22];
	int t = 0;
	
	int tog, max, cur;
	while (cin >> n >> m >> c, n) {
        t++;
		tog = max = cur = 0;
		for (int i = 0; i < n; i++)
			cin >> app[i];

		int idx;
		for (int i = 0; i < m; i++) {
			cin >> idx;
			idx--;
			if (max > c) continue;

			if (tog & (1 << idx))
				cur -= app[idx];
			else {
				cur += app[idx];
				if (cur > max) max = cur;
			}
			tog ^= 1 << idx;
		}

		cout << "Sequence " << t << endl;
		if (max > c) cout << "Fuse was blown.\n\n";
		else cout << "Fuse was not blown.\nMaximal power consumption was " << max << " amperes.\n\n";
	}
}
