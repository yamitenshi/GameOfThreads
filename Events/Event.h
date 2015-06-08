//
// Created by nvgool on 2-6-15.
//

#ifndef THREADINGTEST_EVENT_H
#define THREADINGTEST_EVENT_H

#include <string>

class Event {
public:
    Event(const std::string &type);
    std::string& getType();

protected:
    std::string type;
};

#endif //THREADINGTEST_EVENT_H
