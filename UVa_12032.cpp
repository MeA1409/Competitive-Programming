#include <iostream>
#include <vector>

using namespace std;

int isPossible(int val, vector <int> &sol) {
    int prev = 0;
    int jump;
    for (int i = 0; i < sol.size(); i++) {
        jump = sol[i] - prev;
        if (jump > val) return 0;
        if (jump == val) val--;
        prev = sol[i];
    }
    return 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	int t; cin >> t;
	for (int i = 1; i <= t; i++) {
	    cout << "Case " << i << ": ";
	    int n; cin >> n;
	    vector <int> sol(n);
	    for (int j = 0; j < n; j++)
	        cin >> sol[j];

	    int hi = (int) 1e7;
	    int lo = 0;
	    for (int j = 0; j < 24; j++) {
	        int mi = (hi + lo)/2;
	        if (isPossible(mi, sol)) 
	            hi = mi;
	        else lo = mi;
	    }
	    cout << hi << endl;
	}
	return 0;
}
