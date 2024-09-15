//
// Created by Guillermo on 14/09/24.
//

#ifndef SHOPPINGLIST_APP_SHOPPINGLIST_H
#define SHOPPINGLIST_APP_SHOPPINGLIST_H
#include "Product.h"
#include <list>
#include "Subject.h"
#include "Observer.h"

class ShoppingList: public Subject{
private:
    unsigned int qty;
    std::list<Product*> list;
    std::list<Observer*>observers;
public:
    ShoppingList():qty(0){}

    void AddProduct(std::string &name,std::string &category,unsigned int Product_qty);

    void RemoveProduct(std::string &name);

    void PrintList();

    void subscribe(Observer*o)override;

    void unsubscribe(Observer*o)override;

    void notify()override;

    unsigned int getQty() const;

    ~ShoppingList()=default;



};


#endif //SHOPPINGLIST_APP_SHOPPINGLIST_H
