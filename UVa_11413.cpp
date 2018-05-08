#include <iostream>
using namespace std;

int m, n;
int canFill(int capacity, int c[]) {
    int cur = 0;
    int containers = 1;
    for (int i = 0; i < n; i++) {
        if (c[i] > capacity) return 0;
        cur += c[i];
        if (cur > capacity) {
            cur = c[i];
            containers++;
        }
        if (containers > m) return 0;
    }
    return 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	while (cin >> n >> m) {
	    int c[n];
	    for (int i = 0; i < n; i++)
	        cin >> c[i];
	 
	    int hi = (int) 1e9, lo = 0;
        int mi;
	    for (int i = 0; i < 30; i++) {
	        mi = (hi + lo)/2;
	        if (canFill(mi, c) == 1)
	            hi = mi;
	        else
	            lo = mi;
	    }
	    cout << hi << endl;
	}
	return 0;
}
