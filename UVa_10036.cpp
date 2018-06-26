#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        int ar, d[m] = {0};
    
        cin >> ar;
        d[(ar%m + m)%m] = 1;
        
        for (int i = 1; i < n; i++) {
            cin >> ar;
            int tp[m] = {0};
            for (int j = 0; j < m; j++) {
                if (d[j] == 1)
                    tp[((j + ar)%m + m)%m] = tp[((j - ar)%m + m)%m] = 1;
            }
            for (int j = 0; j < m; j++)
                d[j] = tp[j];
        }
    
        if (d[0] == 1)
            cout << "Divisible\n";
        else cout << "Not divisible\n";
    }
}
