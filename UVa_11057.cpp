#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int n;
	while (cin >> n) {
	    int arr[n];
	    for (int i = 0; i < n; i++)
	        cin >> arr[i];
	    sort(arr, arr + n);
	    
	    int money; cin >> money;
	    int MAX_DIFF = (1 << 30);
	    
	    set <int> avail;
	    int temp,
	        l, r;
	    for (int i = 0; i < n; i++) {
	        temp = money - arr[i];
	        if (avail.count(temp) && arr[i] - temp < MAX_DIFF) {
	            MAX_DIFF = arr[i] - temp;
	            l = temp; r = arr[i];
	        } 
	        avail.insert(arr[i]);
	    }
	    cout << "Peter should buy books whose prices are " 
	        << l << " and " << r << ".\n\n"; 
	}
	return 0;
}
