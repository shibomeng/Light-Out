#include <iostream>
#include <utility>
#include "textdisplay.h"
#include "cell.h"
#include "info.h"
using namespace std;

TextDisplay::TextDisplay(int n): gridSize{n} {
    for (int i = 0; i < gridSize; ++i) {
        vector<char> row;
        for (int h = 0; h < gridSize; ++h) {
            row.emplace_back('_');
        }
        theDisplay.emplace_back(row);
    }
}

void TextDisplay::notify(Subject &whoNotified) {
    Info i = whoNotified.getInfo();
    if (i.state) theDisplay[i.row][i.col] = 'X';
    else theDisplay[i.row][i.col] = '_';
}

TextDisplay::~TextDisplay() {}

SubscriptionType TextDisplay::subType() const {
    return SubscriptionType::All;
}

ostream &operator<<(ostream &out, const TextDisplay &td) {
    for (int i = 0; i < td.gridSize; ++i) {
        for (int h = 0; h < td.gridSize; ++h) {
            out << td.theDisplay[i][h];
        }
        out << std::endl;
    }
    return out;
}

