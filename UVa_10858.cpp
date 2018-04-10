#include <iostream>
#include <vector>

using namespace std;

void foo(vector <vector <int>> &sol, vector <int> &util, int num, int rem) {
    if (rem == 1) {
        sol.push_back(util);
        return;
    }
    for (int i = num; i <= rem; i++) {
        if (rem%i == 0) {
            vector <int> temp = util;
            temp.push_back(i);
            foo(sol, temp, i, rem/i);
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0);
	int n;
	while (cin >> n, n > 0) {
	    vector < vector <int> > sol;
	    for (int i = 2; i*i <= n; i++) {
	        if (n%i == 0) {
	            vector <int> temp = {i};
	            foo(sol, temp, i, n/i);
	        }
	    }
	    cout << sol.size() << endl;
	    for (int i = 0; i < sol.size(); i++) {
	        cout << sol[i][0];
	        for (int j = 1; j < sol[i].size(); j++)
	            cout << " " << sol[i][j];
	        cout << endl;
	    }
	}
	return 0;
}
