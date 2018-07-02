#include <bits/stdc++.h>
using namespace std;

typedef vector <int> vi;

int main() {
	int t; cin >> t;
	while (t--) {
	    int m, n; cin >> m >> n;
	    vector <vi> shop(n);
	    for (int i = 0; i < n; i++) {
	        int mi; cin >> mi;
	        for (int j = 0; j < mi; j++) {
	            int x; cin >> x;
	            shop[i].push_back(x);
	        }
	    }

	    vector <vi> dp(n+1, vi(m+1, 0));

	    for (int i = 1; i <= n; i++) {
	        for (int j = 0; j < shop[i-1].size(); j++)
	            for (int k = shop[i-1][j]; k <= m; k++) {
	                if ((i == 1 || dp[i-1][k-shop[i-1][j]] > 0) 
	                    && dp[i-1][k-shop[i-1][j]] + shop[i-1][j] > dp[i][k])
	                
	                dp[i][k] = dp[i-1][k-shop[i-1][j]] + shop[i-1][j];
	            }
	    }
	    if (dp[n][m] == 0) 
	        cout << "no solution\n";
	    else cout << dp[n][m] << endl;
	}
	return 0;
}
