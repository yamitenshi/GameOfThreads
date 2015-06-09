//
// Created by nvgool on 2-6-15.
//

#ifndef THREADINGTEST_ENTITY_FIELD_H
#define THREADINGTEST_ENTITY_FIELD_H

#include <mutex>
#include <vector>

class Cell;

class Field {
public:
    Field(unsigned long w, unsigned long h);
    Field(Field &other);

    void update();

    unsigned long getWidth();
    unsigned long getHeight();

    std::mutex &getMutex();

    Cell& getCell(unsigned long x, unsigned long y);
    bool cellIsAlive(unsigned long x, unsigned long y);

    void killCell(unsigned long x, unsigned long y);
    void reviveCell(unsigned long x, unsigned long y);
private:
    void cloneCells(Field &other);
    unsigned short countLiveNeighbors(unsigned long x, unsigned long y);

    std::mutex guard;
    std::vector< std::vector<Cell> > cells;
    unsigned long width;
    unsigned long height;
};

#endif //THREADINGTEST_FIELD_H
