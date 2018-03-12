#include <iostream>

using namespace std;

int main() {
    int a, b;
    int ans, cur, prev;
    while (cin >> a, a > 0) {
        cin >> b >> prev;
        ans = a - prev;
        for (int i = 1; i < b; i++) {
            cin >> cur;
            if (cur < prev) ans += prev - cur;
            prev = cur;
        }
        cout << ans << endl;
    }
}
