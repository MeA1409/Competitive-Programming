#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int max(int a, int b) {
	return a > b? a : b;
}

int min(int a, int b) {
	return a < b? a : b;
}

enum OP {UP = 0, DOWN};

void Utl(vector <int> &memo, vector <int> &a, int op = UP) {
	int n = memo.size();
	int e = (op == UP)? 1 : -1;
	
	vector <int> Li;
	for (int i = (op == UP)? 0 : n-1; i < n && i >= 0; i += e) {
		int j = lower_bound(Li.begin(), Li.end(), a[i]) - Li.begin();
		if (j < Li.size() && Li[j] == a[i]) {
			memo[i] = 1;
			continue;
		}
		if (j == Li.size()) 
			Li.push_back(a[i]);
		else Li[j] = a[i];
		memo[i] = j + 1;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	int n;
	while (cin >> n) {
		if (n < 0) continue;
		vector <int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		
		vector <int> memoI(n), memoD(n);

		Utl(memoI, a); Utl(memoD, a, DOWN);
		
		int ans = 0;
		for (int i = 0; i < n; i++) 
			ans = max(ans, min(memoD[i]-1, memoI[i]-1)*2 + 1);
		
		cout << ans << endl;
	}
	return 0;
}
