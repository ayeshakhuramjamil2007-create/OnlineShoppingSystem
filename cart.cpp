#include "cart.h"
#include <iostream>

CartNode* cartHead = NULL;

void addToCart() {
    int id, qty;

    cout << "\nEnter Product ID: ";
    cin >> id;

    Node* product = searchProduct(id);

    if (product == NULL) {
        cout << "\nProduct not found!\n";
        return;
    }

    cout << "Enter quantity: ";
    cin >> qty;

    if (qty <= 0) {
        cout << "\nInvalid quantity!\n";
        return;
    }

    CartNode* temp = cartHead;

    while (temp != NULL) {
        if (temp->id == id) {
            if (temp->quantity + qty > product->data.quantity) {
                cout << "\nNot enough stock available!\n";
                return;
            }

            temp->quantity += qty;
            cout << "\nCart quantity updated successfully!\n";
            return;
        }

        temp = temp->next;
    }

    if (qty > product->data.quantity) {
        cout << "\nNot enough stock available!\n";
        return;
    }

    CartNode* newNode = new CartNode;

    newNode->id = product->data.id;
    newNode->name = product->data.name;
    newNode->price = product->data.price;
    newNode->quantity = qty;
    newNode->next = NULL;

    if (cartHead == NULL) {
        cartHead = newNode;
    } else {
        temp = cartHead;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    cout << "\nProduct added to cart successfully!\n";
}

void displayCart() {
    if (cartHead == NULL) {
        cout << "\nYour cart is empty!\n";
        return;
    }

    CartNode* temp = cartHead;
    double total = 0;

    cout << "\n========== SHOPPING CART ==========\n";

    while (temp != NULL) {
        double subtotal = temp->price * temp->quantity;

        cout << "\nProduct ID: " << temp->id;
        cout << "\nName: " << temp->name;
        cout << "\nPrice: " << temp->price;
        cout << "\nQuantity: " << temp->quantity;
        cout << "\nSubtotal: " << subtotal << endl;

        total += subtotal;
        temp = temp->next;
    }

    cout << "\n-----------------------------------";
    cout << "\nGrand Total: " << total << endl;
}

void removeFromCart() {
    if (cartHead == NULL) {
        cout << "\nYour cart is empty!\n";
        return;
    }

    int id;

    cout << "\nEnter Product ID to remove: ";
    cin >> id;

    CartNode* temp = cartHead;
    CartNode* previous = NULL;

    while (temp != NULL && temp->id != id) {
        previous = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "\nProduct not found in cart!\n";
        return;
    }

    if (previous == NULL) {
        cartHead = temp->next;
    } else {
        previous->next = temp->next;
    }

    delete temp;

    cout << "\nProduct removed from cart successfully!\n";
}
