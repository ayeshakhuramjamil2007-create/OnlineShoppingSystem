#ifndef CART_H
#define CART_H
#include "product.h"

struct CartNode {
    int id;
    string name;
    double price;
    int quantity;
    CartNode* next;
};

extern CartNode* cartHead;

void addToCart();
void displayCart();
void removeFromCart();
#endif
