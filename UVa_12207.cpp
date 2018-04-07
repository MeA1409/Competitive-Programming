#include <iostream>
#include <deque>

using namespace std;

int min(int a, int b) {
    return (a < b)? a : b;
}

int main() {
    ios_base::sync_with_stdio(0);
    int p, q;
    int t = 0;
    while (cin >> p >> q, p && q) {
        cout << "Case " << ++t << ":\n";
        
        deque <int> sol;
        p = min(p, 1000);
        for (int i = 1; i <= p; i++)
            sol.push_back(i);
        char s;
        int num;
        
        while (q--) {
            cin >> s;
            if (s == 'N') {
                while (sol.front() < 0) 
                    sol.pop_front();
                num = sol.front();
                cout << num << endl;
                sol.push_back(num);
                sol.pop_front();
            }
            else if (s == 'E') {
                cin >> num;
                deque<int>::iterator i;
                for (i = sol.begin(); i != sol.end(); i++) {
                    if (*i == num) {
                        *i = -1;
                        break;
                    }
                }
                sol.push_front(num);
            }
        }
    }
}
