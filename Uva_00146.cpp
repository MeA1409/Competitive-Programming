#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
	string line;
	while (cin >> line, line != "#") {
	    if (next_permutation(line.begin(), line.end()))
	        cout << line << endl;
	    else cout << "No Successor\n";
	}
	return 0;
}
