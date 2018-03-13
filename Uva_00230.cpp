#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

typedef pair<string, string> pss;
map<string, int> shelf;

int main() {
    vector <pss> comp;
    string whole;
    string name, author;
    while (getline(cin >> ws, whole), whole[0] != 'E') {
        int i = 1;
        name = author = "";
        for (; whole[i] != '\"' && i < whole.size(); i++) 
            name += whole[i];
        i+=5;
        for (; i < whole.size() - 1; i++)
            author += whole[i];
        comp.push_back(make_pair(author, name));
        shelf[name] = 1;
    }
    sort(comp.begin(), comp.end());
    
    int i;
    string action; 
    while (getline(cin >> ws, whole), whole[0] != 'E') {
        action = "";
        if (whole[0] == 'B') {
            i = 8;
            for (; i < whole.size() - 1; i++)
                action += whole[i];
            shelf[action] = 0;
        }
        else if (whole[0] == 'R') {
            i = 8;
            for (; i < whole.size() - 1; i++)
                action += whole[i];
            shelf[action] = 2;
        }
        else {
            i = 0;
            int prev = -1;
            for (; i < comp.size(); i++) {
                action = comp[i].second;
                if (shelf[action] != 0) {
                    if (shelf[action] == 2) {
                        cout << "Put \"" << action << "\" first\n";
                        shelf[action] = 1; }
                    prev = i;
                    break;
                }
            }
            i++;
            for (; i < comp.size(); i++) {
                action = comp[i].second;
                if (shelf[action] != 0) {
                    if (shelf[action] == 2) {
                        cout << "Put \"" << action << "\" after \"" << comp[prev].second << "\"\n";
                        shelf[action] = 1; }
                    prev = i;
                }
            }
            cout << "END\n";
        }
    }
}
