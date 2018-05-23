#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int max(int a, int b) {
    return (a > b)? a : b;
}

int main() {
	ios_base::sync_with_stdio(0);
	int n, d, k;
	while (cin >> n >> d >> k, n || d || k) {
	    vector <int> mor(n), eve(n);
	    for (int i = 0; i < n; i++)
	        cin >> mor[i];
	    for (int i = 0; i < n; i++)
	        cin >> eve[i];
	    sort(mor.begin(), mor.end());
	    sort(eve.rbegin(), eve.rend());
	    int answer = 0;
	    for (int i = 0; i < n; i++) 
	        answer += max(0, mor[i] + eve[i] - d);
	    
	    cout << answer*k << endl;
	}
	return 0;
}
