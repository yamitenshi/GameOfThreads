//
// Created by nvgool on 2-6-15.
//

#include "Application.h"
#include "../Entity/Field.h"
#include "../Display/FieldDisplay.h"
#include <chrono>


Application::Application() {
    field = new Field(10, 10);
    fieldDisplay = new FieldDisplay(field);
    initThreads();
}

Application::~Application() {
    delete managerThread;
    delete displayThread;
}

void Application::initThreads() {
    managerThread = new std::thread(&Application::handleField, this);
    displayThread = new std::thread(&Application::displayField, this);
}

int Application::run() {
    managerThread->join();
    displayThread->join();
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
