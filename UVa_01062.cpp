#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    string line;
    int t = 1;
    while (cin >> line, line != "end" && line != "") {
        int foo[26] = {0};
        int res = 1;
        foo[line[0]-'A'] = 1;
        for (int i = 1; i < line.size(); i++) {
            int j = line[i]-'A';
            for (; j < 26; j++) 
                if (foo[j]) break;
                
            if (j == 26)
                res++;
            else foo[j] = 0;
            
            foo[line[i]-'A'] = 1;
        }
        cout << "Case " << t++ << ": " << res << endl;
    }
	return 0;
}
