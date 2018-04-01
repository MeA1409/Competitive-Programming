#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int n, m;
	while (cin >> n >> m) {
	    int num;
	    map <int, vector<int>> foo;
	    for (int i = 1; i <= n; i++) {
	        cin >> num;
	        foo[num].push_back(i);
	    }
	    int x, k;
	    while (m--) {
	        cin >> k >> x;
	        if ((int) foo[x].size() < k) cout << 0 << endl;
	        else cout << foo[x][k-1] << endl;
	    }
	}
	return 0;
}
