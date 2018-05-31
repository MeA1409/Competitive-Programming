#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int n; 
	while (cin >> n) {
	    vector <int> sol(n);
	    
	    int sum = 0;
	    for (int i = 0; i < n; i++) {
	        cin >> sol[i];
	        sum += sol[i];
	    }
        
        int answ = 1;
        if (sum % n != 0) 
            cout << -1 << endl;
        else {
            sum /= n;
            for (int i = 0; i < n && sol[i] < sum; i++)
                answ += sum - sol[i];
            cout << answ << endl;
        }
	}
	return 0;
}
