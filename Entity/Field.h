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
    Field(int w, int h);
    Field(Field &other);

    void update();

    int getWidth();
    int getHeight();

    std::mutex &getMutex();

    Cell& getCell(int x, int y);
    bool cellIsAlive(int x, int y);

    void killCell(int x, int y);
    void reviveCell(int x, int y);
private:
    void cloneCells(Field &other);
    int countLiveNeighbors(int x, int y);

    std::mutex guard;
    std::vector< std::vector<Cell> > cells;
    int width;
    int height;
};

#endif //THREADINGTEST_FIELD_H
