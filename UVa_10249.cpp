#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(0);
	int m, n;
	while (cin >> m >> n, m || n) {
	    vector <int> team(m);
	    vector <pii> table(n);

	    for (int i = 0; i < m; i++)
	        cin >> team[i];
	    
	    for (int i = 0; i < n; i++) {
	        int cap; cin >> cap;
	        table[i] = pii(cap, i+1);
	    }
	    sort(table.rbegin(), table.rend());
	    vector <int> sol[m];
        for (int i = 0; i < n; i++) {
            int cap = table[i].first;
            int num = table[i].second;
            for (int j = 0; j < m; j++) {
                if (cap == 0) break;
                if (team[j] == 0) continue;
                cap--; team[j]--;
                sol[j].push_back(num);
            } 
        }
        int pos = 0;
        for (int i = 0; i < m; i++)
            pos |= team[i];
        if (pos) cout << 0 << endl;
        else {
            cout << 1 << endl;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < sol[i].size(); j++) {
                    if (j != 0) cout << " " << sol[i][j];
                    else cout << sol[i][j];
                }
                cout << endl;
            }
        }
	}
	return 0;
}
