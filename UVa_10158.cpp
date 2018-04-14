#include <iostream>
using namespace std;

struct Game{
    int Parent;
    int Rank;
    Game() {
        Rank = 1;
    }
};

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Parent(Game set[], int a) {
    if (set[a].Parent != a)
        set[a].Parent = Parent(set, set[a].Parent);
    return set[a].Parent;
}

void Union(Game set[], int a, int b) {
    a = Parent(set, a);
    b = Parent(set, b);
    if (a != b) {
        if (b > a) swap(&a, &b);
        if (set[a].Rank < set[b].Rank)
            set[a].Parent = b;
        else {
            set[b].Parent = a;
            if (set[a].Rank == set[b].Rank)
                set[a].Rank++;
        }
    }
}

int areMutual(Game set[], int a, int b) {
    a = Parent(set, a);
    b = Parent(set, b);
    if (a == b)
        return 1;
    return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	int n; cin >> n;
	int d = n*2;
	
	Game set[d];
	for (int i = 0; i < d; i++)
	    set[i].Parent = i;
	
	int c, a, b;
	while (cin >> c >> a >> b, c || a || b) {
	    int Ea = a + n,
	        Eb = b + n;
	    switch(c) {
	        case 1: 
                if (areMutual(set, a, Eb) || areMutual(set, Ea, b)) {
                    cout << -1 << endl;
                    break;
	            }
	            Union(set, a, b);
	            Union(set, Ea, Eb);
	            break;
	        case 2:
	            if (areMutual(set, a, b) || areMutual(set, Ea, Eb)) {
	                cout << -1 << endl;
	                break;
	            }
	            Union(set, a, Eb);
	            Union(set, b, Ea);
	            break;
	        case 3:
	            if (areMutual(set, a, b) || areMutual(set, Ea, Eb))
	                cout << 1 << endl;
	            else cout << 0 << endl;
	            break;
	        case 4:
	            if (areMutual(set, a, Eb) || areMutual(set, Ea, b))
                    cout << 1 << endl;
              else cout << 0 << endl;
	            break;
	        default: break;
	    }
	}
	return 0;
}
