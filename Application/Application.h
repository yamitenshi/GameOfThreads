//
// Created by nvgool on 2-6-15.
//

#ifndef THREADINGTEST_APPLICATION_H
#define THREADINGTEST_APPLICATION_H


#include <thread>
#include <mutex>

class Field;
class FieldDisplay;

class Application {
public:
    Application();
    ~Application();

    int run();
    void handleField();
    void displayField();
private:
    void initThreads();

    std::thread *managerThread;
    std::thread *displayThread;

    Field *field;
    FieldDisplay *fieldDisplay;
    std::mutex fieldMutex;

    bool execute = true;
};


#endif //THREADINGTEST_APPLICATION_H
