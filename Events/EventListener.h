//
// Created by nvgool on 5-6-15.
//

#ifndef THREADINGTEST_EVENTLISTENER_H
#define THREADINGTEST_EVENTLISTENER_H

class Event;

class EventListener {
public:
    virtual void handleEvent(Event *event);
};


#endif //THREADINGTEST_EVENTLISTENER_H
