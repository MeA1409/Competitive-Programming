#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n; cin >> n;
    
    while (n--) {
        long left[2] = {0, 1};
        long right[2] = {1, 0};
        long cur[2] = {1, 1};
        
        string query;
        cin >> query;
        for (int i = 0; i < query.size(); i++) {
            if (query[i] == 'R') {
                left[0] = cur[0];
                left[1] = cur[1];
            }
            else {
                right[0] = cur[0];
                right[1] = cur[1];
            }
            cur[0] = left[0] + right[0];
            cur[1] = left[1] + right[1];
        }
        cout << cur[0] << "/" << cur[1] << endl;
    }
    
	return 0;
}
