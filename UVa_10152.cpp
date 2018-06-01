#include <iostream>
#include <vector>
using namespace std;

int main() {
	  ios_base::sync_with_stdio(0);
	  int t; cin >> t;
    
    string discard;
    getline(cin, discard);
	while (t--) {
	    int n; cin >> n;
	    getline(cin, discard);
    
	    vector <string> ini(n);
	    vector <string> fin(n);
	    
	    for (int i = 0; i < n; i++)
	        getline(cin, ini[i]);
	        
	    for (int i = 0; i < n; i++)
	        getline(cin, fin[i]);

	        
	    int k = 0;
	    int n1 = n-1, n2 = n-1;
	    while (n1 >= 0 && n2 >= 0) {
	        if (ini[n1] == fin[n2]) 
	            n1--, n2--;
	        else 
	            k++, n1--;
	    }
        
        for (int i = k - 1; i >= 0; i--)
            cout << fin[i] << endl;
            
	    cout << endl;
	}
	return 0;
}
