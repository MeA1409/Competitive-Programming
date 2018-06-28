#include <bits/stdc++.h>
using namespace std;

int mem[110][65001];
int ar[110]; int x;
int n;

int recur(int id, int rem, char op, string &ops) {
    if (id == n) {
        if (rem == x) {
            ops = op + ops;
            return 1;
        }
        return 0;
    }

    int &ret = mem[id][rem+32000];
    if (ret != -1)
        return ret;
    
    if (rem + ar[id] <= 32000) {
        if (recur(id + 1, rem + ar[id], '+', ops)) {
            ops = op + ops;
            return ret = 1;
        }
    }
    if (rem - ar[id] >= -32000) {
        if (recur(id + 1, rem - ar[id], '-', ops)) {
            ops = op + ops;
            return ret = 1;
        }
    }
    if (rem*ar[id] >= -32000 && rem*ar[id] <= 32000) {
        if (recur(id + 1, rem*ar[id], '*', ops)) {
            ops = op + ops;
            return ret = 1;
        }
    }
    if (rem%ar[id] == 0) {
        if (recur(id + 1, rem/ar[id], '/', ops)) {
            ops = op + ops;
            return ret = 1;
        }
    }
    return ret = 0;
}

int main() {
    int t; cin >> t;
    while (t--) {
        memset(mem, -1, sizeof(mem));
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> ar[i];
        string ops = ""; cin >> x;
        recur(1, ar[0], '+', ops);
        if (ops.size() == 0) {
            cout << "NO EXPRESSION\n";
            continue;
        }
        cout << ar[0];
        for (int i = 1; i < ops.size(); i++)
            cout << ops[i] << ar[i];
        cout << "=" << x << endl;
    }
}
