//
// Created by nvgool on 2-6-15.
//

#ifndef THREADINGTEST_FIELDDISPLAY_H
#define THREADINGTEST_FIELDDISPLAY_H

class Field;

class FieldDisplay {
public:
    FieldDisplay(Field *field);

    virtual void display();

private:
    Field *field;
};


#endif //THREADINGTEST_FIELDDISPLAY_H
