#include <iostream>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    while (cin >> n >> m, n > 0) {
        int num;
        map<int, int> taken;
        for (int i = 0; i < n; i++)
            cin >> num, taken[num] = 1;
        
        int c, r; 
        int doable = 1;
        while (m--) {
            cin >> c >> r;
            int cnt = 0;
            while (c--) {
                cin >> num;
                if (doable && taken[num] == 1) cnt++;
            }
            if (cnt < r) doable = 0;
        }
        if (doable) cout << "yes\n";
        else cout << "no\n";
    }
}
