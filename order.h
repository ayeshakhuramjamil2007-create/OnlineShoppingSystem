#ifndef ORDER_H
#define ORDER_H
#include "cart.h"

struct Order {
    int orderID;
    double total;
    CartNode* items;
    Order* next;
};

extern Order* front;
extern Order* rear;
extern int nextOrderID;

void saveOrders();
void loadOrders();
void saveNextOrderID();
void loadNextOrderID();
void placeOrder();
void processOrder();
void displayOrders();
#endif
