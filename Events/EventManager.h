//
// Created by nvgool on 2-6-15.
//

#ifndef THREADINGTEST_EVENTMANAGER_H
#define THREADINGTEST_EVENTMANAGER_H

#include <queue>
#include <mutex>
#include <unordered_map>

class Event;
class EventListener;

class EventManager {
public:
    static EventManager &getInstance();
    void queueEvent(Event *event);
    void registerListener(EventListener *listener, std::string &name);
    void detachListener(std::string &name);

    void processEvents();

private:
    EventManager();
    ~EventManager();

    std::queue<Event*> eventQueue;
    std::unordered_map<std::string, EventListener*> listeners;
};


#endif //THREADINGTEST_EVENTMANAGER_H
