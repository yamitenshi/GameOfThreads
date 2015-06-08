//
// Created by nvgool on 2-6-15.
//

#include "Cell.h"

Cell::Cell(bool alive = false) : alive(alive) {

}

bool Cell::isAlive() {
    return alive;
}

void Cell::setLife(bool alive) {
    this->alive = alive;
}
