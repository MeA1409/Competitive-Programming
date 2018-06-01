#include <iostream>
using namespace std;

int min(int a, int b) {
    return (a < b)? a : b;
}

int main() {
    ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int l, n; 
        cin >> l >> n;
        int x;
        
        int bestCase = 0, worstCase = 0;
        for (int i = 0; i < n; i++) {
            cin >> x;
            x = min(x, l - x);
            if (x > bestCase)
                bestCase = x;
            if (l - x > worstCase)
                worstCase = l - x;
        }
        cout << bestCase << " " << worstCase << endl;
    }
	return 0;
}
