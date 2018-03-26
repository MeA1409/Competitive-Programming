#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>

using namespace std;

struct team{
    int points, wins, losses, draws;
    int goaldiff, goalscored, goalagainst;
    int games;
    string name, util_name;
    
    team() {
        points = wins = losses = draws =
        goalscored = goalagainst = 
        games = 0;
    }
    
    bool operator < (struct team &other) {
        if (points != other.points)
            return points > other.points;
        if (wins != other.wins) 
            return wins > other.wins;
        if (goaldiff != other.goaldiff)
            return goaldiff > other.goaldiff;
        if (goalscored != other.goalscored)
            return goalscored > other.goalscored;
        if (games != other.games)
            return games < other.games;
        if (util_name != other.util_name)
            return util_name < other.util_name;
        return name < other.name;
    }
};

typedef struct team Team;

Team new_team(string name) {
    Team X;
    X.name = name;
    return X;
}

void to_lower(string &mod) {
    int num;
    for (int i = 0; i < mod.size(); i++) {
        num = mod[i] - 'A';
        if (num >= 0 && num < 26) 
            mod[i] = 'a' + num;
    }
}

inline string getString(int &i, string &mod) {
    string res = "";
    for (; i < mod.size(); i++) {
        if (mod[i] == '#') break;
        res += mod[i];
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
	int t; cin >> t;
	string Tnm;
	
	string discard;
	getline(cin, discard);
	
	while (t--) {
	    getline(cin, Tnm);
	    int n; cin >> n;
	    getline(cin, discard);
	    vector <Team> tnm(n);
	    map<string, int> map_idx;
	    string team_name;
	    for (int i = 0; i < n; i++) {
	        getline(cin, team_name);
	        map_idx[team_name] = i;
	        tnm[i] = new_team(team_name);
	        to_lower(team_name);
	        tnm[i].util_name = team_name;
	    }
	    
	    int m; cin >> m;
	    getline(cin, discard);
	    string line;
	    string TeamA, game, TeamB;
	    int sA, sB;
	    char flush;
	    
	    for (int i = 0; i < m; i++) {
	        getline(cin, line);
            int j = 0;
            
            TeamA = getString(j, line); j++;
            game = getString(j, line); j++;
            TeamB = getString(j, line);
            
            stringstream ss(game);
            ss >> sA >> flush >> sB;
            
            int id1 = map_idx[TeamA], 
                id2 = map_idx[TeamB];
            tnm[id1].games++; 
            tnm[id1].goalscored += sA; tnm[id1].goalagainst += sB;
            tnm[id2].games++; 
            tnm[id2].goalscored += sB; tnm[id2].goalagainst += sA;
            if (sA < sB) {
                tnm[id2].points+=3;
                tnm[id2].wins++;
                tnm[id1].losses++;
            }
            else if (sA > sB) {
                tnm[id1].points+=3;
                tnm[id1].wins++;
                tnm[id2].losses++;
            }
            else {
                tnm[id1].points++; tnm[id2].points++;
                tnm[id1].draws++;  tnm[id2].draws++;
            }
	    }
	    for (int i = 0; i < n; i++)
	        tnm[i].goaldiff = tnm[i].goalscored - tnm[i].goalagainst;
	        
	    sort(tnm.begin(), tnm.end());
	    cout << Tnm << endl;
	    for (int i = 0; i < n; i++) {
	        cout << i+1 << ") ";
	        cout << tnm[i].name << " " << tnm[i].points << "p, "
	            << tnm[i].games << "g (" << tnm[i].wins << "-" 
	            << tnm[i].draws << "-" << tnm[i].losses << "), ";
	        cout << tnm[i].goaldiff << "gd (" << tnm[i].goalscored  << "-"
	                                   << tnm[i].goalagainst << ")\n";
	    }
	    if (t) cout << endl;   
	}
	return 0;
}
