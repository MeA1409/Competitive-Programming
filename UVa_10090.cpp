#include <bits/stdc++.h>
using namespace std;

#define int long long

void extendedEucl(int &x, int &y, int &d, int a, int b) {
    if (b == 0) { x = 1; y = 0; d = a; return; }
    extendedEucl(x, y, d, b, a%b);
    int x1 = y;
    int y1 = x - (a / b) * y;
    x = x1;
    y = y1;
}

int cost(int x1, int x2, int c1, int c2) {
    return x1*c1 + x2*c2;    
} 

signed main() {
	int n; 
	while (cin >> n, n > 0) {
	    int c1, n1; cin >> c1 >> n1;
	    int c2, n2; cin >> c2 >> n2;
	    int x, y, d;
	    extendedEucl(x, y, d, n1, n2);
	    if (n % d != 0) cout << "failed\n";
	    else {
	        x *= n/d; y *= n/d; n1 /= d; n2 /= d;
	        int k1 = ceil(-x*1.0/n2); 
	        int k2 = floor(y*1.0/n1); 
	        int cc1 = cost(x + n2*k1, y - n1*k1, c1, c2);
	        int cc2 = cost(x + n2*k2, y - n1*k2, c1, c2);
            if (k1 > k2) {
                cout << "failed\n";
                continue;
            }
            if (cc1 < cc2) 
	            cout << x + n2*k1 << " " << y - n1*k1 << endl;
	        else 
	            cout << x + n2*k2 << " " << y - n1*k2 << endl;
	    }
	}
	return 0;
}
