#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int max(int a, int b) {
    return a>b? a : b;
}

int main() {
	ios_base::sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
	    int n; cin >> n;
	    
	    int tol = 0;
	    vector <int> arr(n);
	    for (int i = 0; i < n; i++) {
	        cin >> arr[i];
	        tol += arr[i];
	    }
	    
	    
	    int htol = tol/2;
	    vector < vector <int> > sol(2, vector <int>(htol+1));
	    for (int i = 0; i <= n; i++) {
	        for (int j = 0; j <= htol; j++) {
	            if (i == 0) sol[i][j] = 0;
	            else {
	                if (arr[i-1] > j)
	                    sol[i%2][j] = sol[(i-1)%2][j];
	                else 
	                    sol[i%2][j] = max(sol[(i-1)%2][j], sol[(i-1)%2][j-arr[i-1]] + arr[i-1]);
	            }
	        }
	    }
	    int an = abs(tol - sol[n%2][htol] - sol[n%2][htol]);
	    cout << an << endl;
	}
	return 0;
}
