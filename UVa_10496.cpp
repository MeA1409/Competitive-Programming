#include <bits/stdc++.h>
using namespace std;

int dist[11][11];
int memo[11][1 << 11];
int n;

double eDist(int xx, int yy) {
    return sqrt(xx*xx + yy*yy);
} 

int solve(int x, int mask) {
    if (mask == ((1 << n) - 1))
        return dist[0][x];
    
    if (memo[x][mask] != -1) 
        return memo[x][mask];

    int an = 100000000;
    for (int i = 1; i < n; i++)
        if ((mask&(1 << i)) == 0)
            an = min(an, dist[x][i] + solve(i, mask|(1 << i)));
    
    return memo[x][mask] = an;
}

int main() {
    int t; cin >> t;
    while (t--) {
        memset(dist, 0, sizeof(dist));        
        memset(memo, -1, sizeof(memo));
        
        int R, C; cin >> R >> C;
        
        int x[11], y[11];
        cin >> x[0] >> y[0];
        cin >> n; n++;

        for (int i = 1; i < n; i++)
            cin >> x[i] >> y[i];
        
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                dist[i][j] = dist[j][i] = abs(x[i] - x[j]) + abs(y[i] - y[j]);
        
        cout << "The shortest path has length " << solve(0, 1) << endl;
    }
	return 0;
}
