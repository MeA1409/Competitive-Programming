#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef vector <int> vi;

int main() {
    ios_base::sync_with_stdio(0);
    int t; cin >> t;
    for (int s = 1; s <= t; s++) {
        int n, m;
        cin >> n >> m;
        vi cut;
        vector <vi> mat(n+1, vi(n+1));
        for (int i = 0; i < m; i++) {
            int u, v; cin >> u >> v;
            mat[u][v] = mat[v][u] = 1;
        }
        map <int, int> A;
        for (int i = 1; i <= n; i++) {
            int a = 0, b = 0;
            for (int j = 1; j <= i - 1; j++)
                if (mat[i][j] == 1) {
                    if (A[j]) a++;
                    else b++;
                }
            if (a <= b) {
                cut.push_back(i);
                A[i] = 1;
            }
        }
        cout << "Case #" << s << ": ";
        cout << cut.size() << endl;
        for (int i = 0; i < cut.size(); i++) {
            if (i != 0) cout << " ";
            cout << cut[i];
        }
        cout << endl;
    }
	  return 0;
}
