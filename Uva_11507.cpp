#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int c;
    int y, z;
    while (cin >> c, c > 0) {
        string direction;
        y = z = 0;
        string di = "+x";
        
        for (int i = 0; i < c-1; i++) {
            cin >> direction;
            int sign = (direction[0] == '+');
            switch(direction[1]) {
                case 'z':
                    if (di[1] == 'x') {
                        di[1] = 'z';
                        if (!sign) 
                            di[0] = (di[0] == '+'? '-' : '+');
                    }
                    else if (di[1] == 'z') {
                        di[1] = 'x';
                        if (sign)
                            di[0] = (di[0] == '+'? '-' : '+');
                    }
                    break;
                case 'y':
                    if (di[1] == 'x') {
                        di[1] = 'y';
                        if (!sign) 
                            di[0] = (di[0] == '+'? '-' : '+');
                    }
                    else if (di[1] == 'y') {
                        di[1] = 'x';
                        if (sign)
                            di[0] = (di[0] == '+'? '-' : '+');
                    }
                    break;
                default: break;
                }
            }
        cout << di << endl;
    }
}
