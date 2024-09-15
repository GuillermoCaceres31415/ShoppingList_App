//
// Created by Guillermo on 15/09/24.
//

#ifndef SHOPPINGLIST_APP_DISPLAYSHOWQTY_H
#define SHOPPINGLIST_APP_DISPLAYSHOWQTY_H
#include "Observer.h"
#include "ShoppingList.h"


class DisplayShowQty :public Observer{
private:
    unsigned int qty;
    ShoppingList *subject;
public:
    explicit DisplayShowQty(ShoppingList*sub);

    virtual ~DisplayShowQty();

    std::string ShowQty();

    void attach()override;

    void detach()override;

    void update()override;

};


#endif //SHOPPINGLIST_APP_DISPLAYSHOWQTY_H
