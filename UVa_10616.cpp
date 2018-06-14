#include <bits/stdc++.h>
using namespace std;

int ar[201];
long ve[201][21][11];
int n, q;
int d, m; 

long sol(int id, int sum, int k) {
    if (k == m) {
        if (sum == 0) return 1;
        return 0;
    }
    if (id >= n) return 0;
    
    if (ve[id][sum][k] != -1) 
        return ve[id][sum][k];
    
    long &memo = ve[id][sum][k];
    long used = sol(id + 1, ((sum + ar[id])%d + d)%d, k+1),
        nused = sol(id + 1, sum, k);
        
    return memo = used + nused;
}

int main() {
    int s = 1;
	  while (cin >> n >> q) {
	    if (n == 0 && q == 0) break;
	    for (int i = 0; i < n; i++)
	        cin >> ar[i];
	    
	    cout << "SET " << s++ << ":\n";
	    for (int i = 0; i < q; i++) {
	        cin >> d >> m;
	        memset(ve, -1, sizeof(ve));
	        cout << "QUERY " << i+1 << ": " << sol(0, 0, 0) << endl;
	    }
	}
	return 0;
}
