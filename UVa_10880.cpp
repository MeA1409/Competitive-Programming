#include <iostream>
#include <set>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
	int t, s = 0;
	cin >> t;
	int c, r;
	while (s++ < t) {
	    cout << "Case #" << s << ":";
	    cin >> c >> r;
	    if (c <= r) {
	        if (c == r) cout << " " << 0;
	        cout << endl;
	        continue;
	    }
	    set <int> sol;
	    int num = c - r, i;
	    for (i = 1; i*i < num; i++) {
	        if (num%i == 0) {
	            if (i > r)
	                sol.insert(i);
	            if (num/i > r) 
	                sol.insert(num/i);
	        }
	    }
	    if (i*i == num && i > r) sol.insert(i);
	    set<int>::iterator e;
	    for (e = sol.begin(); e != sol.end(); e++)
	        cout << " " << *e;
	    cout << endl;
	}
	return 0;
}
