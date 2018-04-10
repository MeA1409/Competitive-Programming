#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define LEFT 0
#define RIGHT 1

int main() {
  ios_base::sync_with_stdio(0);
	int s; cin >> s;
	while (s--) {
	    int l, c;
	    cin >> l >> c;
	    vector <queue<int>> bank(2);
	    int times = 0;
	    int cl; string pos;
	    for (int i = 0; i < c; i++) {
	        cin >> cl >> pos;
	        if (pos[0] == 'l') bank[LEFT].push(cl);
	        else if (pos[0] == 'r') bank[RIGHT].push(cl);
	    }
	    
	    l*=100;
	    int cur = LEFT;
	    
	    while (!(bank[LEFT].empty() && bank[RIGHT].empty())) {
	        int i = 0;
	        while (!bank[cur].empty()) {
	            i += bank[cur].front();
	            if (i > l) break;
	            bank[cur].pop();
	        }
	        times++; cur ^= 1;
	    }
	    cout << times << endl;
	}
	return 0;
}
