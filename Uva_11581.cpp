#include <iostream>

using namespace std;

#define sz 3

string sol[sz];
int dx[] = {1, 0, -1, 0}, 
    dy[] = {0, 1, 0, -1};

void reform() {
    string util[sz];
    for (int i = 0; i < 3; i++) {
        util[i] = "";
        for (int j = 0; j < 3; j++) 
            util[i] += sol[i][j];
    }
    
    int row, col, ones;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            ones = 0;
            for (int k = 0; k < 4; k++) {
                row = i + dx[k], col = j + dy[k];
                if (row >= 0 && row < 3 && col >= 0 && col < 3 
                            && util[row][col] == '1')
                    ones++;
            }  
            sol[i][j] = (ones&1? '1':'0');
        }
    } 
}

bool zeroed() {
    for (int i = 0; i < 3; i++) 
        for (int j = 0; j < 3; j++)
            if (sol[i][j] == '1') return false;
    return true;
}

int f(int num) {
    if (zeroed() || num == (int)2e9) return -1;
    reform();
    return 1 + f(num+1);
}

int main() {
    ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        for (int i = 0; i < 3; i++) 
            cin >> sol[i];
        int res = f(0);
        cout << res << endl;
    }
}
