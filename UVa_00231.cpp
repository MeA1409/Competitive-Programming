#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int inf = (int) 1e9;

int main() {
	ios_base::sync_with_stdio(0);
	int n; int t = 1;
	while (cin >> n, n != -1) {
		if (t > 1) cout << endl;
		
		vector <int> ar;
		do {
			ar.push_back(n); 
			cin >> n;
		} while (n != -1);
		
		int N = ar.size();
		int res = 1;
		vector <int> li(N, inf);
		li[0] = ar[N - 1];
		for (int i = N - 2, j; i >= 0; i--) {
			j = upper_bound(li.begin(), li.end(), ar[i]) - li.begin();
			li[j] = ar[i];
			if (j + 1 > res) 
				res = j + 1;
		}
		cout << "Test #" << t++ << ":\n";
		cout << "  maximum possible interceptions: " << res << endl;
	}
	return 0;
}
