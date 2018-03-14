#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    vector <int> test(3601);
    string line;
    int t = 1;
    while (getline(cin, line)) {
        test.assign(3601, 1);
        stringstream ss;
        ss << line;
        int i, j;
        int num;
        while (ss >> num) {
            i = num - 5; j = num + 5;
            for (; i < 3601;) {
                while (j-- && i < 3601) 
                    test[i++] = 0;
                j = num + 5; i += num - 5;
            }
        }
        i = 0;
        for (; i < 3601; i++)
            if (test[i] == 0) break;
        for (; i < 3601; i++) {
            if (test[i]) {
                cout << "Set " << t++ 
                      << " synchs again at " 
                        << i/60 << " minute(s) and " 
                          << i%60 << " second(s) after all turning green.\n";
                break;
            }
        }
        if (i == 3601) cout << "Set " 
                              << t++ 
                                << " is unable to synch after one hour.\n";
        ss.str("");
    }
}
