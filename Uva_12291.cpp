#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ii;
typedef vector<string> vs;

int n, m;

void findPat(vs pat, vector <ii> &co) {
    int i, j; 
    i = j = 0;
    int ifPos, jfPos;
    int fnd = 0;
    
    for (; i < m; i++) {
        for (; j < m; j++) {
            if (pat[i][j] == '*') {
                fnd = 1;
                ifPos = i; jfPos = j;
                co.push_back(make_pair(0, 0));
                break;
            }
        }
        if (fnd) break;
        j = 0;
    }
    
    j++;
    
    int x, y;
    for (; i < m; i++) {
        for (; j < m; j++) {
            if (pat[i][j] == '*') {
                x = i - ifPos;
                y = j - jfPos;
                co.push_back(make_pair(x, y));
            }
        }
        j = 0;
    }
}

bool within_bounds(int x, int y) {
    return (x < n && y < n && x >= 0 && y >= 0);
}

bool sol(vs model, vs pat) {
    vector <ii> co;
    findPat(pat, co);
    
    if (co.size() == 0) {
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++)
                if (model[i][j] == '*')
                    return 0;
        return 1;
    }
    
    int x, y;
    int cnt = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (model[i][j] == '*') {
                for (int k = 0; k < co.size(); k++) {
                    x = i + co[k].first; 
                    y = j + co[k].second;
                    if (within_bounds(x, y) && model[x][y] == '*')
                        model[x][y] = '.';
                    else return 0;
                }
                cnt++;
                if (cnt > 2) return 0;
            }
        }
    }
    
    return (cnt == 2);
}

int main() {
    ios_base::sync_with_stdio(0);
    while (cin >> n >> m, n || m) {
        vs model(n), pat(m);
        
        for (int i = 0; i < n; i++)
            cin >> model[i];
        for (int i = 0; i < m; i++)
            cin >> pat[i];
        
        if(sol(model, pat)) cout << 1 << endl;
        else cout << 0 << endl;
    }
    
    return 0;
}    
