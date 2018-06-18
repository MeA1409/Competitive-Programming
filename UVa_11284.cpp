#include <bits/stdc++.h>
using namespace std;

const int inf = (int) 1e9;
int dist[51][51], ar[51];
int memo[13][1 << 13];
int ele[13];
int n, m, q;

// modified TSP
int solve(int s, int mask, int idx) {
    if (mask == ((1 << q) - 1)) 
        return dist[0][s];
    
    if (idx >= 0 && memo[idx][mask] != -1)
        return memo[idx][mask];
        
    int an = dist[0][s];
    for (int i = 0; i < q; i++)
        if (!(mask&(1 << i))) 
            an += ar[ele[i]];


    for (int i = 0; i < q; i++)
        if (!(mask&(1 << i))) 
            an = min(an, dist[s][ele[i]] + solve(ele[i], mask|(1<<i), i));
    
    if (idx == -1) return an;
    return memo[idx][mask] = an;
}

void init() {
    cin >> n >> m;
    n++;
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i != j)
                dist[i][j] = dist[j][i] = inf;
                
    memset(ar, 0, sizeof(ar));
    memset(ele, 0, sizeof(ele));
    memset(memo, -1, sizeof(memo));
}

int main() {
    ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        init();
        while (m--) {
            int u, v;
            cin >> u >> v;
            double _w; cin >> _w;
            int w = (int) (_w*100.0 + 1e-9);
            dist[u][v] = dist[v][u] = min(dist[u][v], w);    
        }
        
        // all pairs shortest paths
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    if (dist[i][j] > dist[i][k] + dist[k][j])
                        dist[i][j] = dist[j][i] = dist[i][k] + dist[k][j];

        int tot = 0;
        cin >> q;
        for (int i = 0; i < q; i++) {
            int u;      cin >> u;
            double _w;  cin >> _w;
            int w = (int) (_w*100.0 + 1e-9);
            ar[u] = w; tot += w;
            ele[i] = u;
        }

        int an = solve(0, 0, -1);
        if(an < tot)
            cout << "Daniel can save " << "$" << fixed << setprecision(2) << (double) (tot - an)/100 << "\n";
        else cout << "Don't leave the house\n";

    }
	return 0;
}
