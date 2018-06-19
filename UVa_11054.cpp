#include <iostream>
#include <vector>
using namespace std;

int min(int a, int b) {
    return a < b? a : b;
}

int main() {
	ios_base::sync_with_stdio(0);
	int n; 
	while (cin >> n, n > 0) {
	    vector <long> ar(n);
	    vector <long> x, y;
	    for (int i = 0; i < n; i++) {
	        cin >> ar[i];
	        if (ar[i] > 0) x.push_back(i);
	        else {
	            ar[i] = -ar[i];
	            y.push_back(i);
	        }
	    }
	    
	    int i1 = 0, i2 = 0;
	    long an = 0;
	    while (i1 < x.size() && i2 < y.size()) {
	        int tmp = min(ar[x[i1]], ar[y[i2]]);
	        ar[x[i1]] -= tmp; 
	        ar[y[i2]] -= tmp;
	        an += abs(x[i1] - y[i2])*tmp;
	        if (ar[x[i1]] == 0) i1++;
	        if (ar[y[i2]] == 0) i2++;
	    } 
	    cout << an << endl;
	}
	return 0;
}
