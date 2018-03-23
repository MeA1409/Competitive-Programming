#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, string> is;

void goUpper(char &e) {
    int num = e - 'a';
    if (num >= 0 && num <= 26)
        e = 'A' + num;
}

void goLower(char &e) {
    int num = e - 'A';
    if (num >= 0 && num <= 26)
        e = 'a' + num;
}

bool cmp(pair <string, is> &a, pair <string, is> &b) {
    if (a.second.second != b.second.second)
        return (a.second.second < b.second.second);

    if (a.second.first != b.second.first)
        return (a.second.first < b.second.first);

    return (a.first < b.first);
}

int main() {
    ios_base::sync_with_stdio(0);
    string ig, line;
    map <string, int> pres;
    
    while (cin >> ig, ig != "::") {
        for (char &e:ig)
            goLower(e);
        pres[ig] = 1;
    }
    
    vector < pair <string, is> > sol;
    
    int order = 1; 
    while (getline(cin >> ws, line)) {
        for (char &e : line)
            goLower(e);
        line += ' ';
        string word = "", util;
        int x = 0, ls = line.size();
        
        for (int i = 0; i < ls; i++) {
            if (line[i] == ' ') {
                if (pres[word] != 1) {
                    util = line.substr(0, ls - 1);
                    for (int j = i-x; j < i; j++)
                        goUpper(util[j]);
                    for (char &e:word)
                        goUpper(e);
                    sol.push_back(make_pair(util, make_pair(order, word)));
                }
                word = "";
                x = 0;
            }
            else {
                word += line[i];
                x++;
            }
        }
        order++;
    }
    
    sort(sol.begin(), sol.end(), cmp);
    for (int i = 0; i < sol.size(); i++) {
        cout << sol[i].first << endl;
    }
        
    return 0;
}
