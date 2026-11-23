#include "product.h"
#include <iostream>
#include <fstream>

Node* head = NULL;

Node* searchProduct(int searchID) {
    Node* temp = head;

    while (temp != NULL) {
        if (temp->data.id == searchID) {
            return temp;
        }

        temp = temp->next;
    }

    return NULL;
}

void searchProductMenu() {
    int id;

    cout << "\nEnter Product ID to search: ";
    cin >> id;

    Node* result = searchProduct(id);

    if (result == NULL) {
        cout << "\nProduct not found!\n";
    } else {
        cout << "\nProduct Found!\n";
        cout << "Name: " << result->data.name << endl;
        cout << "Category: " << result->data.category << endl;
        cout << "Price: " << result->data.price << endl;
        cout << "Quantity: " << result->data.quantity << endl;
    }
}

void searchProductByName() {
    string searchName;
    bool found = false;

    cout << "\nEnter Product Name to search: ";
    cin >> searchName;

    Node* temp = head;

    while (temp != NULL) {

        if (temp->data.name == searchName) {

            cout << "\nProduct Found!\n";
            cout << "ID: " << temp->data.id << endl;
            cout << "Name: " << temp->data.name << endl;
            cout << "Category: " << temp->data.category << endl;
            cout << "Price: " << temp->data.price << endl;
            cout << "Quantity: " << temp->data.quantity << endl;

            found = true;
        }

        temp = temp->next;
    }

    if (!found) {
        cout << "\nProduct not found!\n";
    }
}

void searchProductByCategory() {

    string searchCategory;
    bool found = false;

    cout << "\nEnter Category to search: ";
    cin >> searchCategory;

    Node* temp = head;

    while (temp != NULL) {

        if (temp->data.category == searchCategory) {

            cout << "\nProduct Found!\n";
            cout << "ID: " << temp->data.id << endl;
            cout << "Name: " << temp->data.name << endl;
            cout << "Category: " << temp->data.category << endl;
            cout << "Price: " << temp->data.price << endl;
            cout << "Quantity: " << temp->data.quantity << endl;

            found = true;
        }

        temp = temp->next;
    }

    if (!found) {
        cout << "\nNo product found in this category!\n";
    }
}

void searchProductByPrice() {

    double searchPrice;
    bool found = false;

    cout << "\nEnter Product Price to search: ";
    cin >> searchPrice;

    Node* temp = head;

    while (temp != NULL) {

        if (temp->data.price == searchPrice) {

            cout << "\nProduct Found!\n";
            cout << "ID: " << temp->data.id << endl;
            cout << "Name: " << temp->data.name << endl;
            cout << "Category: " << temp->data.category << endl;
            cout << "Price: " << temp->data.price << endl;
            cout << "Quantity: " << temp->data.quantity << endl;

            found = true;
        }

        temp = temp->next;
    }

    if (!found) {
        cout << "\nNo product found at this price!\n";
    }
}

void saveProducts() {

    ofstream file("products.txt");

    Node* temp = head;

    while (temp != NULL) {

        file << temp->data.id << " "
             << temp->data.name << " "
             << temp->data.category << " "
             << temp->data.price << " "
             << temp->data.quantity << endl;

        temp = temp->next;
    }

    file.close();

    cout << "\nProducts saved successfully!\n";
}

void loadProducts() {

    ifstream file("products.txt");

    if (!file) {
        return;
    }

    while (true) {

        Node* newNode = new Node;

        if (!(file >> newNode->data.id
                   >> newNode->data.name
                   >> newNode->data.category
                   >> newNode->data.price
                   >> newNode->data.quantity)) {

            delete newNode;
            break;
        }

        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        }
        else {
            Node* temp = head;

            while (temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }

    file.close();

    cout << "\nProducts loaded successfully!\n";
}

// Insert product at the end
void addProduct()
{
    Node* newNode = new Node;

    cout << "\nEnter Product ID: ";
    cin >> newNode->data.id;

    if (searchProduct(newNode->data.id) != NULL) {
        cout << "\nError! Product ID already exists.\n";
        delete newNode;
        return;
    }

    cout << "Enter Product Name: ";
    cin >> newNode->data.name;

    cout << "Enter Category: ";
    cin >> newNode->data.category;

    cout << "Enter Price: ";
    cin >> newNode->data.price;

    if (newNode->data.price <= 0) {
        cout << "\nInvalid price!"
             << "\nPrice must be greater than 0.\n";
        delete newNode;
        return;
    }

    cout << "Enter Quantity: ";
    cin >> newNode->data.quantity;

    if (newNode->data.quantity <= 0) {
        cout << "\nInvalid quantity!"
             << "\nQuantity must be greater than 0.\n";
        delete newNode;
        return;
    }

    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
    }

    cout << "\nProduct added successfully!\n";
    saveProducts();
}

