#include <iostream>
#include <vector>

using namespace std;

void Input(vector <int> &f) {
    int n, x;
    cin >> n;
    while (n--) {
        cin >> x;
        f[x] = 1;
    }
}

int max(int a, int b) {
    return (a > b)? a : b;
}

void print(vector <int> f) {
    for (int i = 0; i < 10001; i++)
        if (f[i] == 1)
            cout << " " << i;
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    vector <int> f1(10001);
    vector <int> f2(10001);
    vector <int> f3(10001);
    int c1, c2, c3;
    int t, s = 0; cin >> t;
    while (s++ < t) {
        f1.assign(10001, 0);
        f2.assign(10001, 0);
        f3.assign(10001, 0);
        Input(f1);
        Input(f2);
        Input(f3);
        c1 = c2 = c3 = 0;
        for (int i = 0; i < 10001; i++) {
            if (f1[i]) {
                if (!f2[i] && !f3[i]) c1++;
                else f1[i] = f2[i] = f3[i] = 0;
            }
            if (f2[i]) {
                if (!f1[i] && !f3[i]) c2++;
                else f1[i] = f2[i] = f3[i] = 0;
            }
            if (f3[i]) {
                if (!f1[i] && !f2[i]) c3++;
                else f1[i] = f2[i] = f3[i] = 0;
            }
        }
        int Max = max(c1, max(c2, c3));
        cout << "Case #" << s << ":\n";
        if (Max == c1) {
            cout << 1 << " " << c1;
            print(f1);
            if (Max == c2) {
                cout << 2 << " " << c2;
                print(f2);
                if (Max == c3) {
                    cout << 3 << " " << c3;
                    print(f3);
                }
            }
            else if (Max == c3) {
                cout << 3 << " " << c3;
                print(f3);
            }
        }
        else if (Max == c2) {
            cout << 2 << " " << c2;
            print(f2);
            if (Max == c3) {
                cout << 3 << " " << c3;
                print(f3);
            }
        }
        else if (Max == c3) {
            cout << 3 << " " << c3;
            print(f3);
        }
    }
}
