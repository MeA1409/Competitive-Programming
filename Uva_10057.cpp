#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    int cnt[65537];
    while (cin >> n) {
        for (int i = 0; i < 65536; i++)
            cnt[i] = 0;
            
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            cnt[arr[i]]++;
        }
        
        sort(arr, arr+n);
        int med = n/2;
        int total, diff = 1;
        if (n&1)
            total = cnt[arr[med]]; 
        else {
            med--;
            total = cnt[arr[med]];
            if (arr[med] != arr[med+1]) {
                diff += arr[med+1] - arr[med];
                total += cnt[arr[med+1]];
            }
        }
        cout << arr[med] << " " << total << " " << diff << endl;
    }
}
