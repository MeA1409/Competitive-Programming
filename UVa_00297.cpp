#include <iostream>
#include <queue>

using namespace std;

int max(int a, int b) {
    return a > b ? a : b;
}

struct Node {
    int val;
    int type;
    Node *children[4];
};

typedef struct Node node;

node *newNode() {
    node *x = new node;
    x->val = x->type = 0;
    for (int i = 0; i < 4; i++)
        x->children[i] = NULL;
    return x;
}

int traversal(node *&root, string a, int &i, int value) {
    if (i >= a.size()) return 0;
    
    root = newNode();
    if (a[i] == 'p') {
        int val = 0;
        for (int k = 0; k < 4; k++)
            val += traversal(root->children[k], a, ++i, value/4);
        root->val = val;
        return val;
    }
    
    root->type = 1;
    if (a[i] == 'f') {
        root->val = value;
        return value;
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        string A, B;
        cin >> A >> B;
        
        node *rootA, *rootB;
        int iA = 0, iB = 0;
        traversal(rootA, A, iA, 1024);
        traversal(rootB, B, iB, 1024);
        
        int answer = 0;
        queue <pair<node*, node*>> Solution;
        Solution.push(make_pair(rootA, rootB));
        while (!Solution.empty()) {
            node *x = Solution.front().first;
            node *y = Solution.front().second;
            Solution.pop();
            if (x->type == y->type && x->type == 0) {
                for (int i = 0; i < 4; i++)
                    Solution.push(make_pair(x->children[i], y->children[i]));
                continue;
            }
            answer += max(x->val, y->val);
        }
        cout << "There are " << answer << " black pixels.\n";
    }
	return 0;
}
