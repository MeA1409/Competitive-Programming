#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	
	double n;
	while (cin >> n) {
	    if (n == 1 || n == 0) {
	        cout << "MEMBER\n";
	        if (cin.peek() == 'E') break;
	        continue;
	    }
	    int times = 0;
	    int c = 1;
	    
      // set precision to 18 decimals
	    while ((n *= 3.0)) {
	        if (times++ > 18) break;
	        c = (int) n;
	        if (c == 1) {
	            c = -1; break; }
	        n -= c;
	    }
	    if (c == -1) cout << "NON-MEMBER\n";
	    else cout << "MEMBER\n";
	    if (cin.peek() == 'E') break;
	}
	return 0;
}
