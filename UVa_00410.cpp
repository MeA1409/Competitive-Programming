#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int s, c;
	int t = 1;
	while (cin >> c >> s) {
	    vector <int> sol(s);
	    int x;
	    double avg = 0;
	    for (int i = 0; i < s; i++) {
	        cin >> sol[i];
	        avg += sol[i];
	    }
	    avg = avg*1.0/c;
	    
	    while ((int) sol.size() < 2*c)
	        sol.push_back(0);
	        
	    sort(sol.begin(), sol.end());

	    double imb = 0;
	    cout << "Set #" << t++ << endl;
	    for (int i = 0; i < c; i++) {
	        cout << " " << i << ":";
	        if (sol[i])
	            cout << " " << sol[i];
	        if (sol[2*c - i - 1])
	            cout << " " << sol[2*c - i - 1];
	        
	        imb += abs(sol[i] + sol[2*c - i - 1] - avg);
	        cout << endl;
	    }
	    cout << "IMBALANCE = " << fixed << setprecision(5) << imb << endl;
	    cout << endl;
	}
	return 0;
}
