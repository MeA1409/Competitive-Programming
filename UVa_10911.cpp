#include <bits/stdc++.h>
using namespace std;

const int N = 8; 
double memo[1 << (2*N)];
double dist[2*N][2*N];
int n, target;

double matching(int mask) {
    if (memo[mask] > -1.0)
        return memo[mask];
    if (mask == target)
        return memo[mask] = 0;
        
    double res = 1e9;
    int p1, p2;
    for (p1 = 0; p1 < 2*n; p1++)
        if (!(mask&(1 << p1))) 
            break;
    for (p2 = p1 + 1; p2 < 2*n; p2++)
        if (!(mask&(1 << p2)))
            res = min(res, dist[p1][p2] + matching(mask | (1 << p1) | (1 << p2)));
    return memo[mask] = res;
}

double hypo(int x, int y) {
    return sqrt(x*x + y*y);
}

int main() {
    ios_base::sync_with_stdio(0);
    int t = 0;
    while (cin >> n, n > 0) {
        cout << "Case " << ++t << ": ";
        string name; 
        int x[2*n], y[2*n];
        for (int i = 0; i < 2*n; i++) {
            cin >> name;
            cin >> x[i] >> y[i];
        }
        for (int i = 0; i < 2*n - 1; i++) 
            for (int j = i + 1; j < 2*n; j++)
                dist[i][j] = dist[j][i] = hypo(x[i] - x[j], y[i] - y[j]);
                
        memset(memo, -1.0, sizeof(memo));
        target = (1 << (2*n)) - 1;
        cout << fixed << setprecision(2) << matching(0) << endl;
    }
	return 0;
}
