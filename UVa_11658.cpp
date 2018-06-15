#include <bits/stdc++.h>
using namespace std;

int p[101];
int n, x;
int mem[101][10001];

int min(int a, int b) {
    return a < b? a : b;
}

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int solve(int id, int rem) {
    if (rem < 0)
        return 0;
    if (id >= n) 
        return (int)1e9;
        
    int &g = mem[id][rem];
    if (g != -1) return g;
    
    return g = min(solve(id + 1, rem), p[id] + solve(id + 1, rem - p[id]));
}

int main() {
	ios_base::sync_with_stdio(0);
	while (cin >> n >> x, n || x) {
        for (int i = 0; i < n; i++) {
            double v; cin >> v;
            v = v*100.0;
            // preventing truncation error
            p[i] = (int) (v + 1e-9);
	    }
	    
        swap(p[0], p[x-1]);
        if (p[0] > 5000) {
            cout << "100.00\n";
            continue;
        }
        memset(mem, -1, sizeof(mem));
        int an = p[0] + solve(1, 5000 - p[0]);
        cout << fixed << setprecision(2) << (double)p[0]*100.0/an << endl;
	}
	return 0;
}
