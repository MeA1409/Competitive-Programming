#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> pii;

void compress(vector <int> &axis) {
    set <int> S(axis.begin(), axis.end());
    map <int, int> M;
    int idx = 1;
    for (auto &e : S)
        M[e] = idx*2, idx++;
    for (int i = 0; i < axis.size(); i++)
        axis[i] = M[axis[i]];
}

void swap(int &a, int &b) {
    if (a <= b) return;
    int t = a; a = b; b = t;
}

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};
void bfs(int r, int c, vector <vector <int>> &mat, int y, int x, int color) {
    queue <pii> Q; Q.push(pii(y, x)); 
    mat[y][x] = color;
    while (!Q.empty()) {
        pii T = Q.front(); Q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = T.first + dy[i];
            int nx = T.second + dx[i];
            if (nx < c && nx >= 0 && ny < r && ny >= 0) {
                if (mat[ny][nx] == 0) {
                    mat[ny][nx] = color;
                    Q.push(pii(ny, nx));
                } 
                if (mat[ny][nx] == 1 && color == 1) {
                    ny += dy[i]; nx += dx[i];
                    if (nx < c && nx >= 0 && ny < r && ny >= 0 && mat[ny][nx] == 0) {
                        mat[ny][nx] = color;
                        Q.push(pii(ny, nx));
                    } 
                }
            } 
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    int n; 
    while (cin >> n, n > 0) {
        vector <int> x, y;
        for (int i = 0; i < n; i++) {
            int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
            x.push_back(x1); x.push_back(x2);
            y.push_back(y1); y.push_back(y2);
        }
        compress(x); compress(y);
        int Mx = *max_element(x.begin(), x.end());
        int My = *max_element(y.begin(), y.end());
        vector <vector <int>> mat(My + 2, vector <int> (Mx + 2, 0));
        for (int i = 0; i < n; i++) {
            swap(y[i*2], y[i*2+1]); swap(x[i*2], x[i*2+1]);
            for (int ky = y[i*2]; ky <= y[i*2+1]; ky++) 
                for (int kx = x[i*2]; kx <= x[i*2+1]; kx++)
                     mat[ky][kx] = 1;
        }
        
        int an = 0;
        bfs(My + 2, Mx + 2, mat, 0, 0, 2);
        for (int i = 0; i <= My + 1; i++) {
            for (int j = 0; j <= Mx + 1; j++) {
                if (mat[i][j] == 0) {
                    bfs(My + 2, Mx + 2, mat, i, j, 1);
                    an++;
                }
            }
        }
        cout << an << endl;
    }
	return 0;
}
