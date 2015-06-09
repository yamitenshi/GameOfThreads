//
// Created by nvgool on 2-6-15.
//

#include "EventManager.h"
#include "Event.h"
#include "EventListener.h"

EventManager &EventManager::getInstance() {
    static EventManager instance;
    return instance;
}

EventManager::~EventManager() {
    while(!eventQueue.empty()) {
        Event *event = eventQueue.front();
        eventQueue.pop();
        delete event;
    }

    Event *detachEvent = new Event("detach");
    for(auto listenerPair : listeners) {
        listenerPair.second->handleEvent(detachEvent);
    }
    listeners.clear();
}

EventManager::EventManager() {}

void EventManager::processEvents() {
    bool done = false;
    while(!done) {
        if (eventQueue.empty()) {
            continue;
        }
        Event *event = eventQueue.front();
        eventQueue.pop();
        if (event->getType() == "quit") {
            done = true;
        }

        for(auto i : listeners) {
            i.second->handleEvent(event);
        }

        delete event;
    }
}

void EventManager::queueEvent(Event *event) {
    eventQueue.push(event);
}

void EventManager::registerListener(EventListener *listener, std::string name) {
    std::pair<std::string, EventListener*> pair(name, listener);
    listeners.insert(pair);
}

void EventManager::detachListener(std::string name) {
    listeners.erase(name);
}

