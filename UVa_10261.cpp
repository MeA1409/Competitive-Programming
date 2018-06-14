#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int s = 0;
	int t; cin >> t;
	while (t--) {
		if (s++ > 0) cout << endl;
		int l; cin >> l;
		l*= 100;
		vector <int> queue(1, 0), ssum(1, 0);
		int car; 
		while (cin >> car, car > 0) {
			queue.push_back(car);
			ssum.push_back(ssum.back() + car);
		}
		vector <vector <int>> pos(queue.size(), vector <int>(l+1, 0));
		vector <vector <int>> sol(queue.size(), vector <int>(l+1, 0));
		
		pos[0][0] = 1;
		int i, maxl = 0;
		for (i = 1; i < queue.size(); i++) {
			int loadable = 0;
			for (int j = 0; j <= l; j++) {
				if (j - queue[i] >= 0 && pos[i-1][j-queue[i]]) {
					pos[i][j] = 1;
					sol[i][j] = 1; //to left
					loadable = 1;
				}
				if (pos[i-1][j] && ssum[i] - j <= l) {
					pos[i][j] = 1;
					sol[i][j] = 0; //to right
					loadable = 1;
				}
				if (pos[i][j]) maxl = j;
			}
			if (!loadable) break;
		}
		i--;
		cout << i << endl;
		vector <int> ord(i+1, 0);

        while (i > 0) {
            ord[i] = sol[i][maxl];
            if (sol[i][maxl] == 1)
                maxl -= queue[i];
            i-=1;
        }
        
        for (int j = 1; j < ord.size(); j++) {
            if (ord[j] == 0) 
                cout << "starboard\n";
            else cout << "port\n";
        }
	}
	return 0;
}
