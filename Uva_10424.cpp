#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int getSum(string x) {
    int s =  0;
    for (char e:x) {
        if (isupper(e)) s += e-'A' + 1;
        else if (islower(e)) s += e-'a' + 1;
    }
    return s;
}

int digitSum(int s) {
    if (s == 0) return 0;
    return s%9 == 0 ? 9 : s%9;
}

int main() {
    string a, b;
    int s1, s2;
    while (getline(cin >> ws, a)) {
        getline(cin >> ws, b);
        s1 = digitSum(getSum(a));
        s2 = digitSum(getSum(b));
        double ans;
        
        if (s1 < s2) ans = s1/(s2/1.00);
        else ans = s2/(s1/1.00);
        
        cout << fixed << setprecision(2) << ans*100.00 << " %" << endl;
    }
}
