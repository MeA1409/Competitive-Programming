#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
	int n, ans;
	while (cin >> n, n > 0) {
	    vector <int> arr(n);
	    for (int i = 0; i < n; i++)
	        cin >> arr[i];
	    int next, prev;
	    ans = 0;
	    for (int i = 0; i < n; i++) {
	        next = (i + 1)%n;
	        prev = (i - 1 + n)%n;
	        if ((arr[i] > arr[next] && arr[i] > arr[prev]) || 
	            (arr[i] < arr[next] && arr[i] < arr[prev])) ans++;
	    }
	    cout << ans << endl;
	}
	return 0;
}
