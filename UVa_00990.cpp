#include <iostream>
#include <vector>
using namespace std;

int max(int a, int b) {
    return a > b? a : b;
}

int main() {
	ios_base::sync_with_stdio(0);
	
	int t, w; 
	int k = 0;
	while(cin >> t >> w) {
	    if (k++ > 0) cout << endl;
	    int n; cin >> n;
	    vector <int> mat(t+1, 0);
	    vector <int> d(n), c(n), f(n);
	    for (int i = 0; i < n; i++) {
	        cin >> d[i] >> c[i];
	        f[i] = 3*w*d[i];
	    }
        
        vector <vector <int>> memo(n, vector <int>(t+1, 0));
	    for (int i = 0; i < n; i++) {
	        for (int j = t; j >= f[i]; j--) {
	            if (mat[j-f[i]] + c[i] > mat[j]) {
	                mat[j] = mat[j-f[i]] + c[i];
	                memo[i][j] = 1;
	            }
	        }
	    }

	    cout << mat[t] << endl;
	    vector <pair<int, int>> sol;
	    for (int i = n-1; i >= 0; i--) {
	        if (memo[i][t] == 1) {
	            sol.push_back(make_pair(d[i], c[i]));
	            t -= f[i];
	        }
	    }
	
    	cout << sol.size() << endl;
	    for (int i = sol.size()-1; i >= 0; i--)
	        cout << sol[i].first << " " << sol[i].second << endl;
	}
	return 0;
}
