#include <iostream>
using namespace std;

int main() {
	string mod; int t = 1;
	while (cin >> mod) {
	    cout << "Case " << t++ << ":\n"; 
	    int x; cin >> x;
	    while (x--) {
	        int a, b, c;
	        bool Yes = true;
	        cin >> a >> b;
	        if (a > b) c = a, a = b, b = c;
	        for (int i = a+1; i <= b; i++) {
	            if (mod[i] != mod[a]) {
	                Yes = false; break;
	            }
	        }
	        if (Yes) cout << "Yes\n";
	        else cout << "No\n";
	    }
	}
	return 0;
}
