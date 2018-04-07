#include <iostream>
#include <list>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
	string line;
	while (getline(cin >> ws, line)) {
	    list <char> sol;
	    list <char>::iterator k = sol.begin();
	    int end = 1, li = line.size();
	    for (int i = 0; i < li; i++) {
	        if (line[i] == '[') {
	            k = sol.begin();
	            end = 0;
	        }
	        else if (line[i] == ']')
	            end = 1;
	        else {
	            if (end) sol.push_back(line[i]);
	            else 
	                sol.insert(k, line[i]);
	        }
	    }
	    k = sol.begin();
	    for (; k != sol.end(); k++)
	        cout << *k;
	    cout << endl;
	}
	return 0;
}
