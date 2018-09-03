#include <bits/stdc++.h>
using namespace std;

#define int long long
const double eps = 1e-9;

int sol(vector <vector <double> > &mat, vector <int> &an) {
    vector <double> tmp(7, 0.);
    for (int col = 0, row = 0; col < 7; col++) {
        int rel = row;
        for (int i = row + 1; i < 7; i++)
            if (mat[i][col] > mat[rel][col])
                rel = i;

        swap(mat[row], mat[rel]);

        for (int i = row + 1; i < 7; i++) {
            double cc = mat[i][col] / mat[row][col];
            for (int j = 7; j >= col; j--)
                mat[i][j] -= cc * mat[row][j];
        }
        row++;
    }
    for (int i = 6; i >= 0; i--) {
        double t = mat[i][7];
        for (int j = 6; j > i; j--)
            t -= mat[i][j]*tmp[j];
        tmp[i] = t / mat[i][i];
    }
    for (int i = 0; i < 7; i++) {
        an[i] = round(tmp[i]);
        if (an[i] < 0 || an[i] > 1000) return 0;
    }
    return 1;
}

signed main() {
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	int t; cin >> t;
	while (t--) {
	    vector <unsigned int> init(1500);
        vector < vector <double> > mat(7, vector <double>(8));
        for (int i = 1; i <= 1500; i++)
            cin >> init[i-1];
        for (int i = 1; i <= 7; i++) {
            mat[i-1][0] = 1;
            for (int j = 1; j < 7; j++)
                mat[i-1][j] = mat[i-1][j-1]*i;
            mat[i-1][7] = init[i-1];
        }

        vector <int> an(7);
        int y = sol(mat, an);
        /*
        for (int i = 1; i <= 7; i++) {
            for (int j = 0; j < 8; j++)
                cout << mat[i-1][j] << " ";
            cout << endl;
        }
        */
        for (unsigned int i = 1; i <= 1500; i++) {
            unsigned int t = 0;
            unsigned int x = 1;
            for (int j = 0; j < 7; j++) {
                t += x*an[j];
                x *= i;
            }
            if (t != init[i-1]) y = 0;
        }
        if (y) {
            for (int i = 0; i < 7; i++) {
                if (i != 0) cout << " ";
                cout << an[i];
            } cout << endl;
        }
        else cout << "This is a smart sequence!\n";
	}
	return 0;
}
