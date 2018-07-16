#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, -1, 0, 1};


int main() {
	int row, col;
	while (cin >> row >> col) {
	    int sol[row][col];
	    memset(sol, -1, sizeof(sol));
	    int r; cin >> r;
	    
	    map <pii, map<pii, int>> rstct;
	    map <pii, map<int, int>> obs;
	    while (r--) {
	        int i1, j1, i2, j2;
	        cin >> i1 >> j1 >> i2 >> j2;
	        rstct[pii(i1, j1)][pii(i2, j2)] = 1;
	    }
	    
	    int m; cin >> m;
	    while (m--) {
	        int t;
	        int i, j; cin >> t >> i >> j;
            obs[pii(i, j)][t] = 1;
	    }
	    
	    queue<pair<pii, int>> Q;
	    Q.push(make_pair(pii(0, 0), 0));
	    sol[0][0] = 0; obs[pii(0, 0)][0] = 0;
	    
	    while (!Q.empty()) {
	        auto utl = Q.front(); Q.pop();
	        int x = utl.first.first;
	        int y = utl.first.second;
	        if (obs[utl.first][sol[x][y]] == 1) {
	            sol[x][y]++;
	            Q.push(make_pair(utl.first, sol[x][y]));
	            continue;
	        }
	        
	        for (int s = 0; s < 4; s++) {
	            int nx = x + dx[s];
	            int ny = y + dy[s];
	            if (nx < row && nx >= 0 && ny < col && ny >= 0) {
	                if (!rstct[utl.first][pii(nx, ny)] && sol[nx][ny] == -1) {
	                    sol[nx][ny] = sol[x][y] + 1;
	                    Q.push(make_pair(pii(nx, ny), sol[nx][ny]));
	                }
	            }
	        }
	    }
	    cout << sol[row-1][col-1] << endl;
	}
	return 0;
}
