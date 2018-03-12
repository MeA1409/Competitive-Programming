#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n, posD, posR;
    while (cin >> n, n > 0) {
        int min = 1999999999;
        posD = posR = -1;
        string use; cin >> use;
        for (int i = 0; i < use.size(); i++) {
            if (use[i] == 'Z') {min = 0; break;}
            else if (use[i] == 'R') {
                if (posD != -1 && i - posD < min) min = i - posD;
                posR = i;
                
            }
            else if (use[i] == 'D') {
                if (posR != -1 && i - posR < min) min = i - posR;
                posD = i;
            }
        }
        cout << min << endl;
    }
}
