#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int t; cin >> t;
	
	int n;
	for (int k = 1; k <= t; k++) {
	    cin >> n;
	    string line;
	    cin >> line;
	    int answer = 0;
	    for (int i = 0; i < n; i++) {
	        if (line[i] == '#') continue;
	        answer++; i += 2;
	    }
	    cout << "Case " << k << ": " << answer << endl;
	}
	return 0;
}
