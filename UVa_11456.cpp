#include <iostream>
#include <vector>
using namespace std;

int utl(vector <int> &sol, int start) {
    int n = sol.size();
    vector <int> inc, dec;
    for (int i = start; i < n; i++) {
        if (sol[i] < sol[start]) continue;
        int j1 = lower_bound(inc.begin(), inc.end(), sol[i]) - inc.begin();
        if (j1 == inc.size())       inc.push_back(sol[i]);
        else if (inc[j1] != sol[i]) inc[j1] =     sol[i];
    }
    
    for (int i = n - 1; i >= start; i--) {
        if (sol[i] > sol[start]) continue;
        int j2 = lower_bound(dec.begin(), dec.end(), sol[i]) - dec.begin();
        if (j2 == dec.size())           dec.push_back(sol[i]);
        else if (dec[j2] != sol[i]) dec[j2] =     sol[i];
    }
    return inc.size() + dec.size() - 1;
}

int max(int a, int b) {
    return a > b? a : b;
}

int main() {
	ios_base::sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
	    int n; cin >> n;
	    vector <int> sol(n);
	    for (int i = 0; i < n; i++) 
	        cin >> sol[i];
	    
	    int ans = 0;
	    for (int i = 0; i < n; i++)
	        ans = max(ans, utl(sol, i));
	    cout << ans << endl;
	}
	return 0;
}
