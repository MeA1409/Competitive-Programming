#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

bool cmp(int &a, int &b) {
    return (abs(a) < abs(b));
}

int main() {
    ios_base::sync_with_stdio(0);
    int t; cin >> t;
    int n;
    while (t--) {
        cin >> n;
        if (n == 0) {
            cout << 0 << endl;
            continue;
        }
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
            
        sort(arr, arr+n, cmp);
        int res = 1, e = 1;
        if (arr[0] < 0) e = -1;
        
        for (int i = 1; i < n; ) {
            while (i < n && arr[i]*e > 0)
                i++;
                
            if (i < n && arr[i]*e < 0) res++;
            e*=-1; i++;
        }
        cout << res << endl;
    }
	return 0;
}c
