//
// Created by nvgool on 2-6-15.
//

#ifndef THREADINGTEST_APPLICATION_H
#define THREADINGTEST_APPLICATION_H


#include <thread>
#include <mutex>
#include "../Events/EventListener.h"

class Field;
class FieldDisplay;

class Application : public EventListener {
public:
    Application();
    ~Application();

    int run();
    void handleField();
    void displayField();


    virtual void handleEvent(Event *event) override;

private:
    void initThreads();

    std::thread *managerThread;
    std::thread *displayThread;
    std::thread *eventProcessor;

    Field *field;
    FieldDisplay *fieldDisplay;
    std::mutex fieldMutex;

    bool execute = true;
};


#endif //THREADINGTEST_APPLICATION_H
