//
// Created by Guillermo on 15/09/24.
//

#include "DisplayShowQty.h"

DisplayShowQty::DisplayShowQty(ShoppingList *sub):subject(sub),qty(sub->getQty()) {
    attach();
}
DisplayShowQty::~DisplayShowQty()  {
    detach();
}

void DisplayShowQty::attach() {
    subject->subscribe(this);
}

void DisplayShowQty::detach() {
    subject->unsubscribe(this);
}

void DisplayShowQty::update() {
    this->qty=subject->getQty();
    ShowQty();
}

std::string DisplayShowQty::ShowQty() {
    return std::to_string(qty);
}
