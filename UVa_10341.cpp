#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int p, q, r, s, t, u;
	while (cin >> p >> q >> r >> s >> t >> u) {
	    if (p*exp(-1) + q*sin(1) + r*cos(1) + s*tan(1) + t + u > 1e-9 || 
	                                                    p + r + u < 0) {
	        cout << "No solution\n";
	        continue;
	    }
	    double res;
	    double upper = 1.0, 
	           lower = 0.0;
	    double answer;
	    for (int i = 0; i < 30; i++) {
	        answer = (upper + lower) / 2;
	        res = p*exp(-answer) + 
	            q*sin(answer) + 
	            r*cos(answer) + 
	            s*tan(answer) + 
	            t*answer*answer + u;
	        if (res > 0) lower = answer;
	        else upper = answer;
	    }
	    cout << fixed << setprecision(4) << answer << endl;
	}
	return 0;
}
