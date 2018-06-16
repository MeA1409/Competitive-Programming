#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
	    int n, s; cin >> n >> s;
	    vector <int> A(n), B(n);
	    for (int i = 0; i < n; i++)
	        cin >> A[i] >> B[i];
	    
	    vector <vector <int>> dp(s + 1, vector <int> (s+1, (int)1e9));
	    dp[0][0] = 0;
	    for (int i = 0; i < n; i++) {
	        for (int x = A[i]; x <= s; x++) 
	            for (int y = B[i]; y <= s; y++)
	                dp[x][y] = min(dp[x][y], 1 + dp[x-A[i]][y-B[i]]);
	    } 
	    int res = (int) 1e9;
        for (int x = 0; x <= s; x++)
            for (int y = 0; y <= s; y++)
                if (x*x + y*y == s*s)
                    res = min(res, dp[x][y]);
                    
        if (res == (int) 1e9)  
            cout << "not possible\n";
        else cout << res << endl;
	}
	return 0;
}
