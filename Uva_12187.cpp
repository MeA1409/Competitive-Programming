#include <iostream>
#include <vector>

using namespace std;

typedef vector <int> vi;

int n, r, c, k;
int dx[] = {-1, 0, 1, 0},
    dy[] = {0, 1, 0, -1};
    
void aftermath(vector <vi> &counties) {
    vector <vi> util = counties;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int z = (util[i][j]+1)%n;
            for (int k = 0; k < 4; k++) {
                int x = i+dx[k];
                int y = j+dy[k];
                if (x >= 0 && x < r && 
                    y >= 0 && y < c && 
                    util[x][y] == z) 
                    counties[x][y] = util[i][j];
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    while (cin >> n >> r >> c >> k, n || r || c || k) {
        vector <vi> counties(r, vi(c));
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                cin >> counties[i][j];
            
        while (k--) 
            aftermath(counties);
        
        for (int i = 0; i < r; i++) { 
            for (int j = 0; j < c; j++) {
                if (j != 0) cout << " ";
                cout << counties[i][j];
            }
            cout << endl;
        }
    }
}
