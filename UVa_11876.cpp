#include <iostream>
#include <algorithm>

using namespace std;

const int N = (int) 1e6 + 7;
int sieve[N];
int prime[N];
int size = 0;

int sol[N];

int NOD(int n) {
    int ans = 1;
    
    for (int i = 0; i < size && prime[i]*prime[i] <= n; i++) {
        if (n % prime[i] == 0) {
            int cnt = 1;
            while (n % prime[i] == 0)
                n /= prime[i], cnt++;
            ans *= cnt;
        }    
    }
    if (n != 1) ans *= 2;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    for (int i = 2; i < 1050; i++) {
        if (!sieve[i]) {
            for (int j = i*2; j < 1050; j += i) 
                sieve[j] = 1;
            prime[size++] = i;
        }
    }
    
    sol[0] = 1;
    size = 0;
    for (int i = 1; ; i++) {
        sol[i] = sol[i-1] + NOD(sol[i-1]);
        if (sol[size++] >= N) break;
    }
    
    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        int l, r;
        cin >> l >> r;
        auto x = lower_bound(sol, sol + size, l);
        auto y = upper_bound(sol, sol + size, r);
        cout << "Case " << i << ": " << y - x << endl;
    }
	  return 0;
}
