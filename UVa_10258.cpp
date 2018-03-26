#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>

using namespace std;

struct team{
    int num, acs, atime;
    team() {
        acs = atime = 0;
    }
    bool operator < (struct team &other) {
        if (acs != other.acs)
            return acs > other.acs;
        if (atime != other.atime)
            return atime < other.atime;
        return num < other.num;
    }
};

typedef struct team Team;

Team new_team(int num) {
    Team X;
    X.num = num;
    return X;
}

int main() {
    ios_base::sync_with_stdio(0);
    int t; cin >> t;
    string discard;
    getline(cin, discard);
    getline(cin, discard);
    while (t--) {
        string line;
        map <int, int> pres;
        map <pair<int, int>, int> test;
        vector <Team> sol;
        int num, atime, prob;
        char stat;
        int i = 1;
        while (getline(cin, line)) {
            if (line == "") break;
            stringstream ss(line);
            ss >> num >> prob >> atime >> stat;
            if (!pres[num]) {
                pres[num] = i++;
                sol.push_back(new_team(num));
            }
            pair<int, int> util = make_pair(num, prob);
            if (stat == 'I') {
                if (test[util] != -1)
                    test[util]++;
                continue;
            }
            else if (stat == 'C' && test[util] != -1) {
                int j = pres[num] - 1;
                sol[j].atime += atime + test[util]*20;
                sol[j].acs++;
                test[util] = -1;
            }
        }
        sort(sol.begin(), sol.end());
        for (int i = 0; i < sol.size(); i++)
            cout << sol[i].num << " " << sol[i].acs << " " << sol[i].atime << endl;
        if (t) cout << endl;
    }
}
