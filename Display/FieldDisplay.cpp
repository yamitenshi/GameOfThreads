//
// Created by nvgool on 2-6-15.
//

#include <iostream>
#include "FieldDisplay.h"
#include "../Entity/Field.h"
#include "../Events/Event.h"
#include "../Events/EventManager.h"

FieldDisplay::FieldDisplay(Field *field) : field(field) {}

void FieldDisplay::display() {
    EventManager::getInstance().queueEvent(new Event("quit"));
}
