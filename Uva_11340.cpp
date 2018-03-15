#include <iostream>
#include <string>
#include <iomanip>
#include <map>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
	int t; cin >> t;
	int n, k;
	double ans;
	while (t--) {
	    map <char, double> acc;
	    string line; ans = 0;
	    
	    cin >> n;
	    char c; int p;
	    for (int i = 0; i < n; i++) {
	        cin >> c >> p;
	        acc[c] = p;
	    }
	    cin >> k;
	    cin.ignore();
	    for (int i = 0; i < k; i++) {
	        getline(cin, line);
	        for (char e:line)  
	            if (acc[e]) ans += acc[e];
	    }
	    ans /= 100.0;
        cout << fixed << setprecision(2) << ans << "$\n";
	}
	return 0;
}
