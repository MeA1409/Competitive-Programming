#include <bits/stdc++.h>
using namespace std;

int p[101], f[101];
int memo[101][1101][25];
int n, x, t, k;

int max(int a, int b) {
    return a > b? a : b;
}

int solve(int id, int mrem, int drem) {
    if (drem <= 0 || mrem <= 0 || id >= k) return 0;
    
    int &g = memo[id][mrem][drem];
    if (g != -1) return g;
    
    int a = 0, b = 0, c = 0;
    if (mrem >= 2*p[id] && drem >= 2) 
        a = 2*f[id] + solve(id + 1, mrem - 2*p[id], drem-2);
    if (mrem >= p[id] && drem >= 1)
        b = f[id] + solve(id + 1, mrem - p[id], drem-1);
    c = solve(id + 1, mrem, drem);
    return g = max(c, max(a, b));
}

int main() {
	ios_base::sync_with_stdio(0);
	while (cin >> n >> x >> t >> k, n || x || t || k) {
        n++;
        memset(f, 0, sizeof(f));
        memset(memo, -1, sizeof(memo));
        
        int mmax = floor((double)x*n/1.1 + 1e-9) - t*n; 
        for (int i = 0; i < k; i++) {
            cin >> p[i];
            for (int j = 0; j < n; j++) {
                int utl; cin >> utl;
                f[i] += utl;
            }
        }
        cout << fixed << setprecision(2) << (double)solve(0, mmax, 2*n)/n << endl;;
	}
	return 0;
}
