#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    string cur, prev;
    int res;
    while (cin >> cur, cur[0] != 'E') {
        res = 1;
        while (cur != "1") {
            res++; prev = cur;
            cur = to_string(cur.size()); 
        }
        cout << res << endl;
    }
}
