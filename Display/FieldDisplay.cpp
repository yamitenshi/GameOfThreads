//
// Created by nvgool on 2-6-15.
//

#include <iostream>
#include "FieldDisplay.h"
#include "../Entity/Field.h"
#include "../Events/EventTypes/QuitEvent.h"

FieldDisplay::FieldDisplay(Field *field) : EventListener(), field(field), run(true) {}

void FieldDisplay::display() {
    while(run) {
        field->getMutex().lock();

        std::cout << "Displaying..." << std::endl;

        field->getMutex().unlock();
    }
}

void FieldDisplay::handleEvent(QuitEvent *event) {
    run = false;
}

void FieldDisplay::handleEvent(Event *event) {
    EventListener::handleEvent(event);
}
