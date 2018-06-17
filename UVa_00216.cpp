#include <bits/stdc++.h>
using namespace std;

int x[11], y[11];
double dist[11][11];
int t = 1;
int n;

double eDist(int x, int y) {
    return sqrt(x*x + y*y);
}

void solve() {
    int ar[n];
    for (int i = 0; i < n; i++)
        ar[i] = i;
        
    int p[n];
    double an = 1e9;
    do {
        double tmp = 0.0;
        int s = ar[0];
        for (int i = 1; i < n; i++) {
            tmp += dist[s][ar[i]];
            s = ar[i];
        }
        if (tmp < an) {
            an = tmp;
            for (int i = 0; i < n; i++)
                p[i] = ar[i];
        }
    }
    while (next_permutation(ar, ar + n));
    
    cout << "**********************************************************\n";
    cout << "Network #" << t++ << endl;
    for (int i = 0; i < n-1; i++) {
        cout << "Cable requirement to connect (" << x[p[i]] << "," << y[p[i]] << ") to ("
                                                << x[p[i+1]] << "," << y[p[i+1]] << ") ";
        cout << "is " << fixed << setprecision(2) << dist[p[i]][p[i+1]] + 1e-9 << " feet.\n";
    }
    cout << "Number of feet of cable required is " << fixed << setprecision(2) << an + 1e-9 << ".\n";
}

int main() {
    while (cin >> n, n > 0) {
        memset(dist, 0, sizeof(dist));        
    
        for (int i = 0; i < n; i++)
            cin >> x[i] >> y[i];
        
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                dist[i][j] = dist[j][i] = eDist(x[i] - x[j], y[i] - y[j]) + 16.0;
        
        solve();
    }
	return 0;
}
