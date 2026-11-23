#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
using namespace std;

struct Product {
    int id;
    string name;
    string category;
    double price;
    int quantity;
};

struct Node {
    Product data;
    Node* next;
};

extern Node* head;

Node* searchProduct(int searchID);
void searchProductMenu();
void searchProductByName();
void searchProductByCategory();
void searchProductByPrice();
void saveProducts();
void loadProducts();
void addProduct();
void displayProducts();
void updateProduct();
void deleteProduct();
void sortByPrice();
void sortByID();
void sortByName();
void sortByCategory();
#endif
