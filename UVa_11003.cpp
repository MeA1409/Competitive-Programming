#include <iostream>
using namespace std;

int min(int a, int b) {
    return a < b? a : b;
}

int main() {
	int n;
	while (cin >> n, n > 0) {
	    int w[n], l[n];
	    int dp[n+1];
	    for (int i = 0; i < n; i++) {
	        cin >> w[i] >> l[i];
	        l[i] += w[i];
	        dp[i+1] = 1 << 30; 
	    }
	    dp[0] = 0;
	    //stacking backwards
	    for (int i = n-1; i >= 0; i--) {
	        //backwards to avoid wrong overwriting
	        for (int j = n; j >= 1; j--) {
	            if (dp[j-1] + w[i] <= l[i])
	                dp[j] = min(dp[j], dp[j-1] + w[i]);
	        }
	    }
	    int an = -1;
	    for (int i = n; i >= 0; i--)
	        if (dp[i] != (1 << 30)) {
	            an = i;
	            break;
	        }
        cout << an << endl;
	}
	return 0;
}
