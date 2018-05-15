#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>

using namespace std;

const long N = (long) INT_MAX + 1; 

int main() {
	  ios_base::sync_with_stdio(0);
    vector <long> sol;
    long pTwo = 1;
    long pThree;
    for (int i = 0; pTwo <= N; i++) {
        pThree = 1;
        for (int j = 0; pTwo*pThree <= N; j++) {
            sol.push_back(pTwo*pThree);
            pThree *= 3;
        }
        pTwo *= 2;
    }
    
    sort(sol.begin(), sol.end());
    long n; 
    while (cin >> n, n > 0) {
        auto x = lower_bound(sol.begin(), sol.end(), n);
        cout << *x << endl;
    }
	  return 0;
}
