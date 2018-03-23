#include <iostream>
#include <map>
#include <sstream>
using namespace std;

struct Info {
    string info[8];
};

int main() {
    ios_base::sync_with_stdio(0);
    int t; cin >> t;
    string Department, line;
    map <string, Info> sol; 
    while (t--) {
        getline(cin >> ws, Department);
        while (getline(cin, line)) {
            if (line == "") break;
            stringstream ss(line);
            
            Info new_info;
            new_info.info[0] = Department;
            
            int idx = 1;
            while (getline(ss, new_info.info[idx++], ','));
            sol[new_info.info[3]] = new_info;
        }
    }

    for (map<string, Info>::iterator i = sol.begin(); i != sol.end(); i++) {
        Info X = (*i).second;
        cout << "----------------------------------------\n";
        cout << X.info[1] << " " << X.info[2] << " " << X.info[3] << endl;
        cout << X.info[4] << endl;
        cout << "Department: " << X.info[0] << endl;
        cout << "Home Phone: " << X.info[5] << endl;
        cout << "Work Phone: " << X.info[6] << endl;
        cout << "Campus Box: " << X.info[7] << endl;
    }
	return 0;
}
