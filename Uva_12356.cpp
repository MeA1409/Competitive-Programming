#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n, k; 
    while (cin >> n >> k, n || k) {
        int left[n+1], right[n+1];
        int sol[n+1] = {0};
        int l, r;
        for (int i = 0; i < k; i++) {
            cin >> l >> r;
            sol[l] = sol[r] = 1;
            int L = l-1, R = r+1;
            right[l] = R;
            while (right[l] <= n && sol[right[l]])
                right[l] = right[right[l]];
            left[r] = L;
            while (left[r] > 0 && sol[left[r]]) 
                left[r] = left[left[r]];
            if (left[r] == 0) cout << "*";
            else cout << left[r];
            cout << " ";
            if (right[l] == n+1) cout << "*";
            else cout << right[l];
            cout << endl;
        }
        cout << "-\n";
    }
}
