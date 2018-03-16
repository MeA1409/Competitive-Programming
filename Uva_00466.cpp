#include <iostream>
#include <vector>
using namespace std;

typedef vector <string> vs;

int n;
vs rotate_90(vs mat) {
    vs util(n, "");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) 
            util[i] += mat[n-j-1][i];
    }
    return util;
}

vs rotate_180(vs mat) {
    vs util(n, "");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            util[i] += mat[n-i-1][n-j-1];
    }
    return util;
}

vs rotate_270(vs mat) {
    vs util(n, "");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) 
            util[i] += mat[j][n-i-1];
    }
    return util;
}

vs reflect(vs mat) {
    vs util(n, "");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            util[i] += mat[n-i-1][j];
    }
    return util;
}

bool comp(vs matA, vs matB) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            if (matA[i][j] != matB[i][j]) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    string partA, partB;
    int t = 1;
	while (cin >> n) {
	    vs pat1(n), pat2(n);
	    for (int i = 0; i < n; i++) {
	        cin >> partA >> partB;
	        pat1[i] = partA;
	        pat2[i] = partB;
	    }
	    cout << "Pattern "<< t++ << " was ";
	    if (comp(pat2, pat1)) cout << "preserved.";
	    else {
	        if (comp(pat2, rotate_90(pat1))) cout << "rotated 90 degrees.";
	        else if (comp(pat2, rotate_180(pat1))) cout << "rotated 180 degrees.";
	        else if (comp(pat2, rotate_270(pat1))) cout << "rotated 270 degrees.";
	        else {
	            pat1 = reflect(pat1);
	            if (comp(pat2, pat1)) cout << "reflected vertically.";
	            else {
	                if (comp(pat2, rotate_90(pat1))) cout << "reflected vertically and rotated 90 degrees.";
	                else if (comp(pat2, rotate_180(pat1))) cout << "reflected vertically and rotated 180 degrees.";
	                else if (comp(pat2, rotate_270(pat1))) cout << "reflected vertically and rotated 270 degrees.";
	                else cout << "improperly transformed.";
	            }
	        }
	    }
	    cout << endl;
	}
	return 0;
}
