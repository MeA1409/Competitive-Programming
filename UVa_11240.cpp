#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
	    int n; cin >> n;
	    int prev; cin >> prev;
	    int an = 1; 
	    for (int i = 1, e = 1; i < n; i++) {
	        int cur; cin >> cur;
	        if (e&1) {
	            if (cur < prev)
	                an++, e^=1;
	        }
	        else { 
	            if (cur > prev) 
	                an++, e^=1;
	        }
	        prev = cur;
	    }
	    cout << an << endl;
	}
	return 0;
}
