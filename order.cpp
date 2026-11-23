#include "order.h"
#include <iostream>
#include <fstream>

Order* front = NULL;
Order* rear = NULL;
int nextOrderID = 1;

void saveOrders() {

    ofstream file("orders.txt");

    Order* temp = front;

    while (temp != NULL) {

        int count = 0;
        CartNode* item = temp->items;

        // Count products in this order
        while (item != NULL) {
            count++;
            item = item->next;
        }

        // Save order information
        file << temp->orderID << " "
             << temp->total << " "
             << count << endl;

        // Save ordered products
        item = temp->items;

        while (item != NULL) {

            file << item->id << " "
                 << item->name << " "
                 << item->price << " "
                 << item->quantity << endl;

            item = item->next;
        }

        temp = temp->next;
    }

    file.close();

    cout << "\nOrders saved successfully!\n";
}

void loadOrders() {
    ifstream file("orders.txt");

    if (!file) {
        return;
    }

    while (true) {
        Order* newOrder = new Order;
        int count;

        if (!(file >> newOrder->orderID
                  >> newOrder->total
                  >> count)) {
            delete newOrder;
            break;
        }

        newOrder->items = NULL;
        newOrder->next = NULL;

        CartNode* itemTail = NULL;

        for (int i = 0; i < count; i++) {
            CartNode* newItem = new CartNode;

            file >> newItem->id
                 >> newItem->name
                 >> newItem->price
                 >> newItem->quantity;

            newItem->next = NULL;

            if (newOrder->items == NULL) {
                newOrder->items = newItem;
            } else {
                itemTail->next = newItem;
            }

            itemTail = newItem;
        }

        if (front == NULL) {
            front = rear = newOrder;
        } else {
            rear->next = newOrder;
            rear = newOrder;
        }

        if (newOrder->orderID >= nextOrderID) {
            nextOrderID = newOrder->orderID + 1;
        }
    }

    file.close();

    cout << "\nOrders loaded successfully!\n";
}

void saveNextOrderID() {
    ofstream file("order_counter.txt");

    file << nextOrderID;

    file.close();
}

void loadNextOrderID() {
    ifstream file("order_counter.txt");

    if (file) {
        file >> nextOrderID;
    }

    file.close();
}

void placeOrder() {

    if (cartHead == NULL) {
        cout << "\nYour cart is empty! Cannot place order.\n";
        return;
    }

    // STEP 1: Validate stock for ALL cart items
    CartNode* cartTemp = cartHead;

    while (cartTemp != NULL) {

        Node* product = searchProduct(cartTemp->id);

        if (product == NULL) {
            cout << "\nError! Product no longer exists.\n";
            return;
        }

        if (cartTemp->quantity <= 0 ||
            product->data.quantity < cartTemp->quantity) {

            cout << "\nError! Not enough stock for "
                 << cartTemp->name << endl;

            return;
        }

        cartTemp = cartTemp->next;
    }

    // STEP 2: Create new order
    Order* newOrder = new Order;

    newOrder->orderID = nextOrderID++;
    saveNextOrderID();
    newOrder->total = 0;
    newOrder->items = NULL;
    newOrder->next = NULL;

    cartTemp = cartHead;
    CartNode* itemTail = NULL;

    // STEP 3: Copy cart items and calculate total
    while (cartTemp != NULL) {

        CartNode* newItem = new CartNode;

        newItem->id = cartTemp->id;
        newItem->name = cartTemp->name;
        newItem->price = cartTemp->price;
        newItem->quantity = cartTemp->quantity;
        newItem->next = NULL;

        if (newOrder->items == NULL) {
            newOrder->items = newItem;
        } else {
            itemTail->next = newItem;
        }

        itemTail = newItem;

        newOrder->total +=
            cartTemp->price * cartTemp->quantity;

        // Deduct stock only after validation
        Node* product = searchProduct(cartTemp->id);

        product->data.quantity -= cartTemp->quantity;

        cartTemp = cartTemp->next;
    }

    // STEP 4: Add order to queue
    if (front == NULL) {
        front = rear = newOrder;
    } else {
        rear->next = newOrder;
        rear = newOrder;
    }

    // STEP 5: Display confirmation
    cout << "\nOrder placed successfully!";
    cout << "\nOrder ID: " << newOrder->orderID;
    cout << "\nTotal Amount: " << newOrder->total << endl;

    // STEP 6: Clear shopping cart
    while (cartHead != NULL) {
        CartNode* temp = cartHead;
        cartHead = cartHead->next;
        delete temp;
    }

    saveProducts();

    saveOrders();
}

void processOrder() {
    if (front == NULL) {
        cout << "\nNo pending orders to process!\n";
        return;
    }

    Order* temp = front;

    cout << "\n========== PROCESSING ORDER ==========\n";
    cout << "Order ID: " << temp->orderID;
    cout << "\nTotal Amount: " << temp->total << endl;

    CartNode* item = temp->items;

    cout << "\nOrdered Products:\n";

    while (item != NULL) {
        cout << item->name
             << " | Quantity: " << item->quantity
             << " | Price: " << item->price << endl;

        item = item->next;
    }

    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    item = temp->items;

    while (item != NULL) {
        CartNode* deleteItem = item;
        item = item->next;
        delete deleteItem;
    }

    delete temp;

    cout << "\nOrder processed successfully!\n";

    saveOrders();
}

void displayOrders() {
    if (front == NULL) {
        cout << "\nNo pending orders!\n";
        return;
    }

    Order* temp = front;

    cout << "\n========== PENDING ORDERS ==========\n";

    while (temp != NULL) {
        cout << "\nOrder ID: " << temp->orderID;
        cout << "\nTotal Amount: " << temp->total;

        CartNode* item = temp->items;

        cout << "\nOrdered Products:\n";

        while (item != NULL) {
            cout << item->name
                 << " | Quantity: " << item->quantity
                 << " | Price: " << item->price << endl;

            item = item->next;
        }

        cout << "-----------------------------------\n";

        temp = temp->next;
    }
}
