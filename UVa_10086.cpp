#include <bits/stdc++.h>
using namespace std;

int mem[32][311];
int p[32][311];

int sol(vector <vector <int>> &mat, int Lrem, int indx) {
    if (Lrem == 0) {
        int an = 0;
        for (int j = indx; j < mat.size(); j++)
            an += mat[j][0], p[j][0] = 0;
        return mem[indx][Lrem] = an;
    }
    else if (indx == mat.size())
        return (int) 1e9;
        
    if (mem[indx][Lrem] != -1)
        return mem[indx][Lrem];
    
    int m = mat[indx].size(); int an = (int) 1e9;
    for (int i = 0; i < m && i <= Lrem; i++) {
        int tmp = sol(mat, Lrem - i, indx + 1) + mat[indx][i];
        if (an > tmp) {
            p[indx][Lrem] = i;
            an = tmp;
        }
    }
    return mem[indx][Lrem] = an;
}

void print(int n, int L) {
    int indx = 0, first = 1;
    while (indx < n) {
        if (first) first = 0;
        else cout << " ";
        cout << p[indx][L];
        L -= p[indx][L]; indx++;
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
	int L1, L2;
	while (cin >> L1 >> L2, L1 || L2) {
    	int n; cin >> n;
	    vector <vector <int>> mat(n);
	    for (int i = 0; i < n; i++) {
	        int m; cin >> m;
	        int s1[m+1] = {0}, 
	            s2[m+1] = {0};
	        for (int j = 1; j <= m; j++) 
	            cin >> s1[j];
	        for (int j = 1; j <= m; j++)
	            cin >> s2[j];
            for (int j = 0; j <= m; j++)
                mat[i].push_back(s1[j] + s2[m-j]);
	    }

    	memset(p, 0, sizeof(p));
    	memset(mem, -1, sizeof(mem));
    	cout << sol(mat, L1, 0) << endl;
	    print(n, L1);
	    cout << endl;
	}
	return 0;
}
