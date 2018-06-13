#include <iostream>
#include <vector>
using namespace std;

vector <int> prime;

void sieve() {
    int s[2000] = {0};
    prime.push_back(2);
    for (int i = 3; i <= 1119; i += 2) {
        if (!s[i]) {
            for (int j = i*i, inc = i*2; j <= 1119; j += inc)
                s[j] = 1;
            prime.push_back(i);
        }
    }
}

int dp[1201][15];

void init() {
    dp[0][0] = 1;
    for (int i = 0; i < prime.size(); i++) {
        for (int j = 1200; j >= prime[i]; j--) {
            for (int k = 1; k <= 14; k++)
                dp[j][k] += dp[j-prime[i]][k-1];
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0);
	sieve();
	init();
	int n, k;
	while (cin >> n >> k) {
	    if (n == 0 && k == 0) break;
	    if (n < 0 || k < 0) continue;
	    cout << dp[n][k] << endl;
	}
	return 0;
}
