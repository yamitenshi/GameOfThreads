//
// Created by nvgool on 2-6-15.
//

#include "Application.h"
#include "../Entity/Field.h"
#include "../Display/FieldDisplay.h"
#include "../Events/Event.h"
#include "../Events/EventManager.h"


Application::Application() : EventListener() {
    field = new Field(10, 10);
    fieldDisplay = new FieldDisplay(field);
    EventManager::getInstance().registerListener(this, "application");
    initThreads();
}

Application::~Application() {
    EventManager::getInstance().detachListener("application");
    delete managerThread;
    delete displayThread;
    delete eventProcessor;
}

void Application::initThreads() {
    managerThread = new std::thread(&Application::handleField, this);
    displayThread = new std::thread(&Application::displayField, this);
    eventProcessor = new std::thread(&EventManager::processEvents, &EventManager::getInstance());
}

int Application::run() {
    managerThread->join();
    displayThread->join();
    eventProcessor->join();
    return 0;
}

void Application::handleField() {
    while(execute) {
        fieldMutex.lock();
        field->update();
        fieldMutex.unlock();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void Application::displayField() {
    while(execute) {
        fieldMutex.lock();
        fieldDisplay->display();
        fieldMutex.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void Application::handleEvent(Event *event) {
    if (event->getType() == "quit") {
        execute = false;
    }
}
