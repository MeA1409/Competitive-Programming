#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int n, q;

void swap(int &a, int &b) {
    int temp = a; 
    temp = a, a = b, b = temp;
}

vector <string> transpose(vector <string> mat) {
    vector <string> res(n, "");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            res[i] += mat[j][i];
    return res;
}

void col_int(vector <string> &mat, int x, int y) {
    for (int i = 0; i < n; i++)
        swap(mat[i][x], mat[i][y]);
}

void row_int(vector <string> &mat, int x, int y) {
    for (int i = 0; i < n; i++)
        swap(mat[x][i], mat[y][i]);
}

void inc(vector <string> &mat) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int k = mat[i][j] - '0'; k = (k+1)%10;
            mat[i][j] = ('0' + k);
        }
    }
}

void dec(vector <string> &mat) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int k = mat[i][j] - '0'; k = (k+9)%10;
            mat[i][j] = ('0' + k);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    int t, s = 0; cin >> t;
    string line;
    while (s++ < t) {
        cout << "Case #" << s << endl;
        
        cin >> n;
        vector <string> mat(n);
        for (int i = 0; i < n; i++)
            cin >> mat[i];
        cin >> q;
        while (q--) {
            getline(cin >> ws, line);
            stringstream ss(line);
            
            string word;
            ss >> word;
            
            if (word[0] == 't') mat = transpose(mat);
            else if (word[0] == 'i') inc(mat);
            else if (word[0] == 'd') dec(mat);
            else if (word[0] == 'c') {
                int x, y;
                ss >> x >> y;
                col_int(mat, x-1, y-1);
            }
            else if (word[0] == 'r') {
                int x, y; 
                ss >> x >> y;
                row_int(mat, x-1, y-1);
            }
        }
        for (int i = 0; i < n; i++) 
                cout << mat[i] << endl;
        cout << endl;
    }
}
