#include <iostream>
#include <iomanip>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    while (cin >> n) {
        cout << "------------------------------------------------------------\n";
        set <string> sol;
        string word;
        int wid = -1;
        for (int i = 0; i < n; i++) {
            cin >> word;
            sol.insert(word);
            if (wid < (int)word.size()) 
                wid = word.size();
        }
        wid += 2;
        if (wid > 60) wid = 60;
        
        int m = 60/wid;
        int r = n/m + (n%m != 0);
        
        string tab[n];
        int idx = 0;
        for (set<string>::iterator i = sol.begin(); i != sol.end(); i++)
            tab[idx++] = *i;
            
        for (int i = 0; i < r; i++) {
            for (int j = 0; i + j < n; j += r)
                cout << left << setw(wid) << tab[i+j];
            cout << endl;
        }
    }
}