void displayProducts()
{
    if (head == NULL)
    {
        cout << "\nNo products available!\n";
        return;
    }

    Node* temp = head;

    cout << "\n----- PRODUCT LIST -----\n";

    while (temp != NULL)
    {
        cout << "\nID: " << temp->data.id;
        cout << "\nName: " << temp->data.name;
        cout << "\nCategory: " << temp->data.category;
        cout << "\nPrice: " << temp->data.price;
        cout << "\nQuantity: " << temp->data.quantity;
        cout << "\n------------------------\n";

        temp = temp->next;
    }
}

void updateProduct() {
    int id;

    cout << "\nEnter Product ID to update: ";
    cin >> id;

    Node* result = searchProduct(id);

    if (result == NULL) {
        cout << "\nProduct not found!\n";
        return;
    }

    cout << "\nEnter New Name: ";
    cin >> result->data.name;

    cout << "Enter New Category: ";
    cin >> result->data.category;

    cout << "Enter New Price: ";
    cin >> result->data.price;

    cout << "Enter New Quantity: ";
    cin >> result->data.quantity;

    cout << "\nProduct updated successfully!\n";

    saveProducts();
}

void deleteProduct() {
    int id;

    cout << "\nEnter Product ID to delete: ";
    cin >> id;

    Node* temp = head;
    Node* previous = NULL;

    while (temp != NULL && temp->data.id != id) {
        previous = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "\nProduct not found!\n";
        return;
    }

    if (previous == NULL) {
        head = temp->next;
    }
    else {
        previous->next = temp->next;
    }

    delete temp;

    cout << "\nProduct deleted successfully!\n";

    saveProducts();
}

void sortByPrice() {
    if (head == NULL || head->next == NULL) {
        cout << "\nNot enough products to sort!\n";
        return;
    }

    for (Node* i = head; i->next != NULL; i = i->next) {
        for (Node* j = head; j->next != NULL; j = j->next) {

            if (j->data.price > j->next->data.price) {
                Product temp = j->data;
                j->data = j->next->data;
                j->next->data = temp;
            }
        }
    }

    cout << "\nProducts sorted by price successfully!\n";

    displayProducts();
}

void sortByID() {
    if (head == NULL || head->next == NULL) {
        cout << "\nNot enough products to sort!\n";
        return;
    }

    for (Node* i = head; i->next != NULL; i = i->next) {
        for (Node* j = head; j->next != NULL; j = j->next) {

            if (j->data.id > j->next->data.id) {
                Product temp = j->data;
                j->data = j->next->data;
                j->next->data = temp;
            }
        }
    }

    cout << "\nProducts sorted by ID successfully!\n";

    displayProducts();
}

void sortByName() {

    if (head == NULL || head->next == NULL) {
        cout << "\nNot enough products to sort!\n";
        return;
    }

    for (Node* i = head; i->next != NULL; i = i->next) {

        for (Node* j = head; j->next != NULL; j = j->next) {

            if (j->data.name > j->next->data.name) {

                Product temp = j->data;
                j->data = j->next->data;
                j->next->data = temp;
            }
        }
    }

    cout << "\nProducts sorted by name successfully!\n";

    displayProducts();
}

void sortByCategory() {

    if (head == NULL || head->next == NULL) {
        cout << "\nNot enough products to sort!\n";
        return;
    }

    for (Node* i = head; i->next != NULL; i = i->next) {

        for (Node* j = head; j->next != NULL; j = j->next) {

            if (j->data.category > j->next->data.category) {

                Product temp = j->data;
                j->data = j->next->data;
                j->next->data = temp;
            }
        }
    }

    cout << "\nProducts sorted by category successfully!\n";

    displayProducts();
}
