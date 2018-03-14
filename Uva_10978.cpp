#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
	int t; 
	while (cin >> t, t > 0) {
	    vector <string> vec(t);
	    vector <int> test(t, 0);
	    string val, suit;
	    int j = 0, temp;
	    for (int i = 0; i < t; i++) {
	        cin >> suit >> val;
	        temp = val.size();
	        while (true) {
	            if (test[j] == 0) temp--;
	            if (temp == 0) break;
	            j = (j+1)%t;
	        }
	        vec[j] = suit;
	        test[j] = 1;
	    }
	    for (int i = 0; i < t; i++) {
	        if (i) cout << " ";
	        cout << vec[i];
	    }
	    cout << endl;
	}
	return 0;
}
