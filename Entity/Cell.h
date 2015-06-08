//
// Created by nvgool on 2-6-15.
//

#ifndef THREADINGTEST_CELL_H
#define THREADINGTEST_CELL_H

class Cell {
public:
    Cell(bool alive);

    bool isAlive();
    void setLife(bool alive);

private:
    bool alive;
};

#endif //THREADINGTEST_CELL_H
