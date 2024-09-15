//
// Created by Guillermo on 15/09/24.
//

#ifndef SHOPPINGLIST_APP_SUBJECT_H
#define SHOPPINGLIST_APP_SUBJECT_H
#include "Observer.h"


class Subject {
public:
    virtual void subscribe(Observer *o)=0;
    virtual void unsubscribe(Observer *o)=0;
    virtual void notify()=0;
    virtual ~Subject() {} ;


};


#endif //SHOPPINGLIST_APP_SUBJECT_H
