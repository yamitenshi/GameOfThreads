//
// Created by nvgool on 2-6-15.
//

#include "Event.h"

Event::Event(const std::string &type) : type(type) {}

std::string& Event::getType() {
    return type;
}
