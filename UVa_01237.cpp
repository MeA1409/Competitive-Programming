#include <iostream>
#include <vector>
using namespace std;

struct Info{
    string name;
    int low, high;
};

typedef struct Info info; 

void foo(vector <info> &sol, int price) {
    int n = sol.size();
    string ans = "";
    for (int i = 0; i < n; i++) {
        if (sol[i].low <= price && sol[i].high >= price) {
            if (ans == "")
                ans = sol[i].name;
            else ans = "UNDETERMINED";
        }
    }
    if (ans == "") cout << "UNDETERMINED\n";
    else cout << ans << endl;
}

info new_info(string name, int lo, int hi) {
    info x;
    x.name = name;
    x.low = lo; x.high = hi;
    return x;
}

int main() {
    ios_base::sync_with_stdio(0);
    int t, n; cin >> t;
    while (t--) {
        cin >> n;
        vector <Info> sol(n);
        string name;
        int lo, hi;
        for (int i = 0; i < n; i++) {
            cin >> name >> lo >> hi;
            sol[i] = new_info(name, lo, hi);
        }
        int q; cin >> q;
        int price;
        while (q--) {
            cin >> price;
            foo(sol, price);
        }
        if  (t) cout << endl;
    }
	return 0;
}
