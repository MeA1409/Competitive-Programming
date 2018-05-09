#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

double cal(vector <int> &sol, double val) {
    double x = sol[0];
    double divi = 1;
    for (int i = 1; i < sol.size(); i++) {
        divi *= (1 + val);
        x += sol[i]/divi;
    }
    return x;
}

int main() {
	ios_base::sync_with_stdio(0);
	int t; 
	while (cin >> t, t > 0) {
	    vector <int> sol(t + 1);
	    for (int i = 0; i <= t; i++)
	        cin >> sol[i];
	        
	    double hi = 10000,
	           lo = -1;
	    double mi;
	    for (int i = 0; i < 31; i++) {
	        mi = (hi + lo) /2;
	        if (cal(sol, mi) < 0)
	            hi = mi;
	        else lo = mi;
	    }   
	    cout << fixed << setprecision(2) << lo << endl;
	}
	return 0;
}
