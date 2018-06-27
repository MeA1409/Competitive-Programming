#include <bits/stdc++.h>

using namespace std;

int ar[55];
int n;

int sol() {
    n++;
    int dp[51][51];
    memset(dp, 100, sizeof(dp));
    
    for (int i = 1; i <= n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (i - j == 1)
                dp[j][i] = 0;
            else {
                for (int k = i - 1; k >= j; k--)
                    dp[j][i] = min(dp[j][i], dp[j][k] + dp[k][i] + ar[i] - ar[j]);
            }
        }
    }
    return dp[0][n];
}

int main() {
	  ios_base::sync_with_stdio(0);
    int l; 
    while (cin >> l, l > 0) {
    	cin >> n;
    	ar[0] = 0;
    	for (int i = 1; i <= n; i++) 
	        cin >> ar[i];
	    ar[n+1] = l;
        
	    int an = sol();
    	cout << "The minimum cutting is " << an << ".\n";
	}
	return 0;
}
