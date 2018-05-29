#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int n;
	while (cin >> n, n > 0) {
	    int from[n], to[n];
	    for (int i = 0; i < n; i++)
	        cin >> from[i] >> to[i];
	    sort(from, from + n);
	    sort(to, to + n);
	    int flag = 0;
	    for (int i = 0; i < n; i++)
	        if (from[i] != to[i])
	            flag = 1;
	    if (flag) cout << "NO\n";
	    else cout << "YES\n";
	}
	return 0;
}
