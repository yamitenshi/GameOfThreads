//
// Created by nvgool on 2-6-15.
//

#include "Field.h"
#include "Cell.h"
#include <iostream>

Field::Field(unsigned long w, unsigned long h) :
        width(w),
        height(h),
        cells(std::vector< std::vector<Cell> >(w, std::vector<Cell>(h, Cell(false)))) {}

Field::Field(Field &other) {
    Field(other.getWidth(), other.getHeight());

    cloneCells(other);
}

Field& Field::operator=(Field &other) {
    if (this != &other) {
        width = other.getWidth();
        height = other.getHeight();

        cloneCells(other);
    }

    return *this;
}

void Field::update() {
    guard.lock();
    Field copy = *this;

    for(unsigned long x = 0; x < cells.size(); x++) {
        for(unsigned long y = 0; y < cells[x].size(); y++) {
            unsigned short liveNeighbors = countLiveNeighbors(x, y);

            if (liveNeighbors < 2 || liveNeighbors > 4) {
                copy.killCell(0, 0);
            }

            if (liveNeighbors == 2) {
                copy.reviveCell(x, y);
            }
        }
    }

    cloneCells(copy);
    guard.unlock();
}

unsigned long Field::getWidth() {
    return width;
}

unsigned long Field::getHeight() {
    return height;
}

Cell& Field::getCell(unsigned long x, unsigned long y) {
    return cells.at(x).at(y);
}

bool Field::cellIsAlive(unsigned long x, unsigned long y) {
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
    for (unsigned long x = 0; x < cells.size(); x++) {
        for(unsigned long y = 0; y < cells[x].size(); y++) {
            cells[x][y].setLife(other.getCell(x, y).isAlive());
        }
    }
}

unsigned short Field::countLiveNeighbors(unsigned long x, unsigned long y) {
    unsigned short count = 0;
    for(unsigned long u = x-1; u <= x+1; u++) {
        for(unsigned long v = y-1; v <= y+1; v++) {
            if (u == x && v == y) {
                continue;
            }

            if (cellIsAlive(u, v)) {
                count++;
            }
        }
    }
    return count;
}

void Field::killCell(unsigned long x, unsigned long y) {
    try {
        cells.at(x).at(y).setLife(false);
    }
    catch(std::out_of_range) {
        return;
    }
}

void Field::reviveCell(unsigned long x, unsigned long y) {
    try {
        cells.at(x).at(y).setLife(true);
    }
    catch(std::out_of_range) {
        return;
    }
}

