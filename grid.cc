#include <iostream>
#include "grid.h"
using namespace std;

Grid::Grid() : gridSize{0}, td{nullptr}, gd{nullptr} {}

Grid::~Grid() {
    delete td;
    delete gd;
}

void Grid::clearGrid() {
    theGrid.clear();
    delete td;
}

bool Grid::isWon() const {
    for (int i = 0; i < gridSize; ++i) {
        for (int h = 0; h < gridSize; ++h) {
            if (theGrid[i][h].getState()) {
                return false;
            }
        }
    }
    return true;
}

void Grid::init(int n, Xwindow &w) {
    if (gridSize > 0) clearGrid();
    td = new TextDisplay{n};
    gd = new GraphicsDisplay{&w, 500/n};
    gridSize = n;
    int Size = 500 / gridSize;
    for (int i = 0; i < gridSize; ++i) {
        vector<Cell> row;
        for (int h = 0; h < gridSize; ++h) {
            Cell c;
            c.setCoords(i, h);
            row.emplace_back(c);
            w.fillRectangle(i * Size, h * Size, Size, Size);
        }
        theGrid.emplace_back(row);
    }
    for (int i = 0; i < gridSize; ++i) {
        for (int h = 0; h < gridSize; ++h) {
            int up = i - 1;
            int down = i + 1;
            int left = h - 1;
            int right = h + 1;
            theGrid[i][h].attach(td);
            if (up >= 0) theGrid[i][h].attach(&theGrid[up][h]);
            if (down < gridSize) theGrid[i][h].attach(&theGrid[down][h]);
            if (left >= 0) theGrid[i][h].attach(&theGrid[i][left]);
            if (right < gridSize) theGrid[i][h].attach(&theGrid[i][right]);
            theGrid[i][h].attach(gd);
        }
    }
}

void Grid::turnOn(int r, int c) {
    theGrid[r][c].setOn();
    theGrid[r][c].notifyObservers(td->subType());
}

void Grid::toggle(int r, int c) {
    theGrid[r][c].toggle();
    theGrid[r][c].notifyObservers(theGrid[r][c].subType());
}

ostream &operator<<(ostream &out, const Grid &g) {
    out << *(g.td);
    return out;
}

