#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    while (cin >> n, n > 0) {
        int cur;
        vector <int> sol(n, -1);
        bool stable = true;
        int num, diff;
        for (int i = 0; i < n; i++) {
            cin >> num >> diff;
            if (i + diff < 0 || i + diff >= n) { 
                stable = false; continue; }
            if (sol[i+diff] != -1) {
                stable = false; continue; }
            sol[i+diff] = num;
        }
        if (stable) {
            for (int i = 0; i < n - 1; i++)
                cout << sol[i] << " ";
            cout << sol[n-1];
        }   
        else cout << -1;
        cout << endl;
    }
}
