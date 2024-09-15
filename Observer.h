//
// Created by Guillermo on 15/09/24.
//

#ifndef SHOPPINGLIST_APP_OBSERVER_H
#define SHOPPINGLIST_APP_OBSERVER_H


class Observer {
public:
    virtual ~Observer() {} ;
    virtual void update()=0;
    virtual void attach()=0;
    virtual void detach()=0;


};


#endif //SHOPPINGLIST_APP_OBSERVER_H
