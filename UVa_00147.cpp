#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int bill[] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};

int main() {
    ios_base::sync_with_stdio();
    
    vector <long> dp(30001, 0);
    dp[0] = 1;
    for (int i = 0; i < 11; i++)
        for (int j = bill[i]; j <= 30000; j++)
            dp[j] += dp[j-bill[i]];
    
    double n;
    while (cin >> n, n > 0) {
        int x = (int) (n*100.0 + 1e-9);
        cout << fixed << setprecision(2) << right << setw(6) 
            << n << setw(17) << dp[x] << endl;
    }
	return 0;
}
