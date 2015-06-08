//
// Created by nvgool on 2-6-15.
//

#include "Field.h"
#include "Cell.h"
#include <iostream>

Field::Field(int w, int h) :
        width(w),
        height(h),
        cells(std::vector< std::vector<Cell> >(w, std::vector<Cell>(h, Cell(false)))) {}

Field::Field(Field &other) {
    Field(other.getWidth(), other.getHeight());

    cloneCells(other);
}

void Field::update() {
    guard.lock();
    Field copy(*this);

    for(int x = 0; x < cells.size(); x++) {
        for(int y = 0; y < cells[x].size(); y++) {
            int liveNeighbors = countLiveNeighbors(x, y);

            if (liveNeighbors < 2 || liveNeighbors > 4) {
                copy.killCell(x, y);
            }

            if (liveNeighbors == 2) {
                copy.reviveCell(x, y);
            }
        }
    }

    cloneCells(copy);
    guard.unlock();
}

int Field::getWidth() {
    return width;
}

int Field::getHeight() {
    return height;
}

Cell& Field::getCell(int x, int y) {
    return cells.at(x).at(y);
}

bool Field::cellIsAlive(int x, int y) {
    try {
        return cells.at(x).at(y).isAlive();
    }
    catch(std::out_of_range) {
        return false;
    }
}

std::mutex& Field::getMutex() {
    return guard;
}

void Field::cloneCells(Field &other) {
    for (int x = 0; x < cells.size(); x++) {
        for(int y = 0; y < cells[x].size(); y++) {
            cells[x][y].setLife(other.getCell(x, y).isAlive());
        }
    }
}

int Field::countLiveNeighbors(int x, int y) {
    int count = 0;
    for(int u = x-1; u <= x+1; u++) {
        for(int v = y-1; v <= y+1; v++) {
            if (cellIsAlive(u, v)) {
                count++;
            }
        }
    }
    return count;
}

void Field::killCell(int x, int y) {
    try {
        cells.at(x).at(y).setLife(false);
    }
    catch(std::out_of_range) {
        return;
    }
}

void Field::reviveCell(int x, int y) {
    try {
        cells.at(x).at(y).setLife(true);
    }
    catch(std::out_of_range) {
        return;
    }
}
