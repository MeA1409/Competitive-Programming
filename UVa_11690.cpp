#include <iostream>
#include <vector>
using namespace std;

struct Group{
    int money;
    int friendRank;
    int bestFriend;
    Group() {
        friendRank = 1;
    }
};

typedef vector <struct Group> vGroup;

int bestFriend(vGroup &Pop, int a) {
    int &k = Pop[a].bestFriend;
    if (k != a) 
        k = bestFriend(Pop, k);
    return k;
}

void MakeEven(vGroup &Pop, int a, int b) {
    int pa = bestFriend(Pop, a);
    int pb = bestFriend(Pop, b);
    
    if (pa == pb) return;
    
    if (Pop[pa].friendRank < Pop[pb].friendRank) {
        Pop[pa].bestFriend = pb;
        Pop[pb].money += Pop[pa].money;
    }
    else {
        Pop[pb].bestFriend = pa;
        Pop[pa].money += Pop[pb].money;
        if (Pop[pa].friendRank == Pop[pb].friendRank) 
            Pop[pa].friendRank++;
    }
}

bool isPossible(vGroup &Pop) {
    int n = Pop.size();
    for (int i = 0; i < n; i++)
        if (Pop[bestFriend(Pop, i)].money != 0)
            return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vGroup Pop(n);
        
        for (int i = 0; i < n; i++) {
            int money;
            cin >> money;
            Pop[i].money = money;
            Pop[i].bestFriend = i;
        }
        
        int fA, fB;
        for (int i = 0; i < m; i++) {
            cin >> fA >> fB;
            MakeEven(Pop, fA, fB);
        }
        
        if (isPossible(Pop))
            cout << "POSSIBLE\n";
        else cout << "IMPOSSIBLE\n";
    }
}
