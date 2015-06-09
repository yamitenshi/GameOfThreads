//
// Created by nvgool on 2-6-15.
//

#ifndef THREADINGTEST_FIELDDISPLAY_H
#define THREADINGTEST_FIELDDISPLAY_H

#include "../Events/EventListener.h"

class QuitEvent;

class Field;

class FieldDisplay : public EventListener {
public:
    FieldDisplay(Field *field);

    virtual void display();

    virtual void handleEvent(Event *event) override;

    virtual void handleEvent(QuitEvent *event);

private:
    Field *field;
    bool run;
};


#endif //THREADINGTEST_FIELDDISPLAY_H
