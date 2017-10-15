#include <iostream>
#include <string>
#include "grid.h"
#include "window.h"
using namespace std;

int main() {
    cin.exceptions(ios::eofbit|ios::failbit|ios::badbit);
    string cmd;
    Grid g;
    Xwindow w;
    int moves = 0;
    
    // You will need to make changes to this code.
    
    try {
        while (true) {
            cin >> cmd;
            if (cmd == "new") {
                int n;
                cin >> n;
                g.init(n, w);
            }
            else if (cmd == "init") {
                int r = 0;
                int c = 0;
                while(true) {
                    cin >> r >> c;
                    if (r == -1 && c == -1) {
                        break;
                    } else {
                        g.turnOn(r, c);
                    }
                }
                cout << g;
            }
            else if (cmd == "game") {
                cin >> moves;
                cout << moves << ((moves == 1) ? " move" : " moves") << " left" << endl;
                if (moves < 0) {
                    cout << ((g.isWon()) ? "Won" : "Lost") << endl;
                    return 0;
                } else if (moves == 0) {
                    cout << ((g.isWon()) ? "Won" : "Lost") << endl;
                    return 0;
                }
            }
            else if (cmd == "switch") {
                int r = 0, c = 0;
                cin >> r >> c;
                g.toggle(r, c);
                cout << g;
                if (g.isWon()) {
                    cout << "Won" << endl;
                    return 0;
                } else {
                    --moves;
                    cout << moves << ((moves == 1) ? " move" : " moves") << " left" << endl;
                    if (moves == 0) {
                        cout << "Lost" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    catch (ios::failure &) {
    }
}
