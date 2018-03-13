#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int s = 0, t; cin >> t;
    string line_1, line_2;
    int x; double y;
    while (s++ < t) {
        if (s > 1) cout << endl;
        stringstream ss;
        vector <int> ids;
      
        getline(cin >> ws, line_1);
        ss << line_1;
        while (ss >> x)
            ids.push_back(x-1);
        
        vector <string> num(ids.size());
        for (int i = 0; i < num.size(); i++)
            cin >> num[ids[i]];
        
        for (int i = 0; i < num.size(); i++)
            cout << num[i] << endl;
    }
	return 0;
}
