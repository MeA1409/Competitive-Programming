#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int n; 
	while (cin >> n, n > 0) {
	    vector <int> arr(n);
	    for (int i = 0; i < n; i++)
	        cin >> arr[i];
	    sort(arr.begin(), arr.end());
	    
	    int Size = 0;
	    int utilSize = 1;
	    for (int i = 0; i < n - 1; i++) {
	        if (arr[i] == arr[i+1])
	            utilSize++;
	        else {
	            if (utilSize > Size)
	                Size = utilSize;
	            utilSize = 1;
	        }
	    }
	    if (utilSize > Size) Size = utilSize;
      
	    cout << Size << endl;
	    for (int i = 0; i < Size; i++) {
	        cout << arr[i];
	        for (int j = i + Size; j < n; j += Size)
	            cout << " " << arr[j];
	        cout << endl;
	    }
	    cout << endl;
	}
	return 0;
}
