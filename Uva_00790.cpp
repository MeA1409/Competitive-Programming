#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <iomanip>
#include <sstream>

using namespace std;

struct Team{
    int Rank;
    int Num, Probs, Time;
  
    bool operator<(struct Team &other) {
        if (Probs != other.Probs)
            return Probs > other.Probs;
        if (Time != other.Time)
            return Time < other.Time;
        return Num < other.Num;
    }
};

typedef struct Team team;

team nTeam(int num) {
    team X;
    X.Num = num;
    X.Probs = X.Time = 0;
    return X;
}

int timeElapsed(string &eTime) {
    stringstream ss(eTime);
    int hh, mm; char de;
    ss >> hh >> de >> mm;
    hh *= 60;
    return (hh+mm);
}

int main() {
  ios_base::sync_with_stdio(0);
	int n; cin >> n;
	string line;
  //ignoring two lines
	getline(cin, line);
	getline(cin, line);
	while (n--) {
	    string eTime;
	    char Prob, Stat;
	    int tnum;
	    vector <team> sol(25);
	    
	    for (int i = 0; i < 25; i++)
	        sol[i] = nTeam(i+1);
	    map <pair<int, int>, int> test;
	    vector <string> given;
	    
	    int max = -1;
	    while (getline(cin, line)) {
	        if (line == "") break;
	        given.push_back(line);
	    }
	    
	    sort(given.begin(), given.end());
	    
	    for (int e = 0; e < given.size(); e++) {
	        stringstream ss(given[e]);
	        ss >> tnum >> Prob >> eTime >> Stat;
	        
	        if (tnum > max) max = tnum;
	        pair<int, int> util = make_pair(tnum, Prob);
	        int i = tnum - 1;
	        
	        if (Stat == 'N') {
	            if (test[util] != -1)
	                test[util]++;
	            continue;
	        }

	        if (test[util] != -1) {
	            int eT = timeElapsed(eTime);
	            sol[i].Time += eT + test[util]*20;
	            sol[i].Probs++;
	            test[util] = -1;
	        }
	    }
	    
	    vector<team>::iterator end = sol.begin();
	    if (max < 0) continue;
	    	    
	    for (int i = 0; i < max; i++, end++);
      sort(sol.begin(), end);
	    
      cout << "RANK TEAM PRO/SOLVED TIME\n";
	    int rank = 1; 
	    sol[0].Rank = rank;
	    for (int i = 1; i < max; i++) {
	        ++rank;
	        if (sol[i].Probs == sol[i-1].Probs && sol[i].Time == sol[i-1].Time)
	            sol[i].Rank = sol[i-1].Rank;
	        else sol[i].Rank = rank;
	    }
	    
	    for (int i = 0; i < max; i++) {
	        cout << right << setw(4) 
              << sol[i].Rank << setw(5) 
              << sol[i].Num;
	        if (sol[i].Probs != 0) 
	            cout << setw(5) << sol[i].Probs 
	                << setw(11) << sol[i].Time;
	        cout << endl;
	    }
	    if (n) cout << endl;
	}
	return 0;
}
