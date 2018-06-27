#include <iostream>
using namespace std;

int max(int a, int b) {
    return a > b? a : b;
}

int main() {
    ios_base::sync_with_stdio(0);
    int m, n, t;
    while (cin >> m >> n >> t) {
        int dp[10001] = {0};
        
        for (int i = m; i <= t; i += m) 
            dp[i] = dp[i-m] + 1;

        for (int i = n; i <= t; i++) 
            if (i == n || dp[i-n] > 0) 
                dp[i] = max(dp[i], dp[i-n] + 1);
            
        pair<int, int> an = pair<int, int>(0, 0);
        for (int i = t; i >= 0; i--) {
            if (dp[i] > 0) {
                an.first = dp[i];
                an.second = i;
                break;
            }
        }
        
        cout << an.first;
        if (an.second != t)
            cout << " " << t - an.second;
        cout << endl;
    }
	return 0;
}
